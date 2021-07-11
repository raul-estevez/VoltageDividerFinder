// TODO:
// Verbose
// Makefile
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

    cli_handler(argc, argv);

    FILE *file;
    if((file = fopen(FILENAME, "r")) == NULL){
        puts("Error could not open the file.");
        exit(EXIT_FAILURE);
    }
    read_file(file);

    /*
    for(unsigned int i = 0; i < 8; i++){
        printf("%.0f\n", (float)resistors[i]);
    }
    */
    algorithm();
    print_answer();

    return EXIT_SUCCESS;
}
