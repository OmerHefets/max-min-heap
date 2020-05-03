#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void user_interface(int* arr, int* heap_size)
{
    int command_number;
    printf("welcome, welcome...............\n");
    printf("Enter 1 to build a new heap or 2 to exit from the program: ");
    scanf("%d", &command_number);
    switch(command_number) {
        case(1):
            read_heap(arr, heap_size);
            break;
        case(2):
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
    char filename[50];
    printf("Enter 1 to insert heap values by yourself, or 2 to read the values from an existing file: ");
    scanf("%d", &command_number);
    printf("Format for both manually writing the values and by file is a whitespace between each value, and -1 to end the program.\n");
    printf("For example, for a heap with values: 10, 5, 4, 30, 1. Enter: 10 5 4 30 1 -1\n");
    switch(command_number) {
        case(1):
            read_array(arr, heap_size);
            printf("Using routine \"BUILD-HEAP\" to transform the array values to a heap. Processing..\n");
            /* build-heap-routine */
            printf("Done.\n");
            get_commands_and_execute();
            break;
        case(2):
            printf("Enter your filename (with suffix), assuming the file is in this folder: ");
            scanf("%s", filename);
            read_file(filename, arr, heap_size);
            printf("Using routine \"BUILD-HEAP\" to transform the array values to a heap. Processing..\n");
            /* build-heap-routine */
            printf("Done.\n");
            get_commands_and_execute();
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
    printf("[");
    for (i=0 ; i < (heap_size - 1) ; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[i]);
}

void get_commands_and_execute()
{
    int command_number, user_input;
    printf("The optional commands are.......................\n");
    do {
        printf("Insert number of command: ");
        scanf("%d", &command_number);
        switch(command_number) {
            case 1:
                printf("Insert vertice index to implement heapify: ");
                scanf("%d", &user_input);
                /* heapify */
                break;
            case 2:
                /* extract-max */
                break;
            case 3:
                /* extract-min */
                break;
            case 4:
                printf("Insert the key to be inserted: ");
                scanf("%d", &user_input);
                /* insert */
                break;
            case 5:
                printf("Insert vertice index to be deleted: ");
                scanf("%d", &user_input);
                /* delete */
                break;
            case 6:
                break;
            default:
                printf("No such command. try again.\n");
        }
    } while (command_number != 6);
}