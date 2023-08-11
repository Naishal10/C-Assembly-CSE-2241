/*Naishal Patel*/
#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>


Stack* newStack2(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Stack2* stack2 = (Stack2*)malloc(sizeof(Stack2));
    stack2->length = 0;
    stack2->arrSize = MIN_SIZE;
    stack2->entries = (int*)malloc(stack2->arrSize * sizeof(int));

    stack->vars = stack2;
    stack->push = pushStack2;
    stack->pop = popStack2;
    stack->del = delStack2;

    return stack;
}

void pushStack2(Stack* stack, int data){
    Stack2* stack2 = (Stack2*)stack->vars;
    if(stack2->length == stack2->arrSize){
        stack2->arrSize *= 2;
        stack2->entries = (int*)realloc(stack2->entries, stack2->arrSize * sizeof(int));
    }
    stack2->entries[stack2->length] = data;
    stack2->length++;
}

int popStack2(Stack* stack){
    int data;
    Stack2* stack2 = (Stack2*)stack->vars;
    if(stack2->length == 0){
        return DEFAULT_RESULT;
    }
    data = stack2->entries[stack2->length - 1];
    stack2->length--;
    if(stack2->length <= stack2->arrSize / 4){
        stack2->arrSize /= 2;
        stack2->entries = (int*)realloc(stack2->entries, stack2->arrSize * sizeof(int));
    }
    return data;
}

void delStack2(Stack* stack){
    Stack2* stack2 = (Stack2*)stack->vars;
    free(stack2->entries);
    free(stack2);
    free(stack);
}
