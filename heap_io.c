#include <stdlib.h>
#include "heap.h"

void user_interface(int* arr, int* heap_size)
{
    int command_number;
    printf("Welcome to the max-min-heap program.\n");
    printf("Enter 1 to build a new heap or 2 to exit from the program: ");
    scanf("%d", &command_number);
    switch(command_number) {
        case 1:
            read_heap(arr, heap_size);
            break;
        case 2:
            printf("Exiting the program.\n");
            break;
        default:
            printf("No such command! Exiting the program.");
            break;
    }
}

void read_heap(int* arr, int* heap_size)
{
    int command_number;
    char filename[FILENAME_SIZE];
    printf("Enter 1 to insert heap values by yourself, or 2 to read the values from an existing file: ");
    scanf("%d", &command_number);
    printf("Format for both manually writing the values and by file is a whitespace between each value, and -1 to end the program.\n");
    printf("For example, for a heap with values: 10, 5, 4, 30, 1. Enter: 10 5 4 30 1 -1\n");
    switch(command_number) {
        case 1:
            read_array(arr, heap_size);
            printf("Using routine \"BUILD-HEAP\" to transform the array values to a heap. Processing.. ");
            build_heap(arr, *heap_size);
            printf("Done.\n");
            get_commands_and_execute(arr, heap_size);
            break;
        case 2:
            printf("Enter your filename (with suffix), assuming the file is in this folder: ");
            scanf("%s", filename);
            read_file(filename, arr, heap_size);
            printf("Using routine \"BUILD-HEAP\" to transform the array values to a heap. Processing.. ");
            build_heap(arr, *heap_size);
            printf("Done.\n");
            get_commands_and_execute(arr, heap_size);
            break;
        default:
            printf("No such command! Exiting the program.");
            break;
    }
}

void read_file(char* file_name, int* arr, int* heap_size)
{
    FILE* heap;
    int i, temp = 0;

    heap = fopen(file_name, "r");
    for (i=0 ; i < MAX_HEAP_SIZE ; i++) {
        if ((fscanf(heap, "%d", &temp) == 1) && (temp != -1)) {
            (*heap_size)++;
            arr[i] = temp;         
        } else {
            break;
        }
    }
    fclose(heap);
}

void read_array(int* arr, int* heap_size)
{
    int i, temp=0;
    for (i=0 ; i < MAX_HEAP_SIZE ; i++) {
        if ((scanf("%d", &temp) == 1) && (temp != -1)) {
            (*heap_size)++;
            arr[i] = temp;         
        } else {
            break;
        }
    }
}

void print_heap(int* arr, int heap_size)
{
    int i;
    if (heap_size == 0) {
        printf("[]");
    }
    else {
        printf("[");
        for (i=0 ; i < (heap_size - 1) ; i++) {
            printf("%d, ", arr[i]);
        }
        printf("%d]", arr[i]);
    }
}

void get_commands_and_execute(int* arr, int* heap_size)
{
    int command_number, user_input, routine_output;
    printf("The optional commands are: HEAPIFY (1), HEAP-EXTRACT-MAX (2), HEAP-EXTRACT-MIN (3)\n");
    printf("HEAP-INSERT (4), HEAP-DELETE (5), PRINT-HEAP (6). EXIT PROGRAM (7) \n");
    printf("Enter the number after a routine to execute it.\n");
    do {
        printf("\nInsert number of command: ");
        scanf("%d", &command_number);
        switch(command_number) {
            case 1:
                printf("Insert vertice index to implement heapify: ");
                scanf("%d", &user_input);
                heapify(arr, user_input, *heap_size);
                break;
            case 2:
                routine_output = heap_extract_max(arr, heap_size);
                printf("The maximum value extracted: %d\n", routine_output);
                break;
            case 3:
                routine_output = heap_extract_min(arr, heap_size);
                printf("The minimum value extracted: %d\n", routine_output);
                break;
            case 4:
                printf("Insert the key to be inserted: ");
                scanf("%d", &user_input);
                heap_insert(arr, user_input, heap_size);
                break;
            case 5:
                printf("Insert vertice index to be deleted: ");
                scanf("%d", &user_input);
                heap_delete(arr, user_input, heap_size);
                break;
            case 6:
                print_heap(arr, *heap_size);
                break;
            case 7:
                printf("Exiting the program. Thank you for using it.\n");
                break;
            default:
                printf("No such command. try again.\n");
        }
    } while (command_number != 7);
}