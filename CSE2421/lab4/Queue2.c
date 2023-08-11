
#include <stdio.h>
#include "lab4.h"
#include <stdlib.h>

Queue* newQueue2() {
    Queue* queue;
    Queue2* queue2;

    queue = (Queue*)malloc(sizeof(Queue));
    queue2 = (Queue2*)malloc(sizeof(Queue2));
    queue2->length = 0;
    queue2->curFront = 0;
    queue2->arrSize = MIN_SIZE;
    queue2->entries = (int*)malloc(queue2->arrSize * sizeof(int));

    queue->vars = queue2;
    queue->enqueue = enqueueQueue2;
    queue->dequeue = dequeueQueue2;
    queue->del = delQueue2;

    return queue;
}

void enqueueQueue2(Queue* queue, int data) {
    Queue2* queue2;

    queue2 = (Queue2*)queue->vars;
    if(queue2->length == queue2->arrSize) {
        queue2->arrSize *= 2;
        queue2->entries = (int*)realloc(queue2->entries, queue2->arrSize * sizeof(int));
    }
    queue2->entries[(queue2->curFront + queue2->length) % queue2->arrSize] = data;
    queue2->length++;
}

int dequeueQueue2(Queue* queue) {
    Queue2* queue2;
    int data;

    queue2 = (Queue2*)queue->vars;

    if(queue2->length == 0) {
        return DEFAULT_RESULT;
    }

    data = queue2->entries[queue2->curFront];
    queue2->curFront = (queue2->curFront + 1) % queue2->arrSize;
    queue2->length--;

    return data;
}


void delQueue2(Queue* queue) {
    Queue2* queue2;

    queue2 = (Queue2*)queue->vars;
    free(queue2->entries);
    free(queue2);
    free(queue);
}

