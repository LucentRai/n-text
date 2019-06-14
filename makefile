n-text: n-text.o scan-commands.o put-numbers.o
	gcc n-text.o scan-commands.o put-numbers.o -o n-text -I -gnu=11

n-text.o: n-text.c scan-commands.h put-numbers.h
	gcc -c n-text.c

put-numbers.o: put-numbers.c put-numbers.h
	gcc -c put-numbers.c

scan-commands.o: scan-commands.c scan-commands.h
	gcc -c scan-commands.c