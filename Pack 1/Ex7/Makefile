all: main

main: main.o FindMinSys.o parseString.o toDec.o
	gcc -o main main.o FindMinSys.o parseString.o toDec.o

main.o: main.c include/functions.h
	gcc -Wall -Wextra -c main.c -I include

FindMinSys.o: src/FindMinSys.c include/functions.h
	gcc -Wall -Wextra -c src/FindMinSys.c -I include

parseString.o: src/parseString.c include/functions.h
	gcc -Wall -Wextra -c src/parseString.c -I include

toDec.o: src/toDec.c include/functions.h
	gcc -Wall -Wextra -c src/toDec.c -I include

clean:
	rm -f *.o main

.PHONY: all clean