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
#include "../LILI_type.h"

extern void SILL_PrintList(snode_t *);
extern snode_t * SILL_InitLlist(int);
extern void SILL_DeleteLlist(snode_t **);
extern int SILL_GetLength(snode_t *);
extern sill_t SILL_GetType(snode_t *);
extern void SILL_PushBwd(snode_t *, int);
extern void SILL_PushFwd(snode_t **, int);
extern int SILL_PushIdx(snode_t **, int, int);
extern int SILL_PopHead(snode_t **);
extern int SILL_PopLast(snode_t *);
extern int SILL_PopIdx(snode_t **, int);
extern int SILL_PopVal(snode_t **, int);
extern int SILL_SwapLL(snode_t **, int, int);
extern bool SILL_IsCircular(snode_t *);
extern void SILL_ConvertCircToLine(snode_t **);
extern void SILL_ConvertLineToCirc(snode_t **);

#endif /*SILL_H__H_ */
