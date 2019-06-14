#include "scan-commands.h"
#include "put-numbers.h"

extern int argumentCount;
extern int lowerLimit;
extern unsigned long long int upperLimit;
extern unsigned int minDigit;
extern char *outputFilename;

bool filenameFound = false;
bool rangeFound = false;

void findRange(char *p);

int scanCommands(char *programArgs[]){
    if( argumentCount < MIN_ARGC){
        printHelpInfo;
    }
    for(int i = 1; i < argumentCount; i++){
        if(programArgs[i][0] == '-'){
            if(programArgs[i][1] == OPT_1 && !rangeFound){
                optionFound[OPT_R] = true;
                findRange(programArgs[++i]);
            }
            else if(programArgs[i][1] == OPT_2){
                i++;
                if(!isdigit(programArgs[i][0])){
                    printHelpInfo();
                }
                optionFound[OPT_D] = true; 
                sscanf(programArgs[i], "%d", &minDigit);
            }
            else{
                printHelpInfo();
            }
        }
        else if( !filenameFound && isalnum(programArgs[i][0]) ){
            filenameFound = true;
            outputFilename = programArgs[i];
        }
    }

    if(!rangeFound){    // if user did not specify the range
        printHelpInfo();
    }
}

void findRange(char *p){
    if( sscanf(p, "%d-%llu", &lowerLimit, &upperLimit) == 2 ){
        rangeFound = true;
    }
    else if( sscanf(p, "%llu", &upperLimit) == 1){
        lowerLimit = DEFAULT_LOWER_LIMIT;   //lowerLimit value may have been set in the previous if statement
        rangeFound = true;
    }
    else{
        rangeFound = false;
    }

    if(rangeFound && lowerLimit >= upperLimit){
        fprintf(stderr, "\t\tERROR!!!\nLower limit is greater than upper limit.");
        printHelpInfo();
        exit(EXIT_SUCCESS);
    }
}

void printHelpInfo(void){
    FILE *helpFile;
    int ch;

    printf("\n");
    if((helpFile = fopen(HELP_FILENAME, "r")) == NULL){
        #ifdef DEBUG
            fprintf(stderr, "\nCOULD NOT OPEN HELP FILE.\n");
        #else
            fprintf(stderr, "Syntax error!!!\n"); //default message.
        #endif
    }
    else{
        while((ch = getc(helpFile)) != EOF){
            putchar(ch);
        }
        printf("\n");
    }

    fclose(helpFile);
    exit(EXIT_SUCCESS);
}