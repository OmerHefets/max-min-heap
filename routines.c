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
        printf("Trying to extract a number from an empty heap. Start again with a new heap.\n");
        exit(1);
    }
    max = array[0];
    array[0] = array[*heap_size - 1];
    (*heap_size)--;
    if (*heap_size >= 1) {
        heapify(array, 1, *heap_size);
    }
    return max;
}

int heap_extract_min(int* array, int* heap_size)
{
    int smallest_index, smallest_value;
    if (*heap_size < 1) {
        printf("Trying to extract a number from an empty heap. Start again with a new heap.\n");
        exit(1);
    }
    smallest_index = find_smallest_value_index_sons(array, 1, *heap_size);
    smallest_value = array[smallest_index-1];
    array[smallest_index-1] = array[*heap_size-1];
    (*heap_size)--;
    if (*heap_size >= 1) {
        heapify(array, smallest_index, *heap_size);
    }
    return smallest_value;
}

void heap_delete(int* array, int index, int* heap_size)
{
    if (check_heap_boundaries(index, *heap_size) == FALSE) {
        return;
    }
    swap(array, index, *heap_size);
    (*heap_size)--;
    heapify(array, index, *heap_size);
}

void heap_insert(int* array, int key, int* heap_size)
{
    int n;
    n = ++(*heap_size);
    array[n-1] = key;
    if (odd_or_even_depth(n) == ODD_DEPTH && n > 1 && array[n-1] > array[parent(n)-1]) {
        swap(array, n, parent(n));
        n = parent(n);
    } else if (odd_or_even_depth(n) == EVEN_DEPTH && n > 1 && array[n-1] < array[parent(n)-1]) {
        swap(array, n, parent(n));
        n = parent(n);
    }
    if (odd_or_even_depth(n) == ODD_DEPTH) {
        while (n > 3 && array[n-1] < array[parent(parent(n))-1]) {
            swap(array, n, parent(parent(n)));
            n = parent(parent(n));
        }
    } else {
        while (n > 3 && array[n-1] > array[parent(parent(n))-1]) {
            swap(array, n, parent(parent(n)));
            n = parent(parent(n));
        }
    }
}