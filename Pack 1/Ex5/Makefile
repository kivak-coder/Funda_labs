all: main

main: main.o parsing.o funcA.o funcB.o funcC.o funcD.o 
	gcc -o main main.o parsing.o funcA.o funcB.o funcC.o funcD.o -lm

main.o: main.c include/functions.h
	gcc -Wall -Wextra -c main.c -I include

parsing.o: src/parsing.c include/functions.h
	gcc -Wall -Wextra -c src/parsing.c -I include

funcA.o: src/funcA.c include/functions.h
	gcc -Wall -Wextra -c src/funcA.c -I include

funcB.o: src/funcB.c include/functions.h
	gcc -Wall -Wextra -c src/funcB.c -I include

funcC.o: src/funcC.c include/functions.h
	gcc -Wall -Wextra -c src/funcC.c -I include

funcD.o: src/funcD.c include/functions.h
	gcc -Wall -Wextra -c src/funcD.c -I include

clean:
	rm -f *.o main

.PHONY: all clean