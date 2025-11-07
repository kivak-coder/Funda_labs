all: main

main: main.o overprints.o toDecSys.o Roman.o toNsys.o reverseString.o Zeckendorf.o tests.o memoryDumps.o
	gcc -o main main.o overprints.o toDecSys.o Roman.o toNsys.o reverseString.o Zeckendorf.o tests.o memoryDumps.o

main.o: main.c
	gcc -c main.c

overprints.o: src/overprints.c
	gcc -c src/overprints.c

toDecSys.o: src/toDecSys.c
	gcc -c src/toDecSys.c

Roman.o: src/Roman.c
	gcc -c src/Roman.c

toNsys.o: src/toNsys.c
	gcc -c src/toNsys.c

reverseString.o: src/reverseString.c
	gcc -c src/reverseString.c

Zeckendorf.o: src/Zeckendorf.c
	gcc -c src/Zeckendorf.c

memoryDumps.o: src/memoryDumps.c
	gcc -c src/memoryDumps.c

tests.o: tests/tests.c
	gcc -c tests/tests.c

clean:
	rm -f *.o main