/*
    Auther      : Heinz Samuelsson
    Date        : 2014-11-02
    File        : x_plane_instr_ctrl.c
    Reference   : -
    Description : Handle communication between X-Plane 10 and servo controller.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "convert_fp_number.h"


/* *** MAIN *** */
int main(void) {


    // define data set
    int indata[ARR_SIZE][4] = {
                               {195,47,0,0},    // [0]  -175
                               {67,7,0,0},      // [1]  -135
                               {62,32,0,0},     // [2]  0.156250
                               {193,58,225,72}, // [3]  -11.68
                               {64,73,15,216},  // [4]  3.141592
                               {70,210,240,0}   // [5]  27000
                              };

    int data_set = 0; // select one the data set in indata[]

    printf("--------------------------\n");
    while (data_set < 6) {
        float rv = FloatPointConv_getFloatData(*indata,data_set*4);
        printf("Value of [%d] - %f\n",data_set,rv);
        printf("--------------------------\n");
        data_set++;
    }

    return 0;
}

