// TODO:
// Error handling
// Verbose
// Makefile
// README
// Licencia

// v2.0
// Un cli argument con el que puedas elegir la cantidad de respuestas que imprime el programa

#include <stdio.h>
#include <unistd.h>

#include "./include/algorithm.h"
#include "./include/cliargs.h"
#include "./include/read_file.h"


int main(int argc, char *argv[]){

    cli_handler(argc, argv);

    FILE *file;
    file = fopen(FILENAME, "r");
    read_file(file);

    /*
    for(unsigned int i = 0; i < 8; i++){
        printf("%.0f\n", (float)resistors[i]);
    }
    */
    algorithm();
    print_answer();

    return 0;
}
