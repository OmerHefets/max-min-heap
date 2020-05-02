#include <stdio.h>
#include "heap.h"

int check_heap_boundaries(int index, int heap_size)
{
    if (index > heap_size) {
        printf("Index out of bound. try again.\n");
        return 0;
    }
    return 1;
}

int odd_or_even_depth(int index)
{
    int depth = 0;
    int min_bound = 1, max_bound = 1;
    int multiplier = 2;
    while (index < min_bound || index > max_bound) {
        min_bound = max_bound;
        max_bound += multiplier;
        multiplier *= 2;
        depth = !depth;
    }
    return depth;
    
    return 0;
}