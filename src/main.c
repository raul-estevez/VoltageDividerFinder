// TODO:
// README
// Licencia

// v2.0
// Un cli argument con el que puedas elegir la cantidad de respuestas que imprime el programa

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
