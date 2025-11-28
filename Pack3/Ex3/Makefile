all: main

main: main.o linkedList.o liver.o stack.o
	gcc -o main main.o linkedList.o liver.o stack.o

main.o: main.c include/linkedList.h include/liver.h include/stack.h
	gcc -Wall -Wextra -Wpedantic -Iinclude -c main.c -o main.o

linkedList.o: src/linkedList.c include/linkedList.h include/liver.h
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/linkedList.c -o linkedList.o

liver.o: src/liver.c include/liver.h
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/liver.c -o liver.o

stack.o: src/stack.c include/stack.h include/linkedList.h
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/stack.c -o stack.o

clean:
	rm -f *.o main

.PHONY: all clean