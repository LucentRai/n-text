/*
    This program creates a text file and puts a range of numbers in it based on given parameters in command line.
*/
#include "scan-commands.h"
#include "put-numbers.h"

#define DEBUG
#define MIN_ARGC 3
#define MAX_ARGC 7

extern bool optionFound[];

int lowerLimit = DEFAULT_LOWER_LIMIT;
unsigned long long upperLimit = 0;
unsigned int minDigit = DEFAULT_MIN_DIGIT;
char *outputFilename = DEFAULT_OUTPUT_FILENAME;

#ifdef DEBUG
void printScannedArguments(int argumentCount);
#endif

int main(int argc, char *argv[]){

#ifdef DEBUG
    printf("\n\t\tDEBUGGING MODE\n");
    printScannedArguments(argc);
#endif

    if(argc < MIN_ARGC){
        printHelpInfo();
    }
    else if(argc > MAX_ARGC){
        printHelpInfo();
    }
    
    scanCommands(argc, argv);
    putNumbers(outputFilename, lowerLimit, upperLimit, minDigit);

    exit(EXIT_SUCCESS);
}

#ifdef DEBUG
void printScannedArguments(int argumentCount){
    printf("\nArgument Cound =%d", argumentCount);
    printf("\n Range = %d - %llu", lowerLimit, upperLimit);
    printf("\nMinimum Digits to print = %u", minDigit);
    printf("\nOutput Filename = %s\n", outputFilename);
    if(optionFound[OPT_R] == true)
        printf("r ");
    if(optionFound[OPT_D] == true)
        printf("d");

    /*for(int i = 0; i < OPT_N; i++){
        if(optionFound[i] = true){
            if(i == OPT_R){
                printf("option \'r\' entered\n");
            }
            else if(i == OPT_D){
                printf("option \'d\' entered\n");
            }
        }
    }*/
}
#endif