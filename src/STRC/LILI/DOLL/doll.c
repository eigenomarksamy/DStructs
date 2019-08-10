/*
 * doll.c
 *
 *  Created on: Aug 10, 2019
 *      Author: oks
 */

#include "doll.h"

void DOLL_PrintList(dnode_t * node) {
//    bool is_circular;
//    is_circular = (DOLL_IsCircular(node) == 1) ? 1 : 0;
//    if (is_circular) {
//        DOLL_ConvertCircToLine(&node);
//    }
    dnode_t * last;
    printf("\n");
    printf("Forward Direction: ");
    while (node->next != NULL) {
        printf("%d, ", node->val);
        last = node;
        node = node->next;
    }
    printf("%d\n", node->val);
//    printf("\n");
    printf("Reverse Direction: ");
    printf("%d, ", node->val);
    while (last->prev != NULL) {
        printf("%d, ", last->val);
        last = last->prev;
    }
    printf("%d", last->val);
    printf("\n");
//    if (is_circular) {
//        DOLL_ConvertLineToCirc(&node);
//    }
}

dnode_t * DOLL_InitLlist(int value) {
    dnode_t * new_node = (dnode_t*)malloc(sizeof(dnode_t));
    new_node->val = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void DOLL_DeleteLlist(dnode_t ** head) {
//    bool is_circular;
//    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
//    if (is_circular) {
//        SILL_ConvertCircToLine(head);
//    }
    dnode_t * current = *head;
    dnode_t * next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int DOLL_GetLength(dnode_t * head) {
//    bool is_circular;
//    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
//    if (is_circular) {
//        DOLL_ConvertCircToLine(&head);
//    }
    int count = 0;
    dnode_t * current = head;
    while (current->next != NULL) {
        count++;
        current = current -> next;
    }
//    if (is_circular) {
//        DOLL_ConvertLineToCirc(&head);
//    }
    return count;
}

//doll_t DOLL_GetType(dnode_t * head) {
//    if (DOLL_IsCircular(head) == 1) {
//        return CIRCULAR_D;
//    }
//    else {
//        return LINEAR_D;
//    }
//}

void DOLL_PushBwd(dnode_t * head, int value) {
//    bool is_circular;
//    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
//    if (is_circular) {
//        DOLL_ConvertCircToLine(&head);
//    }
    dnode_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(dnode_t));
    current->next->val = value;
    current->next->next = NULL;
    current->next->prev = current;
//    if (is_circular) {
//        DOLL_ConvertLineToCirc(&head);
//    }
}

void DOLL_PushFwd(dnode_t ** head, int value) {
//    bool is_circular;
//    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
//    if (is_circular) {
//        DOLL_ConvertCircToLine(&head);
//    }
    dnode_t * new_node = (dnode_t*)malloc(sizeof(dnode_t));
    new_node->val = value;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
//    if (is_circular) {
//        DOLL_ConvertLineToCirc(&head);
//    }
}

int DOLL_PushIdx(dnode_t ** head, int idx, int val) {
//    bool is_circular;
//    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
//    if (is_circular) {
//        DOLL_ConvertCircToLine(&head);
//    }
    int i;
    dnode_t * new_node;
    dnode_t * current = *head;
    new_node = malloc(sizeof(dnode_t));
    if (idx == 0) {
        DOLL_PushFwd(head, val);
    }
    if (idx >= DOLL_GetLength(*head)) {
        DOLL_PushBwd(*head, val);
    }
    for (i = 0; i < idx; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    new_node->val = val;
    new_node->next = current->next;
    current->next = new_node;
    new_node->prev = current;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
//    if (is_circular) {
//        DOLL_ConvertLineToCirc(&head);
//    }
    return 1;
}
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
