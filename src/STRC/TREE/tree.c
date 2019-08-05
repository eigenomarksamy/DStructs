/*
 * tree.c
 *
 *  Created on: Aug 5, 2019
 *      Author: oks
 */


#include "tree.h"

#define TEST_NO 10

void BITR_main(void) {
    printf("\n----------------------\n");
    printf("TREE Testing:\n\n");
    int test, c, success;
    test = c = success;
    srand(time(NULL));
    bnode_t * root = NULL;
    while (c++ < TEST_NO)
        BITR_Insert(&root, BITR_New(rand() % 150));
    printf("IN ORDER -> ");
    BITR_In(root);
    printf("\nPRE ORDER -> ");
    BITR_Pre(root);
    printf("\nPOST ORDER -> ");
    BITR_Post(root);
    puts("\n TEST SEARCH: ");
    while (test++ < TEST_NO)
        if (BITR_SearchVal(root, test) > 0) {
            printf("   - %d\n", test);
            success++;
        }
    printf("\n <SUCCESS> = %d <FAILED> = %d\n", success, TEST_NO - success);
    BITR_PrintTree(ALL_TREE, root, NULL, 0);
}
