/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-11-02
    File        : floatpoint_conv.c
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


/* *** MAIN *** */
int main(void) {

    int indata[ARR_SIZE][4] = {
                               {195,47,0,0},    // -175
                               {67,7,0,0},      // -135
                               {62,32,0,0},     // 0.156250
                               {193,58,225,72}, // -11.68
                               {64,73,15,216},  // 3.141592
                               {70,210,240,0}   // 27000
                              };

    get_data(&indata);
    return 0;
}

/* Result:
*/


