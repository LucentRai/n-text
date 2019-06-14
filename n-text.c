/*
    This program creates a text file and puts a range of numbers in it based on given parameters in command line.
*/
#include "scan-commands.h"
#include "put-numbers.h"

#define DEBUG
#define MIN_ARGC 3
#define MAX_ARGC 7

extern bool optionFound[OPT_N];

int argumentCount;
int lowerLimit = DEFAULT_LOWER_LIMIT;
unsigned long long upperLimit = 0;
unsigned int minDigit = DEFAULT_MIN_DIGIT;
char *outputFilename = DEFAULT_OUTPUT_FILENAME;

#ifdef DEBUG
void printScannedArguments(void);
#endif

int main(int argc, char *argv[]){
#ifdef DEBUG
    printf("\n\t\tDEBUGGING MODE\n");
#endif

    if(argc < MIN_ARGC){
        printHelpInfo();
    }
    else if(argc > MAX_ARGC){
        printHelpInfo();
    }

    argumentCount = argc;
    
    scanCommands(argv);
#ifdef DEBUG
    printScannedArguments();
#endif
    //putNumbers(outputFilename, lowerLimit, upperLimit, minDigit);

    exit(EXIT_SUCCESS);
}

#ifdef DEBUG
void printScannedArguments(void){
    printf("\nArgument Cound =%d", argumentCount);
    printf("\n Range = %d - %llu", lowerLimit, upperLimit);
    printf("\nMinimum Digits to print = %u", minDigit);
    printf("\nOutput Filename = %s\n", outputFilename);
    
    for(int i = 0; i < OPT_N; i++){
        if(optionFound[i] = true){
            if(i == OPT_R){
                printf("option \'r\' entered");
            }
            else if(i == OPT_D){
                printf("option \'d\' entered");
            }
        }
    }
}
#endif