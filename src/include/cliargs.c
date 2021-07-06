#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "cliargs.h"
#include "algorithm.h"

char *FILENAME;
float vin;
float vout;


void cli_handler(int argc, char *argv[]){
    int option;
    while(option = getopt(argc, argv, "vVhHG") != -1){
        switch(option){
            case 'v':
            case 'V':
                // Verbose
                break;
            case 'h':
            case 'H':
                // Help page
                break;
            case 'G':
                // version 
                // Implement long argument
                break;
        }
    }

    // Handle the non option parameters
    if(argv[optind] != NULL){
        vin = strtof(argv[optind], NULL);
        printf("%f\n", vin);
    } else {
        // Error
    }

    if(argv[optind+1] != NULL){
        vout = strtof(argv[optind+1], NULL);
        printf("%f\n\n\n\n\n\n", vout);
    } else {
        // Error
    }

    if(argv[optind+2] != NULL){
        FILENAME = argv[optind+2];
    } else {
        // Error
    }
}
