/*
 * stark.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */


#include "stak.h"

void STAR_main(void) {
    printf("\n----------------------\n");
    printf("STACK Testing:\n\n");
    stack_t * stack = STAR_CreateStack(100);
    int peek_var = -1;
    STAR_Push(stack, 10);
    STAR_Push(stack, 20);
    STAR_Push(stack, 30);
    STAR_PrintStack(stack);
    printf("Pop: %d\n", STAR_Pop(stack));
    STAR_PrintStack(stack);
    printf("Pushing: 40\n");
    STAR_Push(stack, 40);
    STAR_PrintStack(stack);
    peek_var = STAR_Peek(stack);
    printf("Peek: %d\n", peek_var);
    printf("Pushing: 50\n");
    STAR_Push(stack, 50);
    STAR_PrintStack(stack);
}
