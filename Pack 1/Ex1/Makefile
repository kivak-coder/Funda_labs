all: main

main: main.o funcA.o funcB.o funcC.o funcD.o funcE.o funcF.o
	gcc -o main main.o funcA.o funcB.o funcC.o funcD.o funcE.o funcF.o -lm

main.o: main.c
	gcc -c main.c -I include/

funcA.o: src/funcA.c
	gcc -c src/funcA.c -I include/

funcB.o: src/funcB.c
	gcc -c src/funcB.c -I include/

funcC.o: src/funcC.c
	gcc -c src/funcC.c -I include/

funcD.o: src/funcD.c
	gcc -c src/funcD.c -I include/

funcE.o: src/funcE.c
	gcc -c src/funcE.c -I include/

funcF.o: src/funcF.c
	gcc -c src/funcF.c -I include/

clean:
	rm -f *.o main

.PHONY: all clean