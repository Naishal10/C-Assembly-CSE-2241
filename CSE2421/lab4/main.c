/* Naishal Patel :) */

#include <stdio.h>
#include <stdlib.h>

#include "lab4.h"
#include <time.h>


void StackTest(int type){
    Stack* newStack = type == 1 ? newStack1() : newStack2();

    int i, removed, errors;
    errors = 0;

    for(i = 0; i < NUM_ENTRIES; i++){
        newStack->push(newStack, i);
    }

    for(i = 0; i < NUM_ENTRIES; i++){
        removed = newStack->pop(newStack);
        if(removed != NUM_ENTRIES - i - 1){
            printf("Expected %i, removed %i\n", NUM_ENTRIES - i - 1, removed);
            errors++;
        }
    }

    newStack->del(newStack);

    printf("Ended with %i errors\n", errors);
}

void StackTest1(int type){
    Stack* newStack;
    int i, removed, errors;
    clock_t start, end;
    double cpu_time_used;

    newStack = type == 1 ? newStack1() : newStack2();
    errors = 0;

    start = clock();

    for(i = 0; i < NUM_ENTRIES; i++){
        newStack->push(newStack, i);
    }

    for(i = 0; i < NUM_ENTRIES; i++){
        removed = newStack->pop(newStack);
        if(removed != NUM_ENTRIES - i - 1){
          /*  printf("Expected %i, removed %i\n", NUM_ENTRIES - i - 1, removed);*/
            errors++;
        }
    }

    end = clock();

    newStack->del(newStack);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Ended with %i errors\n", errors);
    printf("Time taken: %f seconds\n", cpu_time_used);
}

void QueueTest1(int type){
    Queue* newQueue;
    int i, removed, errors;
    clock_t start, end;
    double cpu_time_used;

    newQueue = type == 1 ? newQueue1() : newQueue2();
    errors = 0;

    start = clock();

    for(i = 0; i < NUM_ENTRIES; i++){
        newQueue->enqueue(newQueue, i);
    }

    for(i = 0; i < NUM_ENTRIES; i++){
        removed = newQueue->dequeue(newQueue);
        if(removed != i){ 
            /* printf("Expected %i, removed %i\n", i, removed); */
            errors++;
        }
    }

    end = clock();

    newQueue->del(newQueue);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Ended with %i errors\n", errors);
    printf("Time taken: %f seconds\n", cpu_time_used);
}



int main(int argc, char *argv[]){
    StackTest1(1);
    StackTest1(2);
    QueueTest1(1);
    QueueTest1(2);
    return 0;
}
