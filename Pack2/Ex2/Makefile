all: main

main: main.o functions.o
	gcc -o main main.o functions.o -lm

main.o: main.c
	gcc -Wall -Wextra -c main.c -I include/

functions.o: src/functions.c
	gcc -Wall -Wextra  -c src/functions.c -I include/
	
clean:
	rm -f *.o main

.PHONY: all clean