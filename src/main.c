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

// v2.0
// A CLI argument that lets you choose how many outputs you want

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./include/algorithm.h"
#include "./include/cliargs.h"
#include "./include/read_file.h"


int main(int argc, char *argv[]){

    // Handle the terminal arguments
    cli_handler(argc, argv);

    // Open the file 
    FILE *file;
    if((file = fopen(FILENAME, "r")) == NULL){
        puts("Error could not open the file.");
        exit(EXIT_FAILURE);
    }

    // First we need to read the file to get all the input resistors in an array
    read_file(file);
    // Then we pass the array by the algorithm
    algorithm();
    // And print the answer to the user
    print_answer();

    return EXIT_SUCCESS;
}
