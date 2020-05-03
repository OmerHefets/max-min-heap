#include "heap.h"
#include <stdio.h>

int main()
{
    int len=21;
    int arr[21] = {125, 70, 15, 22, 150, 60, 100, 70, 100, 10, 1000, 50, 90, 50, 50, 50, 85, 70, 45, 60, 100};
    build_heap(arr, len);
    print_heap(arr, len);
    heap_extract_max(arr, &len);
    print_heap(arr, len);
    printf("%d", len);
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
