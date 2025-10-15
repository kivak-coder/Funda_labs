all: main

main: main.o rewriteFiles.o
	gcc -o main main.o rewriteFiles.o

main.o: main.c include/rewriteFiles.h
	gcc -Wpedantic -Wall -Wextra -c main.c -I include

rewriteFiles.o: src/rewriteFiles.c include/rewriteFiles.h
	gcc -Wpedantic -Wall -Wextra -c src/rewriteFiles.c -I include

clean: 
	rm -f *.o main

.PNONY: all clean