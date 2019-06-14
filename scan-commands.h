#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define OPT_1 'r'
#define OPT_2 'd'
#define OPT_N 2                 //number of options
#define OPT_R 0                 //array index for 'r' option 
#define OPT_D 1                 //array index for 'd' option
#define DEFAULT_LOWER_LIMIT 0
#define DEFAULT_MIN_DIGIT 9
#define DEFAULT_OUTPUT_FILENAME "numbers.txt"
#define HELP_FILENAME "help"
#define MIN_ARGC 3

<<<<<<< HEAD

int scanCommands(int argc, char **argv);
=======
bool optionFound[OPT_N] = {false};

int scanCommands(char **argv);
>>>>>>> 0a44b9758cac4b95e47cf8e50712ef24ab488836
void printHelpInfo(void);