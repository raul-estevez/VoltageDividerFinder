#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "cliargs.h"
#include "algorithm.h"

char *FILENAME;
float vin;
float vout;

int verbose_flag = 0;
int help_flag = 0;
int version_flag = 0;

static struct option long_options[] = {
    {"verbose", no_argument, &verbose_flag, 1},
    {"help", no_argument, &help_flag, 1},
    {"version", no_argument, &version_flag, 1},
    {"v", no_argument, 0, 'v'},
    {0,0,0,0}
};



void cli_handler(int argc, char *argv[]){
    opterr = 0;
    int option_index = 0;
    int option;
    while((option = getopt_long(argc, argv, "vh", long_options, &option_index)) != -1){
        switch(option){
            case 'v':
                // Verbose
                puts("VERBOSE");
                // verbose_flag = 1;
                break;
            case 'h':
                // Help page
                puts("HELP");
                break;
            case '?':
                printf("%c\n Unknow option\n", optopt);
                break;
        }
    }

    // Handle the non option parameters
    if(argv[optind] != NULL){
        vin = strtof(argv[optind], NULL);
        printf("Vin: %.2f\n", vin);
    } else {
        // Error
        puts("Error no first argument found.");
        exit(EXIT_FAILURE);
    }

    if(argv[optind+1] != NULL){
        vout = strtof(argv[optind+1], NULL);
        printf("Vout: %.2f\n", vout);
    } else {
        // Error
        puts("Error no second argument found.");
        exit(EXIT_FAILURE);
    }

    if(argv[optind+2] != NULL){
        FILENAME = argv[optind+2];
    } else {
        puts("Error no filename found");
        exit(EXIT_FAILURE);
    }


    if(help_flag){
        puts("LONG HELP");
    }

    if(version_flag){
        puts("LONG VERSION");
    }
}
