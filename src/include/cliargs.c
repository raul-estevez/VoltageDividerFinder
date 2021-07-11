#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "cliargs.h"
#include "algorithm.h"

#define VERSION "1.0"

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
                verbose_flag = 1;
                break;
            case 'h':
                // Help page
                help_handler();
                break;
            case '?':
                printf("Unknow option -%c\n", optopt);
                break;
        }
    }

    if(help_flag){
        help_handler();
    }

    if(version_flag){
        version_handler();
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
}

void help_handler(void){
    printf("VoltageDividerFinder %s\n\n", VERSION);
    puts("USAGE\n\tvdf Vin Vout file [options]");
    puts("-----------------------------------------------------");
    puts("DESCRIPTION");
    puts("\tA handy tool for creating voltage dividers with the resistors you have in hand.");
    puts("-----------------------------------------------------");
    puts("CIRCUIT DIAGRAM;");
    puts("\t ^ Vin");
    puts("\t ⊥");
    puts("\t| |");
    puts("\t| | R1");
    puts("\t ⊤");
    puts("\t |———— Vout");
    puts("\t ⊥");
    puts("\t| |");
    puts("\t| | R2");
    puts("\t ⊤");
    puts("\t |");
    puts("\t ¯");
    puts("-----------------------------------------------------");
    puts("OPTIONS");
    puts("\t--verbose\t-v\tPrints verbose info.");
    puts("\t--help\t\t-h\tDisplays this help page.");
    puts("\t--version\t  \tDisplays the version message.");
    puts("-----------------------------------------------------");
    puts("EXAMPLE");
    puts("\tLets say you have Vin = 12v and you want Vout = 8v, you resistors are in my_resistors.txt");
    puts("\t\t$ vdf 12 8 my_resistors.txt");
    puts("\tAnd the program prints the best 5 combinations of resistors with less error.");
    puts("-----------------------------------------------------");
    puts("Created by: Raúl Estévez Gómez    <estevezgomezraul@gmail.com>\n");
    puts("If you encounter any bug, please refer to https://github.com/SarKing/VoltageDividerFinder");

    exit(EXIT_SUCCESS);
}

void version_handler(void){
    printf("VoltageDividerFinder %s\n", VERSION);
    puts("Copyright (C) 2021 Raúl Estévez Gómez");
    puts("This is free software: you are free to change and redistribute it.");
    puts("There is NO WARRANTY, to the extent permitted by law.");

    exit(EXIT_SUCCESS);
}
