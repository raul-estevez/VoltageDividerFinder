/*
    Copyright 2021 Raúl Estévez Gómez

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in 
    the Software without restriction, including without limitation the rights to 
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
    the Software, and to permit persons to whom the Software is furnished to do so, 
    subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all 
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

    Written by Raúl Estévez Gómez <estevezgomezraul@gmail.com>
*/


#include <stdio.h>
#include <math.h>

#include "algorithm.h"
#include "cliargs.h"
#include "read_file.h"

float answer[4][5];
unsigned short answer_pos = 0;

void algorithm(void){
    for(unsigned int i = 0; i < resistors_count; i++){
        // Fix a R1
        //for(unsigned int j = i; j < resistors_count; j++){
        for(unsigned int j = 0; j < resistors_count; j++){
            // Iterate for all R2's
            float vout_parcial = vout_function(vin, resistors[i], resistors[j]);
            float current_error = (fabs(vout-vout_parcial)/vout) * 100;
            
            if(verbose_flag){
                printf("R1: %d\tR2: %d\tVout: %.6fV    \tError:%0.6f%\n", resistors[i],
                        resistors[j], vout_parcial, current_error);
            }

            // In the first iteration we always introduce the value in the array
            if(i == 0 && j == 0){
                answer[0][0] = (float)resistors[i];
                answer[1][0] = (float)resistors[j];
                answer[2][0] = current_error;
                answer[3][0] = vout_parcial;
            } else {
                // Save how full the array is
                unsigned int answer_max = answer_pos;

                // While the current error is less than the error in the las position
                while(current_error <= answer[2][answer_pos]){
                    // We look if we are in the las position
                    if(answer_pos < 4){
                        // The last element gets shifted one position
                        answer[0][answer_pos+1] = answer[0][answer_pos];
                        answer[1][answer_pos+1] = answer[1][answer_pos];
                        answer[2][answer_pos+1] = answer[2][answer_pos];
                        answer[3][answer_pos+1] = answer[3][answer_pos];

                        // The new element gets introduced in the array
                        answer[0][answer_pos] = (float)resistors[i];
                        answer[1][answer_pos] = (float)resistors[j];
                        answer[2][answer_pos] = current_error;
                        answer[3][answer_pos] = vout_parcial;

                        // If we added a new element in the array
                        if(answer_max == answer_pos){
                            answer_max++; 
                        }
                    // If we are not in the first element in the array we need to keep looking 
                        // if the new error is less than the rest
                        if(answer_pos != 0){
                            answer_pos--;
                        } else {
                            // If we are in the las position we have finished the iteration
                            break;
                        }
                    } else {
                        // If we are in the las position we cant shift the previous elemente we just
                        // overwrite it
                        answer[0][answer_pos] = (float)resistors[i];
                        answer[1][answer_pos] = (float)resistors[j];
                        answer[2][answer_pos] = current_error;
                        answer[3][answer_pos] = vout_parcial;
                       
                        answer_pos--;
                    }
                }
                answer_pos = answer_max;
            }
        }
    }
}


float vout_function(float vin, float R1, float R2){
    return vin * (R2/(R1+R2));
}

void print_answer(void){
    for(unsigned short i = 0; i < 5; i++){
        printf("R1: %.0f  \t", answer[0][i]);
        printf("R2: %.0f  \t", answer[1][i]);
        printf("Error: %.4f%  \t", answer[2][i]);
        printf("VOut: %.2fV\n", answer[3][i]);
    }
}
