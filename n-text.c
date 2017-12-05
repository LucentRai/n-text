/*
    This program creates a text file and puts a range of numbers in it based on given parameters in command line.
*/

#include <stdlib.h>
#include "scan-commands.h"
#include "put-numbers.h"

int argumentCount;
int lowerLimit = DEFAULT_LOWER_LIMIT;
unsigned long long int upperLimit = 0;
unsigned int minDigit = DEFAULT_MIN_DIGIT;
char *outputFilename = DEFAULT_OUTPUT_FILENAME;

int main(int argc, char *argv[]){
#ifdef DEBUG
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
    printf("\nArgument Count = %d\n\
Range = %d - %llu\n\
Minimum Digits to print = %u\n\
Output filename = %s", argumentCount, lowerLimit, upperLimit, minDigit, outputFilename);
}
#endif