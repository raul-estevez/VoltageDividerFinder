#include <stdio.h>
#include <math.h>

#include "algorithm.h"
#include "cliargs.h"
#include "read_file.h"

float answer[3][5];
unsigned short answer_pos = 0;

void algorithm(void){
    unsigned short resistors_size = sizeof(resistors);
    for(unsigned int i = 0; i < resistors_size; i++){
        // Fix a R1
        for(unsigned int j = i; j < resistors_size; j++){
            // Iterate for all R2's
            float vout_parcial = vout_function(vin, resistors[i], resistors[j]);
            float current_error = fabs(vout-vout_parcial);
            // VERBOSE
            //printf("%f\n", current_error);

            // In the first iteration we always introduce the value in the array
            if(i == 0 && j == 0){
                answer[0][0] = (float)resistors[i];
                answer[1][0] = (float)resistors[j];
                answer[2][0] = current_error;
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

                        // The new element gets introduced in the array
                        answer[0][answer_pos] = (float)resistors[i];
                        answer[1][answer_pos] = (float)resistors[j];
                        answer[2][answer_pos] = current_error;

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
        for(unsigned short j = 0; j < 2; j++){
            printf("%.0f\t", answer[j][i]);
        }
        printf("%.4f\n", answer[2][i]);
    }
}
