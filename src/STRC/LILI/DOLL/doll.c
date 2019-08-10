/*
 * doll.c
 *
 *  Created on: Aug 10, 2019
 *      Author: oks
 */

#include "doll.h"

void DOLL_PrintList(dnode_t * node) {
    bool is_circular;
    is_circular = (SILL_IsCircular(node) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(&node);
    }
    dnode_t * last;
    printf("Forward Direction: ");
    while (node->next != NULL) {
        printf("%d, ", node->val);
        last = node;
        node = node->next;
    }
    printf("%d\n", node->val);
    printf("Reverse Direction: ");
    while (last->prev != NULL) {
        printf("%d, ", last->val);
        last = last->prev;
    }
    printf("%d\n", last->val);
    if (is_circular) {
        DOLL_ConvertLineToCirc(&node);
    }
}

//dnode_t * DOLL_InitLlist(int) {
//
//}
//
//void DOLL_DeleteLlist(dnode_t **) {
//
//}
//
//int DOLL_GetLength(dnode_t *) {
//
//}
//doll_t DOLL_GetType(dnode_t *) {
//
//}
//
//void DOLL_PushBwd(dnode_t *, int) {
//
//}
//
//void DOLL_PushFwd(dnode_t **, int) {
//
//}
//
//int DOLL_PushIdx(dnode_t **, int, int) {
//
//}
//
//int DOLL_PopHead(dnode_t **) {
//
//}
//
//int DOLL_PopLast(dnode_t *) {
//
//}
//
//int DOLL_PopIdx(dnode_t **, int) {
//
//}
//
//int DOLL_PopVal(dnode_t **, int) {
//
//}
//
//int DOLL_SwapLL(dnode_t **, int, int) {
//
//}
//
//bool DOLL_IsCircular(dnode_t *) {
//
//}
//
//void DOLL_ConvertCircToLine(dnode_t **) {
//
//}
//
//void DOLL_ConvertLineToCirc(dnode_t **) {
//
//}
