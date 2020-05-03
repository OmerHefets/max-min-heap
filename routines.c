#include <stdio.h>
#include "heap.h"

void heapify(int* array, int index, int heap_size)
{
    int smallest, largest;
    if (check_heap_boundaries(index, heap_size) == FALSE) {
        return;
    }
    if (odd_or_even_depth(index) == ODD_DEPTH) {
        smallest = find_smallest_value_index_sons(array, index, heap_size);
        printf("%d", smallest);
        swap(array, index, smallest);
        smallest = find_smallest_value_index_grandsons(array, index, heap_size);
        if (smallest != index) {
            swap(array, index, smallest);
            heapify(array, smallest, heap_size);
        }
    } else {
        largest = find_largest_value_index_sons(array, index, heap_size);
        printf("%d", largest);
        swap(array, index, largest);
        largest = find_largest_value_index_grandsons(array, index, heap_size);
        if (largest != index) {
            swap(array, index, largest);
            heapify(array, largest, heap_size);
        }
    }
}

void build_heap()
{
    return;
}

int heap_extract_max()
{
    return 0;
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