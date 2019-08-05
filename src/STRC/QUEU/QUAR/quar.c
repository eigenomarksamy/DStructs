/*
 * quar.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */


#include "quar.h"

void QUAR_PrintQueue(queue_t * queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

queue_t * QUAR_CreateQueue(unsigned int capacity) {
    queue_t * queue = (queue_t*)malloc(sizeof(queue_t));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int QUAR_IsFull(queue_t * queue) {
    return (queue->size == queue->capacity);
}

int QUAR_IsEmpty(queue_t * queue) {
    return (queue->size == 0);
}

void QUAR_Enqueue(queue_t * queue, int item) {
    if (QUAR_IsFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int QUAR_Dequeue(queue_t * queue) {
    if (QUAR_IsEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size--;
    return item;
}

int QUAR_GetFront(queue_t * queue) {
    if (QUAR_IsEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int QUAR_GetRear(queue_t * queue) {
    if (QUAR_IsEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
