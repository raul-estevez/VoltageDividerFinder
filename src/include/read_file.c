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
#include <string.h>
#include <stdlib.h>

#include "read_file.h"

unsigned char EOF_flag = 0;

unsigned int *resistors = NULL;
unsigned static short resistors_sz = 0;
unsigned static short resistors_count = 0;

long read_resistance(FILE *fp){

    char *number = NULL;
    unsigned char number_sz = 0;
    unsigned char numberount = 0;

    char c;
    while(((c = fgetc(fp)) != ',') && (c != EOF)){
        if(numberount >= number_sz){
            // More space
            number_sz += 4;
            number = realloc(number, sizeof(char) * number_sz);
        }
        number[numberount] = c;
        numberount++;
    }
    // At this point we have a full number in character form 
    // so we need to convert from string to char
    if (c == EOF) EOF_flag = 1;
    return strtol(number, (char **)NULL, 10);
    
}

void write_to_resistors(long number){
    // Write the fetched resistors to the array
    if(resistors_count >= resistors_sz){
        resistors_sz += 4;
        resistors = realloc(resistors, sizeof(unsigned int) * resistors_sz);
    }
    resistors[resistors_count] = number;
    resistors_count++;
}

void read_file(FILE* file){
    while(!EOF_flag){
        write_to_resistors(read_resistance(file));
    }
}
