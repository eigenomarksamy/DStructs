/*
 * sll.h
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */

#ifndef SILL_H__
#define SILL_H_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

extern void SILL_PrintList(node_t *);
extern node_t * SILL_InitLlist(int);
extern void SILL_DeleteLlist(node_t **);
extern int SILL_GetLength(node_t *);
extern void SILL_PushBwd(node_t *, int);
extern void SILL_PushFwd(node_t **, int);
extern int SILL_PushIdx(node_t **, int, int);
extern int SILL_PopHead(node_t **);
extern int SILL_PopLast(node_t *);
extern int SILL_PopIdx(node_t **, int);
extern int SILL_PopVal(node_t **, int);
extern int SLL_SwapLl(node_t **, int, int);

#endif /*SILL_H__H_ */
