/*
 * doll.h
 *
 *  Created on: Aug 10, 2019
 *      Author: oks
 */

#ifndef STRC_LILI_DOLL_DOLL_H_
#define STRC_LILI_DOLL_DOLL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../LILI_type.h"

extern void DOLL_PrintList(dnode_t *);
extern dnode_t * DOLL_InitLlist(int);
extern void DOLL_DeleteLlist(dnode_t **);
extern int DOLL_GetLength(dnode_t *);
extern doll_t DOLL_GetType(dnode_t *);
extern void DOLL_PushBwd(dnode_t *, int);
extern void DOLL_PushFwd(dnode_t **, int);
extern int DOLL_PushIdx(dnode_t **, int, int);
extern int DOLL_PopHead(dnode_t **);
extern int DOLL_PopLast(dnode_t *);
extern int DOLL_PopIdx(dnode_t **, int);
extern int DOLL_PopVal(dnode_t **, int);
extern int DOLL_SwapLL(dnode_t **, int, int);
extern bool DOLL_IsCircular(dnode_t *);
extern void DOLL_ConvertCircToLine(dnode_t **);
extern void DOLL_ConvertLineToCirc(dnode_t **);

#endif /* STRC_LILI_DOLL_DOLL_H_ */
