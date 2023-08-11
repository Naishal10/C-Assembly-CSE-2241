/* Naishal Patel */
#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>

Queue* newQueue1(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    Queue1* queue1 = (Queue1*)malloc(sizeof(Queue1));
    queue1->length = 0;
    queue1->firstNode = NULL;
    queue1->lastNode = NULL;

    queue->vars = queue1;
    queue->enqueue = enqueueQueue1;
    queue->dequeue = dequeueQueue1;
    queue->del = delQueue1;

    return queue;
}

void enqueueQueue1(Queue* queue, int data){
    Queue1* queue1 = (Queue1*)queue->vars;
    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    newNode->data = data;
    newNode->next = NULL;
    if(queue1->lastNode != NULL){
        queue1->lastNode->next = newNode;
    }
    queue1->lastNode = newNode;
    if(queue1->firstNode == NULL){
        queue1->firstNode = newNode;
    }
    queue1->length++;
}

int dequeueQueue1(Queue* queue){
    Queue1* queue1 = (Queue1*)queue->vars;
    LLNode* firstNode;
    int data;

    if(queue1->length == 0){
        return DEFAULT_RESULT;
    }

    firstNode = queue1->firstNode;
    data = firstNode->data;
    queue1->firstNode = firstNode->next;
    if(queue1->firstNode == NULL){
        queue1->lastNode = NULL;
    }
    free(firstNode);
    queue1->length--;
    return data;
}

void delQueue1(Queue* queue){
    Queue1* queue1 = (Queue1*)queue->vars;
    LLNode* current = queue1->firstNode;
    LLNode* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    free(queue1);
    free(queue);
}

