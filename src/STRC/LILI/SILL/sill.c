/*
 * sll.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */

#include "sill.h"

void SILL_PrintList(snode_t * head) {
    bool is_circular;
    is_circular = (SILL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(&head);
    }
    snode_t * current = head;
    while (current->next != NULL) {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("%d", current->val);
    printf("\n");
    if (is_circular) {
        SILL_ConvertLineToCirc(&head);
    }
}

snode_t * SILL_InitLlist(int init_val) {
    snode_t * head = NULL;
    head = malloc(sizeof(snode_t));
    head->val = init_val;
    head->next = NULL;
    return head;
}

void SILL_DeleteLlist(snode_t ** head) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    snode_t * current = *head;
    snode_t * next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int SILL_GetLength(snode_t * head) {
    bool is_circular;
    is_circular = (SILL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(&head);
    }
    int count = 0;
    snode_t * current = head;
    while (current->next != NULL) {
        count++;
        current = current -> next;
    }
    if (is_circular) {
        SILL_ConvertLineToCirc(&head);
    }
    return count;
}

void SILL_PushBwd(snode_t * head, int val) {
    bool is_circular;
    is_circular = (SILL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(&head);
    }
    snode_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(snode_t));
    current->next->val = val;
    current->next->next = NULL;
    if (is_circular) {
        SILL_ConvertLineToCirc(&head);
    }
}

void SILL_PushFwd(snode_t ** head, int val) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    snode_t * new_node;
    new_node = malloc(sizeof(snode_t));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
    if (is_circular) {
        SILL_ConvertLineToCirc(head);
    }
}

int SILL_PushIdx(snode_t ** head, int idx, int val) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    int i;
    snode_t * new_node;
    snode_t * current = *head;
    new_node = malloc(sizeof(snode_t));
    if (idx == 0) {
        SILL_PushFwd(head, val);
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
    if (is_circular) {
        SILL_ConvertLineToCirc(head);
    }
    return 1;
}

int SILL_PopHead(snode_t ** head) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    int retval = -1;
    snode_t * next_node = NULL;
    if (*head == NULL) {
        return -1;
    }
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    if (is_circular) {
        SILL_ConvertLineToCirc(head);
    }
    return retval;
}

int SILL_PopLast(snode_t * head) {
    bool is_circular;
    is_circular = (SILL_IsCircular(head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(&head);
    }
    int retval = 0;
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    snode_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    if (is_circular) {
        SILL_ConvertLineToCirc(&head);
    }
    return retval;
}

int SILL_PopIdx(snode_t ** head, int idx) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    int i = 0;
    int retval = -1;
    snode_t * current = *head;
    snode_t * temp_node = NULL;
    if (idx == 0) {
        return SILL_PopHead(head);
    }
    for (i = 0; i < idx - 1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    if (is_circular) {
        SILL_ConvertLineToCirc(head);
    }
    return retval;
}

int SILL_PopVal(snode_t ** head, int val) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    int retval = -1;
    snode_t * current = *head;
    snode_t * prev = NULL;
    snode_t * temp_node = NULL;
    if (val == current->val) {
        return SILL_PopHead(head);
    }
    while (current->val != val) {
        if (current->next == NULL) {
            return -1;
        }
        prev = current;
        current = current->next;
    }
    temp_node = prev->next;
    retval = temp_node->val;
    prev->next = temp_node->next;
    free(temp_node);
    if (is_circular) {
        SILL_ConvertLineToCirc(head);
    }
    return retval;
}

int SILL_SwapLL(snode_t ** head, int idx_1, int idx_2) {
    bool is_circular;
    is_circular = (SILL_IsCircular(*head) == 1) ? 1 : 0;
    if (is_circular) {
        SILL_ConvertCircToLine(head);
    }
    int retval = 1;
    int val;
    int idx_lo, idx_hi;
    idx_lo = (idx_1 > idx_2) ? idx_1 : idx_2;
    idx_hi = (idx_1 < idx_2) ? idx_1 : idx_2;
    val = SILL_PopIdx(head, idx_lo);
    (void)SILL_PushIdx(head, idx_hi, val);
    val = SILL_PopIdx(head, idx_hi);
    (void)SILL_PushIdx(head, idx_lo-1, val);
    if (is_circular) {
        SILL_ConvertLineToCirc(head);
    }
    return retval;
}

bool SILL_IsCircular(snode_t * head) {
    bool retval = 0;
    if (head == NULL) {
        retval = 1;
    }
    snode_t * node = head->next;
    while (node != NULL && node != head) {
        node = node->next;
    }
    if (node == head) {
        retval = 1;
    }
    return retval;
}

void SILL_ConvertCircToLine(snode_t ** head) {
    snode_t * temp;
    temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void SILL_ConvertLineToCirc(snode_t ** head) {
    snode_t * rear;
    rear = *head;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    rear->next = *head;
}

sill_t SILL_GetType(snode_t * head) {
    if (SILL_IsCircular(head) == 1) {
        return CIRCULAR_S;
    }
    else {
        return LINEAR_S;
    }
}
