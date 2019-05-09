CFLAGS= -Wall -fpic -coverage -lm -std=c99


all: testme.c
	gcc -o testme testme.c -g $(CFLAGS)
	gcov testme.c >> results.out
	./testme

clean:
	rm -f *results.out testme *.gcno *.gcov
