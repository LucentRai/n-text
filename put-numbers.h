#ifndef PUT_NUMBERS_H
#define PUT_NUMBERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LOWER_LIMIT 0       //default lower limit in the range
#define DEFAULT_MIN_DIGIT 0         //default minimum digits to print
#define DEFAULT_OUTPUT_FILENAME "generated_n_file.txt"      //default output filename if filename is not specified

void putNumbers(FILE *fp, int lowerLimit, unsigned long long int upperLimit, int minDigit);

#endif