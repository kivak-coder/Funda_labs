all: main test1

main: main.o DivNumDenum.o gcd.o Infinite.o
	gcc -o main main.o DivNumDenum.o gcd.o Infinite.o -lm

test1: test1.o DivNumDenum.o gcd.o Infinite.o
	gcc -o test1 test1.o DivNumDenum.o gcd.o Infinite.o -lm

main.o: main.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c main.c -I include

test1.o: test1.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c test1.c -I include

DivNumDenum.o: src/DivNumDenum.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c src/DivNumDenum.c -I include

gcd.o: src/gcd.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c src/gcd.c -I include

Infinite.o: src/Infinite.c include/functions.h
	gcc -Wpedantic -Wall -Wextra -c src/Infinite.c -I include

clean:
	rm -f *.o main test1

.PHONY: all clean