main: main.o heap_io.o heap.h
	gcc -g -Wall -ansi -pedantic main.o heap_io.o heap.h -o main
main.o: main.c heap.h
	gcc -c -Wall -ansi -pedantic main.c
heap_io.o: heap_io.c heap.h
	gcc -c -Wall -ansi -pedantic heap_io.c