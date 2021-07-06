
// TODO:
// Implemetar la introducion de parametros desde la terminal
// Implementar la introducion de datos desde un archivo
// README
// Licencia

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "./include/algorithm.h"
#include "./include/cliargs.h"


int main(int argc, char *argv[]){

    cli_handler(argc, argv);
    algorithm();
    print_answer();

    return 0;
}
