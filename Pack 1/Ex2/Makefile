all: main

main: main.o parseArgs.o PrimeN.o 
	gcc -Wall -Wextra -o main main.o parseArgs.o PrimeN.o -lm

main.o: main.c
	gcc -Wall -Wextra -c main.c -I include/

parseArgs.o: src/parseArgs.c
	gcc -Wall -Wextra -c src/parseArgs.c -I include/

PrimeN.o: src/PrimeN.c
	gcc -Wall -Wextra -c src/PrimeN.c -I include/

clean: 
	rm -f *.o main

.PHONY: all clean