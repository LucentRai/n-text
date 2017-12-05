# n-text

This program creates a text file and puts a range of numbers in it based on given parameters in command line.

Usage: n-text file_name [option] LOWER_LIMIT-UPPER_LIMIT [option] [numeric-value]

*If the range is not given the default LOWER_LIMIT is 0.
*If the minimum digits options is not specified the default value 0 will be set

Options:
            r       Range: range of numbers that are to be put in the text file
            d       Minimum digits: minimum number of digits to put; if the number is less than this value, necessary zeros are added

Examples:
n-text a.txt -r 9999                prints 0 to 9999 in a.txt
n-text -r 5555-99999 -d 5           prints 05555 to 99999 in generated_n_file.txt
n-text dic.txt -r 0-1000000 -d 7    prints 0000000 to 1000000 in dic.txt
n-text pass.txt -r 99999999 -d 5    prints 00000 to 99999999 in pass.txt
