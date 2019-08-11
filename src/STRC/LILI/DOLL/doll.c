/*
 * doll.c
 *
 *  Created on: Aug 10, 2019
 *      Author: oks
 */

#include "doll.h"

void DOLL_PrintList(dnode_t * node) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(node) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(&node);
    }
    dnode_t * last;
    printf("\n");
    printf("Forward Direction: ");
    while (node->next != NULL) {
        printf("%d, ", node->val);
        last = node;
        node = node->next;
    }
    printf("%d\n", node->val);
    printf("Reverse Direction: ");
    printf("%d, ", node->val);
    while (last->prev != NULL) {
        printf("%d, ", last->val);
        last = last->prev;
    }
    printf("%d", last->val);
    printf("\n");
    if (is_circular) {
        DOLL_ConvertLineToCirc(&node);
    }
}

dnode_t * DOLL_InitLlist(int value) {
    dnode_t * new_node = (dnode_t*)malloc(sizeof(dnode_t));
    new_node->val = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void DOLL_DeleteLlist(dnode_t ** head) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
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
    bool is_circular;
    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(&head);
    }
    int count = 0;
    dnode_t * current = head;
    while (current->next != NULL) {
        count++;
        current = current -> next;
    }
    if (is_circular) {
        DOLL_ConvertLineToCirc(&head);
    }
    return count+1;
}

doll_t DOLL_GetType(dnode_t * head) {
    if (DOLL_IsCircular(head) == 1) {
        return CIRCULAR_D;
    }
    else {
        return LINEAR_D;
    }
}

void DOLL_PushBwd(dnode_t * head, int value) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(&head);
    }
    dnode_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(dnode_t));
    current->next->val = value;
    current->next->next = NULL;
    current->next->prev = current;
    if (is_circular) {
        DOLL_ConvertLineToCirc(&head);
    }
}

void DOLL_PushFwd(dnode_t ** head, int value) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
    dnode_t * new_node = (dnode_t*)malloc(sizeof(dnode_t));
    new_node->val = value;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
    if (is_circular) {
        DOLL_ConvertLineToCirc(head);
    }
}

int DOLL_PushIdx(dnode_t ** head, int idx, int val) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
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
    if (is_circular) {
        DOLL_ConvertLineToCirc(head);
    }
    return 1;
}

int DOLL_PopHead(dnode_t ** head) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
    int retval = -1;
    dnode_t * next_node = NULL;
    if (*head == NULL) {
        return -1;
    }
    next_node = (*head)->next;
    retval = (*head)->val;
    next_node->prev = NULL;
    free(*head);
    *head = next_node;
    if (is_circular) {
        DOLL_ConvertLineToCirc(head);
    }
    return retval;
}

int DOLL_PopLast(dnode_t * head) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(&head);
    }
    int retval = 0;
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    dnode_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    if (is_circular) {
        DOLL_ConvertLineToCirc(&head);
    }
    return retval;
}

int DOLL_PopIdx(dnode_t ** head, int idx) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
    int i = 0;
    int retval = -1;
    dnode_t * current = *head;
    dnode_t * temp_node = NULL;
    if (idx == 0) {
        return DOLL_PopHead(head);
    }
    for (i = 0; i < idx - 1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    temp_node = current->next;
    if (temp_node->next == NULL)
        return DOLL_PopLast(*head);
    temp_node->next->prev = temp_node->prev;
    temp_node->prev->next = temp_node->next;
    retval = temp_node->val;
    free(temp_node);
    if (is_circular) {
        DOLL_ConvertLineToCirc(head);
    }
    return retval;
}

int DOLL_PopVal(dnode_t ** head, int val) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
    int retval = -1;
    int count = 0;
    dnode_t * current = *head;
    if (val == current->val) {
        return DOLL_PopHead(head);
    }
    while (current->val != val) {
        count++;
        current = current->next;
    }
    if (count < DOLL_GetLength(*head))
        retval = DOLL_PopIdx(head, count);
    if (is_circular) {
        DOLL_ConvertLineToCirc(head);
    }
    return retval;
}

int DOLL_SwapLL(dnode_t ** head, int idx_1, int idx_2) {
    bool is_circular;
    is_circular = (DOLL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        DOLL_ConvertCircToLine(head);
    }
    int retval = 1;
    int val;
    int idx_lo, idx_hi;
    idx_lo = (idx_1 > idx_2) ? idx_1 : idx_2;
    idx_hi = (idx_1 < idx_2) ? idx_1 : idx_2;
    val = DOLL_PopIdx(head, idx_lo);
    (void)DOLL_PushIdx(head, idx_hi, val);
    val = DOLL_PopIdx(head, idx_hi);
    (void)DOLL_PushIdx(head, idx_lo-1, val);
    if (is_circular) {
        DOLL_ConvertLineToCirc(head);
    }
    return retval;
}

bool DOLL_IsCircular(dnode_t * head) {
    bool retval = 0;
    if (head == NULL) {
        retval = 1;
    }
    dnode_t * node = head->next;
    while (node != NULL && node != head) {
        node = node->next;
    }
    if (node == head) {
        retval = 1;
    }
    return retval;
}

void DOLL_ConvertCircToLine(dnode_t ** head) {
    if (!DOLL_IsCircular(*head))
        return;
    dnode_t * temp;
    temp = *head;
    temp->prev = NULL;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void DOLL_ConvertLineToCirc(dnode_t ** head) {
    if (DOLL_IsCircular(*head))
        return;
    dnode_t * rear;
    rear = *head;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    rear->next = *head;
}
