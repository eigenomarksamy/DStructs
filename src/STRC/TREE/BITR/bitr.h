/*
 * bitr.h
 *
 *  Created on: Aug 5, 2019
 *      Author: oks
 */

#ifndef BITR_H_
#define BITR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct BNode {
    struct BNode * left;
    struct BNode * right;
    int val;
} bnode_t;

enum To_Print {
    VALUE = 0,
    ALL_TREE,
    TO_LEVEL,
};

extern void BITR_PrintTree(enum To_Print, bnode_t *, bnode_t *, int) ;
extern void BITR_In(bnode_t *);
extern void BITR_Pre(bnode_t *);
extern void BITR_Post(bnode_t *);
extern bnode_t * BITR_New(int);
extern void BITR_Insert(bnode_t **, bnode_t *);
extern bnode_t * BITR_SearchVal(bnode_t *, int);
extern void BITR_SearchPointer(bnode_t *, int, bnode_t **);

#endif /* BITR_H_ */
