n-text: n-text.c scan-commands.h put-numbers.h
	gcc n-text.c -o n-text -I -gnu=11

put-numbers: put-numbers.c put-numbers.h
	gcc -c put-numbers.c

scan-commands: scan-commands.c scan-commands.h
	gcc -c scan-commands.c