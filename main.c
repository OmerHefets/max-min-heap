#include "heap.h"
#include <stdio.h>

int main()
{

    printf("%d", odd_or_even_depth(1));
    printf("%d", odd_or_even_depth(2));
    printf("%d", odd_or_even_depth(4));
    printf("%d", odd_or_even_depth(6));
    printf("%d", odd_or_even_depth(13));
    printf("%d", odd_or_even_depth(20));
    /*
    int heap[MAX_HEAP_SIZE];
    int heap_size = 0;
    user_interface(heap, &heap_size);
    print_heap(heap, heap_size);
    printf("\t%d\t", heap_size); */
    return 0;
}
