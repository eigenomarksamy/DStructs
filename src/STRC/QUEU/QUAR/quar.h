/*
 * quar.h
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */

#ifndef QUAR_H_
#define QUAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Queue {
	int front;
	int rear;
	int size;
	unsigned int capacity;
	int * array;
} queue_t;

extern void QUAR_PrintQueue(queue_t *);
extern queue_t * QUAR_CreateQueue(unsigned int);
extern int QUAR_IsFull(queue_t *);
extern int QUAR_IsEmpty(queue_t *);
extern void QUAR_Enqueue(queue_t *, int);
extern int QUAR_Dequeue(queue_t *);
extern int QUAR_GetFront(queue_t *);
extern int QUAR_GetRear(queue_t *);

#endif /* QUAR_H_ */
