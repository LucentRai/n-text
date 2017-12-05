#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "bigNumbers.h"

struct bigNumber *nString;

void copyNumberFromArg(char *a){
    char *ch = a;
    int digit = 0;
    int i = 0;

    while(*ch != '\0'){
        if(isdigit(*ch)){
            digit++;
        }
        else{
            break;
        }
        ch++;
    }

    nString = malloc(sizeof(struct bigNumber) + digit + 1);
    nString->digits = digit;

    ch = a;
    while(digit--){
        nString->n[i++] = *ch;
        ch++;
    }
    nString->n[i] = '\0';
}

struct bigNumber *addOne(struct bigNumber *num){
    int i;
    bool added = false;
    struct bigNumber *result;

    if( (result = malloc( sizeof(num) )) == NULL){
        fprintf(stderr, "\nError in %s!!!. Could not allocate space.\nExiting the program...", __func__);
        exit(EXIT_FAILURE);
    }
    result->digits = num->digits;
    strncpy(result->n, num->n, num->digits);
    result->n[result->digits] = '\0';
    i  = result->digits - 1;   //position of last digit in the array

    while( characterToInt(result->n[i]) == 9 ){     //for numbers ending with 9
        result->n[i] = '0';
        if(--i < 0){    // if adding 1 to the number increases its digits
            if( realloc(result, sizeof(result) + 1) == NULL ){    // 1 Byte for the new digit that appears at the left most side
                fprintf(stderr, "\nError in %s. Could not reallocate memory\nExiting from the program.\n", __func__);
                exit(EXIT_FAILURE);
            }
            for(int j = result->digits; j >= 0; j--){         //shifting digits right
                result->n[j + 1] = result->n[j];
            }
            result->n[0] = '1';
            result->digits++;
            added = true;
            break;
        }
        else if( characterToInt(result->n[i]) != 9 ){
            result->n[i] = intToCharacter( characterToInt(result->n[i]) + 1 );
            added = true;
            break;
        }
    }

    if(!added){     //for numbers that don't end with 9
        result->n[i] = intToCharacter( characterToInt(result->n[i]) + 1 );
        return result;
    }
    else{
        return result;
    }
}

int characterToInt(char ch){
    switch(ch){
        case '0': return 0;
                  break;
        case '1': return 1;
                  break;
        case '2': return 2;
                  break;
        case '3': return 3;
                  break;
        case '4': return 4;
                  break;
        case '5': return 5;
                  break;
        case '6': return 6;
                  break;
        case '7': return 7;
                  break;
        case '8': return 8;
                  break;
        case '9': return 9;
                  break;
        case '\0': fprintf(stderr, "\nError in %s. Encountered NULL character in the array", __func__);
                   break;
        default:  fprintf(stderr, "\nError in %s. Invalid non-numeric character in the array", __func__);
                  break;
    }
}

char intToCharacter(int i){
    switch(i){
        case 0: return '0';
                  break;
        case 1: return '1';
                  break;
        case 2: return '2';
                  break;
        case 3: return '3';
                  break;
        case 4: return '4';
                  break;
        case 5: return '5';
                  break;
        case 6: return '6';
                  break;
        case 7: return '7';
                  break;
        case 8: return '8';
                  break;
        case 9: return '9';
                  break;
        default:  fprintf(stderr, "\nError in %s. Invalid character in the array", __func__);
                  break;
    }
}