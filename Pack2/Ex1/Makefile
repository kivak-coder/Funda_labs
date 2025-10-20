all: main

main: main.o DivNumDenum.o gcd.o Infinite.o
	gcc -o main main.o DivNumDenum.o gcd.o Infinite.o -lm

main.o: main.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c main.c -I include

DivNumDenum.o: src/DivNumDenum.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c src/DivNumDenum.c -I include

gcd.o: src/gcd.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c src/gcd.c -I include

Infinite.o: src/Infinite.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c src/Infinite.c -I include

clean: 
	rm -f *.o main

.PNONY: all clean