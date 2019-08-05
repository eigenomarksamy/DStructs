/*
 * star.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */


#include "star.h"

void STAR_PrintStack(stack_t * stack) {
    if (!STAR_IsEmpty(stack)) {
        for (int i = stack->top; i >= 0; i--)
            printf("%d ", stack->array[i]);
    }
    printf("\n");
}

stack_t * STAR_CreateStack(unsigned int capacity) {
    stack_t * stack = (stack_t*)malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int STAR_IsFull(stack_t * stack) {
    return (stack->top == stack->capacity - 1);
}

int STAR_IsEmpty(stack_t * stack) {
    return (stack->top == -1);
}

void STAR_Push(stack_t * stack, int item) {
    if (STAR_IsFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int STAR_Pop(stack_t * stack) {
    if (STAR_IsEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int STAR_Peek(stack_t * stack) {
    if (STAR_IsEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
