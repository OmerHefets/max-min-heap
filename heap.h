#include <math.h>
#define MAX_HEAP_SIZE 100
#define TRUE 1
#define FALSE 0
#define ODD_DEPTH 1
#define EVEN_DEPTH 0

void user_interface(int* arr, int* heap_size);
void read_heap(int* arr, int* heap_size);
void read_array(int* arr, int* heap_size);
void read_file(char* file_name, int* arr, int* heap_size);
void print_heap(int* arr, int heap_size);
void get_commands_and_execute();

int check_heap_boundaries(int index, int heap_size);
int odd_or_even_depth(int index);

void heapify(int* array, int index, int heap_size);


int right(int index);
int left(int index);
int parent(int index);
void swap(int* arr, int index_a, int index_b);
int find_smallest_value_index_sons(int* arr, int index, int heap_size);
int find_largest_value_index_sons(int* arr, int index, int heap_size);
int find_smallest_value_index_grandsons(int* arr, int index, int heap_size);
int find_largest_value_index_grandsons(int* arr, int index, int heap_size);
