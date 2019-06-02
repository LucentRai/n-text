n-text: n-text.c scan-commands.o put-numbers.o
	gcc n-text.c scan-commands.o put-numbers.o -o n-text -I -gnu=11

put-numbers.o: put-numbers.c put-numbers.h
	gcc -c put-numbers.c

scan-commands.o: scan-commands.c scan-commands.h
	gcc -c scan-commands.c