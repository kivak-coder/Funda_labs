all: main

main: main.o functions.o toDecSys.o Romanian.o toNsys.o reverseString.o Zeckendorf.o tests.o
	gcc -o main main.o functions.o toDecSys.o Romanian.o toNsys.o reverseString.o Zeckendorf.o tests.o

main.o: main.c
	gcc -c main.c

functions.o: src/functions.c
	gcc -c src/functions.c

toDecSys.o: src/toDecSys.c
	gcc -c src/toDecSys.c

Romanian.o: src/Romanian.c
	gcc -c src/Romanian.c

toNsys.o: src/toNsys.c
	gcc -c src/toNsys.c

reverseString.o: src/reverseString.c
	gcc -c src/reverseString.c

Zeckendorf.o: src/Zeckendorf.c
	gcc -c src/Zeckendorf.c

tests.o: src/tests.c
	gcc -c src/tests.c

clean:
	rm -f *.o main