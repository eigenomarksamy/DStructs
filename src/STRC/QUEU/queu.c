/*
 * queu.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */


#include "queu.h"

void QUAR_main(void) {
    printf("\n----------------------\n");
    printf("QUEUE Testing:\n\n");
    queue_t * queue = QUAR_CreateQueue(100);
    for (int i = 0; i <= 10; i++)
        QUAR_Enqueue(queue, i*2);
    printf("Front: %d\n", QUAR_GetFront(queue));
    printf("Rear: %d\n", QUAR_GetRear(queue));
    QUAR_PrintQueue(queue);
    (void)QUAR_Dequeue(queue);
    QUAR_PrintQueue(queue);
    printf("Front: %d\n", QUAR_GetFront(queue));
    printf("Rear: %d\n", QUAR_GetRear(queue));
}
