main: main.o heap_io.o routines.o helper_functions.o heap.h
	gcc -g -Wall -ansi -pedantic main.o heap_io.o routines.o helper_functions.o heap.h -o main
main.o: main.c heap.h
	gcc -c -Wall -ansi -pedantic main.c
heap_io.o: heap_io.c heap.h
	gcc -c -Wall -ansi -pedantic heap_io.c
routines.o: routines.c heap.h
	gcc -c -Wall -ansi -pedantic routines.c
helper_functions.o: helper_functions.c heap.h
	gcc -c -Wall -ansi -pedantic helper_functions.c

# cleanup
clean:
	rm *.o