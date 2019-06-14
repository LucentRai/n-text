#include "put-numbers.h"

void putNumbers(char *filename, int lowerLimit, unsigned long long int upperLimit, int minDigit){
    FILE *fp;

    if((fp = fopen(filename, "w")) == NULL){
        printf("\n !!! ERROR! Could not create file.");
        exit(EXIT_FAILURE);
    }

    for(unsigned long long i = lowerLimit; i < upperLimit; i++){
        fprintf(fp, "%.%dllu\n", minDigit, i);
    }

    fclose(fp);
}