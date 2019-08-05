/*
 * sll.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */

#include "sill.h"

void SILL_PrintList(node_t * head) {
    node_t * current = head;
    while (current->next != NULL) {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("%d", current->val);
    printf("\n");
}

node_t * SILL_InitLlist(int init_val) {
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    head->val = init_val;
    head->next = NULL;
    return head;
}

void SILL_DeleteLlist(node_t ** head) {
    node_t * current = *head;
    node_t * next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int SILL_GetLength(node_t * head) {
    int count = 0;
    node_t * current = head;
    while (current->next != NULL) {
        count++;
        current = current -> next;
    }
    return count;
}

void SILL_PushBwd(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void SILL_PushFwd(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int SILL_PushIdx(node_t ** head, int idx, int val) {
    int i;
    node_t * new_node;
    node_t * current = *head;
    new_node = malloc(sizeof(node_t));
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
    return 1;
}

int SILL_PopHead(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;
    if (*head == NULL) {
        return -1;
    }
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    return retval;
}

int SILL_PopLast(node_t * head) {
    int retval = 0;
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

int SILL_PopIdx(node_t ** head, int idx) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;
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
    return retval;
}

int SILL_PopVal(node_t ** head, int val) {
    int retval = -1;
    node_t * current = *head;
    node_t * prev = NULL;
    node_t * temp_node = NULL;
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
    return retval;
}

int SLL_SwapLl(node_t ** head, int idx_1, int idx_2) {
    int retval = 1;
    int val;
    int idx_lo, idx_hi;
    idx_lo = (idx_1 > idx_2) ? idx_1 : idx_2;
    idx_hi = (idx_1 < idx_2) ? idx_1 : idx_2;
    val = SILL_PopIdx(head, idx_lo);
    (void)SILL_PushIdx(head, idx_hi, val);
    val = SILL_PopIdx(head, idx_hi);
    (void)SILL_PushIdx(head, idx_lo-1, val);
    return retval;
}

