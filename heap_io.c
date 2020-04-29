#include <stdio.h>
#include "heap.h"

void print_instruction()
{
    printf("welcome, welcome\n");
    printf("Insert your array, which will become heap:\n");
}

void read_array(int* arr, int* heap_size)
{
    int i, temp;
    for (i=0 ; i < MAX_HEAP_SIZE ; i++) {
        if (scanf("%d", &temp) == 1) {
            (*heap_size)++;
            arr[i] = temp;
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

void user_interface()
{
    int command_number, user_input;
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