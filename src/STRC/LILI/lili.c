/*
 * lili.c
 *
 *  Created on: Aug 3, 2019
 *      Author: oks
 */

#include "lili.h"

void SILL_main(void) {
    printf("\n----------------------\n");
    printf("LINKEDLIST Testing:\n\n");
    snode_t * head = NULL;
    int length = 0;
    int is_circular;
    head = SILL_InitLlist(1);
    printf("Initialized List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    SILL_ConvertLineToCirc(&head);
    for (int i = 2; i <= 10; i++)
        SILL_PushBwd(head, i);
    printf("Full        List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    SILL_ConvertCircToLine(&head);
    SILL_PushFwd(&head, 10);
    printf("Pushfwd     List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_PopHead(&head);
    printf("Popfwd      List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    SILL_PushFwd(&head, 0);
    printf("Pushfwd     List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_PopLast(head);
    printf("Poplast     List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_PopIdx(&head, 8);
    printf("Popindex    List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_PopVal(&head, 5);
    printf("Popvalue    List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_PushIdx(&head, 4, 5);
    printf("Pushindex   List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_PushIdx(&head, 7, 8);
    printf("Pushindex   List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_SwapLL(&head, 1, 8);
    printf("Swap        List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    (void)SILL_SwapLL(&head, 1, 8);
    printf("Swap        List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    printf("Singular    List: ");
    SILL_PrintList(head);
    is_circular = SILL_IsCircular(head);
    printf("Circle: %d\n", is_circular);
    printf("Singular    List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    SILL_ConvertLineToCirc(&head);
    is_circular = SILL_IsCircular(head);
    printf("Circle: %d\n", is_circular);
    printf("Circular    List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    SILL_ConvertCircToLine(&head);
    is_circular = SILL_IsCircular(head);
    printf("Circle: %d\n", is_circular);
    printf("Singular    List: ");
    SILL_PrintList(head);
    length = SILL_GetLength(head);
    printf("Length: %d\n", length);
    SILL_DeleteLlist(&head);
}

void DOLL_main(void) {

}
