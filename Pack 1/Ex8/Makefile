all: main

main: main.o parsing.o toNumericSystems.o
	gcc -o main main.o parsing.o toNumericSystems.o -lm

main.o: main.c
	gcc -c main.c -I include/

toNumericSystems.o: src/toNumericSystems.c
	gcc -c src/toNumericSystems.c -I include/

parsing.o: src/parsing.c
	gcc -c src/parsing.c -I include/

clean:
	rm -f *.o main

.PHONY: all clean