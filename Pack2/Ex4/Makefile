all: main

main: main.o overscan.o Roman.o toDecSys.o validateAll.o Zeckendorf.o
	gcc -o main main.o overscan.o Roman.o toDecSys.o validateAll.o Zeckendorf.o -lm

main.o: main.c include/functions.h
	gcc -Wall -Wextra -c main.c -I include/

overscan.o: src/overscan.c include/functions.h
	gcc -Wall -Wextra -c src/overscan.c -I include/

Roman.o: src/Roman.c include/functions.h
	gcc -Wall -Wextra -c src/Roman.c -I include/

validateAll.o: src/validateAll.c include/functions.h
	gcc -Wall -Wextra -c src/validateAll.c -I include/

Zeckendorf.o: src/Zeckendorf.c include/functions.h
	gcc -Wall -Wextra -c src/Zeckendorf.c -I include/

toDecSys.o: src/toDecSys.c include/functions.h
	gcc -Wall -Wextra -c src/toDecSys.c -I include/

clean:
	rm -f *.o main

.PHONY: all clean