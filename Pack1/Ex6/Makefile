all: main

main: main.o trapezoidMethod.o funcToCalculate.o 
	gcc -o main main.o trapezoidMethod.o funcToCalculate.o -lm 

main.o: main.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -c main.c -I include

trapezoidMethod.o: src/trapezoidMethod.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -c src/trapezoidMethod.c -I include

funcToCalculate.o: src/funcToCalculate.c include/functions.h
	gcc -Wall -Wextra -Wpedantic -c src/funcToCalculate.c -I include
clean:
	rm -f *.o main

.PHONY: all clean