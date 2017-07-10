All:
	clear
	gcc -Wall -g -O -c src/HashSet.c
	ar -cvq hash.a HashSet.o
	gcc -static -Wall -ggdb src/main.c -o run hash.a -lm
Clean:
	./scripts/clean.sh
