#include "heap.h"
#include <stdio.h>

int main()
{
    int heap[MAX_HEAP_SIZE];
    int heap_size = 0;
    print_instruction();
    read_array(heap, &heap_size);
    print_heap(heap, heap_size);
    user_interface();
    return 0;
}