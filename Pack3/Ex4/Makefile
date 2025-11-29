all: main

main: main.o heap.o 
	gcc -o main main.o heap.o -lm

main.o: main.c include/heap.h
	gcc -Wall -Wextra -Wpedantic -Iinclude -c main.c -o main.o

heap.o: src/heap.c include/heap.h 
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/heap.c -o heap.o

clean:
	rm -f *.o main

.PHONY: all clean