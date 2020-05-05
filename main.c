/**
 * the main script for running the heap program.
 * calling the user interface with initialized array to hold the heap values, and sending a pointer to the heap size
 */

#include "heap.h"

int main()
{
    int heap[MAX_HEAP_SIZE];
    int heap_size = 0;
    user_interface(heap, &heap_size);
    return 0;
}
