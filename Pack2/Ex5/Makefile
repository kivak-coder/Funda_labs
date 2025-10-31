all: main

main: main.o WithoutSpaces.o SeparateAndCheck.o rewriteFiles.o print.o
	gcc -o main main.o WithoutSpaces.o SeparateAndCheck.o rewriteFiles.o print.o

main.o: main.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -I include -c main.c

WithoutSpaces.o: src/WithoutSpaces.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -I include -c src/WithoutSpaces.c -o WithoutSpaces.o

print.o: src/print.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -I include -c src/print.c -o print.o

SeparateAndCheck.o: src/SeparateAndCheck.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -I include -c src/SeparateAndCheck.c -o SeparateAndCheck.o

rewriteFiles.o: src/rewriteFiles.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -I include -c src/rewriteFiles.c -o rewriteFiles.o

clean:
	rm -f main *.o

.PHONY: all clean