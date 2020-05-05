/**
 * This module hold all the input-output functions for the heap. Mainly the user interface, and reading and printing the heap.
 * This module works mainly with the routines modules.
 */

#include <stdlib.h>
#include "heap.h"

/**
 * a function asking the user to proceed or exit the program
 * param *arr - the heap 
 * param *heap_size - pointer to the heap size
 */
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

/**
 * a function that reads the heap value in two possible ways from the user, and implements the BUILD-HEAP routine on it.
 * param *arr - the heap 
 * param *heap_size - pointer to the heap size
 */
void read_heap(int* arr, int* heap_size)
{
    int command_number;
    char filename[FILENAME_SIZE];
    printf("Enter 1 to insert heap values by yourself, or 2 to read the values from an existing file: ");
    scanf("%d", &command_number);
    printf("Format for both manually writing the values and by file is a whitespace between each value, and -1 to end the program.\n");
    printf("For example, for a heap with values: 10, 5, 4, 30, 1. Enter: 10 5 4 30 1 -1\n");
    /* for each case, read the heap values and build a heap with the BUILD-HEAP routine */
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

/**
 * reading heap values from file
 * param *file_name - string that holds the filename
 * param *arr - the heap 
 * param *heap_size - pointer to the heap size
 */
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

/**
 * reading heap values from the user directly.
 * param *arr - the heap 
 * param *heap_size - pointer to the heap size
 */
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

/**
 * printing the heap value 
 * param *arr - the heap 
 * param heap_size - the heap size
 */
void print_heap(int* arr, int heap_size)
{
    int i;
    /* since heap values start from 0, we need a specific case if the heap is empty */
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


/**
 * the main function that interacts with the users. asks for a command and implements it with a specific routine
 * param *arr - the heap 
 * param *heap_size - pointer to the heap size
 */
void get_commands_and_execute(int* arr, int* heap_size)
{
    int command_number, user_input, routine_output;
    printf("The optional commands are: HEAP-EXTRACT-MAX (1), HEAP-EXTRACT-MIN (2)\n");
    printf("HEAP-INSERT (3), HEAP-DELETE (4), PRINT-HEAP (5). EXIT PROGRAM (6) \n");
    printf("Enter the number after a routine to execute it.\n");
    /* reading a command number and executing the following command in routines.c */
    do {
        printf("\nInsert number of command: ");
        scanf("%d", &command_number);
        switch(command_number) {
            case 1:
                routine_output = heap_extract_max(arr, heap_size);
                printf("The maximum value extracted: %d\n", routine_output);
                break;
            case 2:
                routine_output = heap_extract_min(arr, heap_size);
                printf("The minimum value extracted: %d\n", routine_output);
                break;
            case 3:
                printf("Insert the key to be inserted: ");
                scanf("%d", &user_input);
                heap_insert(arr, user_input, heap_size);
                break;
            case 4:
                printf("Insert vertice index to be deleted: ");
                scanf("%d", &user_input);
                heap_delete(arr, user_input, heap_size);
                break;
            case 5:
                print_heap(arr, *heap_size);
                break;
            case 6:
                printf("Exiting the program. Thank you for using it!\n");
                break;
            default:
                printf("No such command. try again.\n");
        }
    } while (command_number != 6);
}