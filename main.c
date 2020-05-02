#include "heap.h"
#include <stdio.h>

int main()
{
    int heap[MAX_HEAP_SIZE];
    int heap_size = 0;
    user_interface(heap, &heap_size);
    /* read_file("input1.txt", heap, &heap_size); */
    print_heap(heap, heap_size);
    printf("\t%d\t", heap_size);
    return 0;
}