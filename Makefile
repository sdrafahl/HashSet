All:
	gcc -Wall -g -O -c src/HashSet.c
	ar -cvq hash.a src/HashSet.o
	gcc -static -Wall -ggdb src/main.c -lm -o run hash.a
Clean:
	./scripts/clean.sh
