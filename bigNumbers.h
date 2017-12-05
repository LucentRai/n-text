/* Contains functions for storing large numbers in character format.
 */
#ifndef BIG_NUMBERS_H
#define BIG_NUMBERS_H

struct bigNumber{
    int digits;
    char n[];
};

void copyNumberFromArg(char *a); //copys numbers from command-line argument or any string with digits stored as char
struct bigNumber *addOne(struct bigNumber *n); //add one and returns the result
int characterToInt(char ch);
char intToCharacter(int i);

#endif