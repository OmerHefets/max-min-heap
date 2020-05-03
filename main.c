#include "heap.h"
#include <stdio.h>

int main()
{
    int arr[11] = {1000, 100, 15, 120, 150, 100, 100, 70, 60, 10, 125};
    heapify(arr, 2, 11);
    print_heap(arr, 11);
    return 0;   
    /*
    int heap[MAX_HEAP_SIZE];
    int heap_size = 0;
    user_interface(heap, &heap_size);
    print_heap(heap, heap_size);
    printf("\t%d\t", heap_size);
    return 0;
    */
}
