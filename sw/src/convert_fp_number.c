/*
    Auther      : Heinz Samuelsson
    Date        : 2014-11-02
    File        : convert_fp_number.c
    Reference   : -
    Description : Convert IEEE 754 single-precision binary floating-point
                  format: binary32 to decimal value.

                  value = (-1)^sign * (1.b22 b21 b20 ... b0) * 2^(exp-127)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "convert_fp_number.h"

// global object holding information about the floating point number
static FloatPointNumber fpNumber;


// convert input decimal integer data to binary string
char* FloatPointConv_decimal2binary(int n) {

    int   d;
    int   count = 0;
    char* pointer;

    pointer = (char*)malloc(32);
    if (pointer == NULL)
        exit(EXIT_FAILURE);

    for (int c=7; c>=0; c--) {
        d = n >> c;
        if (d&1)
            *(pointer+count) = 1 + '0';
        else
            *(pointer+count) = 0 + '0';

        count++;
    }

    return pointer;
}


// convert array of data to a binary string
void FloatPointConv_convertArray(int* indata, int offset) {

    char* p_binvalue;
    char  bin_data[33];

    // 32 bits of data is created
    for (int i=0; i<4; i++) {
        p_binvalue = FloatPointConv_decimal2binary(indata[i+offset]);

        for (int j=0; j<8; j++) {
            bin_data[j+i*8] = p_binvalue[j];
        }
    }

    bin_data[32] = '\n';
    for (int k=0; k<32; k++) {
    }

    strcpy(fpNumber.value32bit,bin_data);
}


// get sign bit of data
void FloatPointConv_assignSign(char* bin_data) {

    int   sign;

    if (*(bin_data) == '1') {
        sign = -1;
    }
    else {
        sign = 1;
    }

    fpNumber.sign = sign;
}


// get exponent
void FloatPointConv_assignExponent(char* indata) {

    char exponent[8];

    for (int k=1; k<9; k++) {
        exponent[k-1] = *(indata+k);
    }

    strcpy(fpNumber.exponent,exponent);
}


// get mantissa
void FloatPointConv_assignMantissa(char* indata) {

    char mantissa[23];

    for (int k=9; k<32; k++) {
        mantissa[k-9] = *(indata+k);
    }

    strcpy(fpNumber.mantissa,mantissa);
}


// convert the exponent to decimal number
int FloatPointConv_bin2dec(char* indata) {

    char chardata[8];
    strncpy(chardata,indata,8);

    int decimal_data = (int)strtol(chardata,NULL,2);
    return (decimal_data - 127);
}


// convert the mantissa to decimal number
int FloatPointConv_bin2dec2(char* indata) {

    char chardata[24];
    strncpy(chardata,indata,24);
    chardata[23] = '\n';

    int decimal_data = (int)strtol(chardata,NULL,2);

   return decimal_data;
}


// calculate 1/2^n
float FloatPointConv_powerOf2n(int x) {

    int   p = 1;
    float q = 0.0;

    for (int i=0; i<x+1; i++) {
        p = p * 2;
        q = 1/(float)p;
    }
    return q;
}


// calculate 2^n
float FloatPointConv_powerOf2(int n) {

    float pow = 1.0;
    int   i   = 1;

    while (i <= abs(n)) {
        pow = (float)(pow * 2.0);
        i++;
    }

    if (n > 0)
        return pow;
    else
        return (float)(1.0/pow);
}


// calculate floating point value
float FloatPointConv_calcFloatingPointValue(FloatPointNumber fpNo, int dec_exponent) {

    float sum;

    for (int i=0; i<23; i++) {
        if (fpNo.mantissa[i] == '1') {
            sum += FloatPointConv_powerOf2n(i);
        }
    }

    float x = FloatPointConv_powerOf2(dec_exponent);
    float result = (float)fpNumber.sign*(IMPLICIT_BIT+sum) * x;

    return result;
}


// get data
float FloatPointConv_getFloatData(int* data, int offset) {

    FloatPointConv_convertArray(data,offset);
    FloatPointConv_assignSign(fpNumber.value32bit);
    FloatPointConv_assignExponent(fpNumber.value32bit);
    FloatPointConv_assignMantissa(fpNumber.value32bit);

    int dec_exponent = FloatPointConv_bin2dec(fpNumber.exponent);
    //int dec_mantissa = FloatPointConv_bin2dec2(fpNumber.mantissa);
    float rv = FloatPointConv_calcFloatingPointValue(fpNumber,dec_exponent);

    return rv;
}


/* Result:
     ------------------------------
     Result: -175.000000
     ------------------------------
     Result: 135.000000
     ------------------------------
     Result: 0.156250
     ------------------------------
     Result: -11.680000
     ------------------------------
     Result: 3.141592
     ------------------------------
     Result: 27000.000000
     ------------------------------
*/


