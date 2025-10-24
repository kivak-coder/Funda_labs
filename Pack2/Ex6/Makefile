all: main

main: main.o average.o findAndSort.o parseStud.o print.o readStuds.o findType.o
	gcc -o main main.o average.o findAndSort.o parseStud.o print.o readStuds.o findType.o -lm

main.o: main.c include/functions.h
	gcc -Wall -Wextra -c main.c -I include/

average.o: src/average.c include/functions.h
	gcc -Wall -Wextra -c src/average.c -I include/

findAndSort.o: src/findAndSort.c include/functions.h
	gcc -Wall -Wextra -c src/findAndSort.c -I include/

parseStud.o: src/parseStud.c include/functions.h
	gcc -Wall -Wextra -c src/parseStud.c -I include/

print.o: src/print.c include/functions.h
	gcc -Wall -Wextra -c src/print.c -I include/

readStuds.o: src/readStuds.c include/functions.h
	gcc -Wall -Wextra -c src/readStuds.c -I include/

findType.o: src/findType.c include/functions.h
	gcc -Wall -Wextra -c src/findType.c -I include/

clean:
	rm -f *.o main

.PHONY: all clean