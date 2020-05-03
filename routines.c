#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void heapify(int* array, int index, int heap_size)
{
    int smallest, largest;
    if (check_heap_boundaries(index, heap_size) == FALSE) {
        return;
    }
    if (odd_or_even_depth(index) == ODD_DEPTH) {
        smallest = find_smallest_value_index_sons(array, index, heap_size);
        swap(array, index, smallest);
        smallest = find_smallest_value_index_grandsons(array, index, heap_size);
        if (smallest != index) {
            swap(array, index, smallest);
            heapify(array, smallest, heap_size);
        }
    } else {
        largest = find_largest_value_index_sons(array, index, heap_size);
        swap(array, index, largest);
        largest = find_largest_value_index_grandsons(array, index, heap_size);
        if (largest != index) {
            swap(array, index, largest);
            heapify(array, largest, heap_size);
        }
    }
}

void build_heap(int* array, int heap_size)
{
    int i;
    for (i = (heap_size / 2) ; i >= 1 ; i--) {
        heapify(array, i, heap_size);
    }
}

int heap_extract_max(int* array, int* heap_size)
{
    int max;
    if (*heap_size < 1) {
        exit(1);
    }
    max = array[0];
    array[0] = array[*heap_size - 1];
    (*heap_size)--;
    heapify(array, 1, *heap_size);
    return max;
}

int heap_extract_min()
{
    return 0;
}

void heap_delete()
{
    return;
}

void heap_insert()
{
    return;
}