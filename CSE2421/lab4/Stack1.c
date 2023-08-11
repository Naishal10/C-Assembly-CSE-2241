/*Naishal Patel*/
#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>

Stack* newStack1(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Stack1* stack1 = (Stack1*)malloc(sizeof(Stack1));
    stack1->length = 0;
    stack1->firstNode = NULL;
    stack1->lastNode = NULL;

    stack->vars = stack1;
    stack->push = pushStack1;
    stack->pop = popStack1;
    stack->del = delStack1;

    return stack;
}

void pushStack1(Stack* stack, int data){
    Stack1* stack1 = (Stack1*)stack->vars;
    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    newNode->data = data;
    newNode->next = stack1->firstNode;
    stack1->firstNode = newNode;
    if(stack1->lastNode == NULL){
        stack1->lastNode = newNode;
    }
    stack1->length++;
}

int popStack1(Stack* stack){
    Stack1* stack1 = (Stack1*)stack->vars;
    LLNode* topNode;
    int data;

    if(stack1->length == 0){
        return DEFAULT_RESULT;
    }

    topNode = stack1->firstNode;
    data = topNode->data;
    stack1->firstNode = topNode->next;
    if(stack1->firstNode == NULL){
        stack1->lastNode = NULL;
    }
    free(topNode);
    stack1->length--;
    return data;
}

void delStack1(Stack* stack){
    Stack1* stack1 = (Stack1*)stack->vars;
    LLNode* current = stack1->firstNode;
    LLNode* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    free(stack1);
    free(stack);
}
