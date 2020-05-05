/**
 * this module holds functions that mainly help the rountines of the mmn, and makes the code more readable.
 */

#include "heap.h"

/**
 * make sure a requested index is in the boudaries of an existing array. return TRUE (1) if yes, FALSE (0) if not
 * param index - the index to be checked
 * param heap_size - the size of the heap.
 */
int check_heap_boundaries(int index, int heap_size)
{
    if (index > heap_size || index < 1) {
        printf("Index out of bound. try again.\n");
        return FALSE;
    }
    return TRUE;
}

/**
 * check if a specific vertice of the heap is on a odd or even depth.
 * param index - the index of the vertice
 */
int odd_or_even_depth(int index)
{
    int depth = EVEN_DEPTH;
    int min_bound = 1, max_bound = 1;
    int multiplier = 2;
    /* we've learned that max number of leaves on a tree with height h is 2^h. */
    /* so increasing the value each time by 2^h of the boundaries */
    while (index < min_bound || index > max_bound) {
        min_bound = max_bound;
        max_bound += multiplier;
        multiplier *= 2;
        depth = !depth;
    }
    return depth;
}

/**
 * swap two values in an array. useful for switching values in heaps
 * param *arr - the array
 * param index_a - the first index to be switched
 * param index_b - the second index to be switched
 */
void swap(int* arr, int index_a, int index_b)
{
    int temp;
    temp = arr[index_a-1];
    arr[index_a-1] = arr[index_b-1];
    arr[index_b-1] = temp;
}

/**
 * calculate parent index for a specific vertice
 * param index - index of the veritce
 */
int parent(int index)
{
    int val;
    val = (index / 2);
    return val;
}


/**
 * calculate left son index of a vertice
 * param index - index of the veritce
 */
int left(int index)
{
    return (2 * index);
}

/**
 * caculate right son index of a vertice
 * param index - index of the veritce
 */
int right(int index)
{
    return (2 * index) + 1;
}


/**
 * return the index of the smallest value from a vertice and its sons
 * param *arr - the array
 * param index - the index of the vertice
 * param heap_size - the size of the heap
 */
int find_smallest_value_index_sons(int* arr, int index, int heap_size)
{
    int smallest;
    int l = left(index);
    int r = right(index);
    if ((l <= heap_size) && arr[l-1] < arr[index-1]) {
        smallest = l;
    } else {
        smallest = index;
    }
    if ((r <= heap_size) && arr[r-1] < arr[smallest-1]) {
        smallest = r;
    }
    return smallest;
}

/**
 * return the index of the largest value from a vertice and its sons
 * param *arr - the array
 * param index - the index of the vertice
 * param heap_size - the size of the heap
 */
int find_largest_value_index_sons(int* arr, int index, int heap_size)
{
    int largest;
    int l = left(index);
    int r = right(index);
    if ((l <= heap_size) && arr[l-1] > arr[index-1]) {
        largest = l;
    } else {
        largest = index;
    }
    if ((r <= heap_size) && arr[r-1] > arr[largest-1]) {
        largest = r;
    }
    return largest;
}

/**
 * return the index of the smallest value from a vertice and its grandsons
 * param *arr - the array
 * param index - the index of the vertice
 * param heap_size - the size of the heap
 */
int find_smallest_value_index_grandsons(int* arr, int index, int heap_size)
{
    int smallest;
    int l_l = left(left(index));
    int l_r = right(left(index));
    int r_l = left(right(index));
    int r_r = right(right(index));
    if ((l_l <= heap_size) && arr[l_l-1] < arr[index-1]) {
        smallest = l_l;
    } else {
        smallest = index;
    }
    if ((l_r <= heap_size) && arr[l_r-1] < arr[smallest-1]) {
        smallest = l_r;
    }
    if ((r_l <= heap_size) && arr[r_l-1] < arr[smallest-1]) {
        smallest = r_l;
    }
    if ((r_r <= heap_size) && arr[r_r-1] < arr[smallest-1]) {
        smallest = r_r;
    }
    return smallest;
}


/**
 * return the index of the largest value from a vertice and its grandsons
 * param *arr - the array
 * param index - the index of the vertice
 * param heap_size - the size of the heap
 */
int find_largest_value_index_grandsons(int* arr, int index, int heap_size)
{
    int largest;
    int l_l = left(left(index));
    int l_r = right(left(index));
    int r_l = left(right(index));
    int r_r = right(right(index));
    if ((l_l <= heap_size) && arr[l_l-1] > arr[index-1]) {
        largest = l_l;
    } else {
        largest = index;
    }
    if ((l_r <= heap_size) && arr[l_r-1] > arr[largest-1]) {
        largest = l_r;
    }
    if ((r_l <= heap_size) && arr[r_l-1] > arr[largest-1]) {
        largest = r_l;
    }
    if ((r_r <= heap_size) && arr[r_r-1] > arr[largest-1]) {
        largest = r_r;
    }
    return largest;
}