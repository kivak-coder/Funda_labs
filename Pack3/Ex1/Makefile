all: main

main: main.o convertToBase.o stringOperations.o operations.o
	gcc -o main main.o convertToBase.o stringOperations.o operations.o

main.o: main.c include/functions.h
	gcc -c main.c

convertToBase.o: src/convertToBase.c include/functions.h
	gcc -c src/convertToBase.c

stringOperations.o: src/stringOperations.c include/functions.h
	gcc -c src/stringOperations.c

operations.o: src/operations.c include/functions.h
	gcc -c src/operations.c

clean:
	rm -f *.o main