/*
 * LILI_type.h
 *
 *  Created on: Aug 10, 2019
 *      Author: oks
 */

#ifndef STRC_LILI_LILI_TYPE_H_
#define STRC_LILI_LILI_TYPE_H_

typedef struct snode {
    int val;
    struct snode * next;
} snode_t;

typedef struct dnode {
    int val;
    struct dnode * prev;
    struct dnode * next;
} dnode_t;

typedef enum LinkedList {
    NOT_DEFINED,
    LINEAR_SINGULAR,
    CIRCULAR_SINGULAR,
    LINEAR_DOUBLUAR,
    CIRCULAR_DOUBLUAR
} lili_t;

typedef enum SLinkedList {
    NOT_SINGLE,
    LINEAR_S,
    CIRCULAR_S
} sill_t;

typedef enum DLinkedList {
    NOT_DOUBLE,
    LINEAR_D,
    CIRCULAR_D
} doll_t;

#endif /* STRC_LILI_LILI_TYPE_H_ */
