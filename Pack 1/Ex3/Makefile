all: main

main: main.o funcA.o funcB.o funcC.o reading.o
	gcc -o main main.o funcA.o funcB.o funcC.o reading.o -lm

main.o: main.c include/functions.h
	gcc -c main.c -I include/

funcA.o: src/funcA.c include/functions.h
	gcc -c src/funcA.c -I include/

funcB.o: src/funcB.c include/functions.h
	gcc -c src/funcB.c -I include/

funcC.o: src/funcC.c include/functions.h
	gcc -c src/funcC.c -I include/

reading.o: src/reading.c include/functions.h
	gcc -c src/reading.c -I include/

clean:
	rm -f *.o main

.PHONY: all clean