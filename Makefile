All:
	gcc -Wall -g -O -c HashSet.c
	ar -cvq hash.a HashSet.o
	gcc -static -Wall -ggdb main.c -lm  -o run hash.a
