all: main

main: main.o stack.o functions.o
	gcc -o main main.o stack.o functions.o

main.o: main.c include/functions.h
	gcc -Iinclude -c main.c -o main.o

stack.o: src/stack.c include/stack.h
	gcc -Iinclude -c src/stack.c -o stack.o

functions.o: src/functions.c include/functions.h
	gcc -Iinclude -c src/functions.c -o functions.o

clean:
	rm -f main main.o stack.o functions.o

.PHONY: all clean