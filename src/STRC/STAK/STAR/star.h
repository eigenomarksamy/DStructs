/*
 * star.h
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */

#ifndef STAR_H_
#define STAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} stack_t;

extern void STAR_PrintStack(stack_t *);
extern stack_t * STAR_CreateStack(unsigned int);
extern int STAR_IsFull(stack_t *);
extern int STAR_IsEmpty(stack_t *);
extern void STAR_Push(stack_t *, int);
extern int STAR_Pop(stack_t *);
extern int STAR_Peek(stack_t *);

#endif /* STAR_H_ */
