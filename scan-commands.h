#ifndef SCAN_COMMANDS_H
#define SCAN_COMMANDS_H

#include <stdbool.h>

#define DEBUG
#define MIN_ARGC 3        //minimum number of arguments to be supplied to the program
#define MAX_ARGC 6        //maximum number of arguments to be supplied to the program
#define OPT_1 'r'         //option 1: stands for range
#define OPT_2 'd'         //option 2: stands for minimum digits to display
#define HELP_FILENAME "help.dat"

void printHelpInfo(void);
int scanCommands(char *programArgs[]);

#ifdef DEBUG
void printScannedArguments(void);
#endif

#endif