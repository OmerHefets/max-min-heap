#include <stdio.h>
#include "heap.h"

int check_heap_boundaries(int index, int heap_size)
{
    if (index > heap_size || index < 1) {
        printf("Index out of bound. try again.\n");
        return 0;
    }
    return 1;
}

int odd_or_even_depth(int index)
{
    int depth = EVEN_DEPTH;
    int min_bound = 1, max_bound = 1;
    int multiplier = 2;
    while (index < min_bound || index > max_bound) {
        min_bound = max_bound;
        max_bound += multiplier;
        multiplier *= 2;
        depth = !depth;
    }
    return depth;
}

void swap(int* arr, int index_a, int index_b)
{
    int temp;
    temp = arr[index_a-1];
    arr[index_a-1] = arr[index_b-1];
    arr[index_b-1] = temp;
}


int parent(int index)
{
    int val;
    val = (index / 2);
    return val;
}

int left(int index)
{
    return (2 * index);
}

int right(int index)
{
    return (2 * index) + 1;
}

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
    if ((r <= heap_size) && arr[r-1] > arr[index-1]) {
        largest = r;
    }
    return largest;
}

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