#define MAX_HEAP_SIZE 100

void user_interface(int* arr, int* heap_size);
void read_heap(int* arr, int* heap_size);
void read_array(int* arr, int* heap_size);
void read_file(char* file_name, int* arr, int* heap_size);
void print_heap(int* arr, int heap_size);
void get_commands_and_execute();

int check_heap_boundaries(int index, int heap_size);
int odd_or_even_depth(int index);