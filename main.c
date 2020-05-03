#include "heap.h"
#include <stdio.h>

int main()
{
    int arr[21] = {1000, 10, 15, 22, 150, 100, 100, 70, 60, 45, 125, 50, 50, 50, 50, 90, 85, 70, 70, 60, 100};
    heapify(arr, 4, 21);
    print_heap(arr, 21);
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
