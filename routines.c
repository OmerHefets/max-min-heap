/**
 * this module holds all the requested routines in the mmn.
 * calling helper functions from the helper_function modules to make the code more readable.
 */

#include <stdlib.h>
#include "heap.h"

/**
 * fix one vertice of the heap, assuming all his sons are a max-min-heap
 * param *array - the heap 
 * param index - the requested verice index 
 * param heap_size - the heap size
 */
void heapify(int* array, int index, int heap_size)
{
    int smallest, largest;
    if (check_heap_boundaries(index, heap_size) == FALSE) {
        return;
    }
    /* for each case of odd or even, first choose smallest / largest from his sons, then grandsons, */
    /* and then make sure the heap exists with HEAPIFY on the grandson (if switched) */
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

/**
 * building a heap from an existing array
 * param *array - the heap 
 * param heap_size - the heap size
 */
void build_heap(int* array, int heap_size)
{
    /* same implementation as in the book */
    int i;
    for (i = (heap_size / 2) ; i >= 1 ; i--) {
        heapify(array, i, heap_size);
    }
}

/**
 * extracting (get and delete) the maximum value of the heap.
 * param *array - the heap 
 * param *heap_size - pointer to the heap size
 */
int heap_extract_max(int* array, int* heap_size)
{
    /* same implementation as in the book */
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


/**
 * extracting (get and delete) the minimum value of the heap
 * param *array - the heap 
 * param *heap_size - pointer to the heap size
 */
int heap_extract_min(int* array, int* heap_size)
{
    /* same implementation as in the book, simply choose the smallest from the first 3 vertices */
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

/**
 * deleting a verice from the heap
 * param *array - the heap 
 * param index - the vertices index to delete
 * param *heap_size - pointer to the heap size
 */
void heap_delete(int* array, int index, int* heap_size)
{
    /* swap the deleted value with the last vertice on the heap, and HEAPIFY on the new one */
    if (check_heap_boundaries(index, *heap_size) == FALSE) {
        return;
    }
    swap(array, index, *heap_size);
    (*heap_size)--;
    heapify(array, index, *heap_size);
}


/**
 * insert a new vertice to the heap
 * param *arr - the heap 
 * param key - value of the verice to be inserted
 * param *heap_size - pointer to the heap size
 */
void heap_insert(int* array, int key, int* heap_size)
{
    /* propagating upwards the value, but first checking if its supposed to be a min value or max value */
    /* depends on the depth of the tree (odd or even) */
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