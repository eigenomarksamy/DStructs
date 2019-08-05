/*
 * bitr.c
 *
 *  Created on: Aug 5, 2019
 *      Author: oks
 */


#include "bitr.h"

#define SPACE 10

static void BITR_PrintComplete(bnode_t *, int);
static int BITR_GetLevel(bnode_t *);
static void BITR_PrintLevel(bnode_t *, int);

static void BITR_PrintComplete(bnode_t * root, int spacing) {
     if (root == NULL)
          return;
     spacing += SPACE;
     BITR_PrintComplete(root->right, spacing);
     printf("\n");
     for (int i = SPACE; i < spacing; i++)
         printf(" ");
     printf("%d\n", root->val);
     BITR_PrintComplete(root->left, spacing);
}

static int BITR_GetLevel(bnode_t * node) {
    int retval = -1;
    if (node == NULL)
        return 0;
    int left_max = 1 + BITR_GetLevel(node->left);
    int right_max = 1 + BITR_GetLevel(node->right);
    retval = (left_max > right_max) ? left_max : right_max;
    return retval;
}

static void BITR_PrintLevel(bnode_t * node, int level) {
    if (node != NULL && level == 0)
        printf("%d\n", node->val);
    else if (node != NULL) {
        BITR_PrintLevel(node->left, level - 1);
        BITR_PrintLevel(node->right, level - 1);
    }
}

void BITR_PrintTree(enum To_Print to_print, bnode_t * root, bnode_t * node, int value) {
    int level;
    switch(to_print) {
    case VALUE:
        printf("The Value is: %d\n", value);
    break;
    case ALL_TREE:
        BITR_PrintComplete(root, 0);
    break;
    case TO_LEVEL:
        level = BITR_GetLevel(node);
        for (int i = 0; i < level; i++)
            BITR_PrintLevel(node, i);
    break;
    default:
    break;
    }
}

void BITR_In(bnode_t * node) {
    if (node->left)
        BITR_In(node->left);
    BITR_PrintTree(VALUE, NULL, NULL, node->val);
    if (node->right)
        BITR_In(node->right);
}

void BITR_Pre(bnode_t * node) {
    BITR_PrintTree(VALUE, NULL, NULL, node->val);
    if (node->left)
        BITR_Pre(node->left);
    if (node->right)
        BITR_Pre(node->right);
}

void BITR_Post(bnode_t * node) {
    if (node->left)
        BITR_Pre(node->left);
    if (node->right)
        BITR_Pre(node->right);
    BITR_PrintTree(VALUE, NULL, NULL, node->val);
}

bnode_t * BITR_New(int value) {
    bnode_t * node = malloc(sizeof(bnode_t));
    node->val = value;
    node->left = node->right = NULL;
    return node;
}
void BITR_Insert(bnode_t ** root, bnode_t * child) {
    if (!*root) *root = child;
    else BITR_Insert(child->val <= (*root)->val ? &(*root)->left : &(*root)->right, child);
    /*
    		that is ->

    		else if(child->value <= (*root)->value)
    			insert(&(*root)->l, child); 	  // child value is minor/equal to current node call insertion on left node

    		else
    			insert(&(*root)->r, child); 	  // call insertion on right node
    	*/
}

bnode_t * BITR_SearchVal(bnode_t * root, int value) {
    return !root ? NULL : root->val == value ? root : BITR_SearchVal(value > root->val ? root->right : root->left, value);
    /*
		that is -->
		if(root == NULL)
			return NULL;  		         // node not found
		else if (root->value == value)
			return root; 		         // first node address found

		else if(value > root->value)
			search(root->r,value);	     // resursive search on right side of tree
		else
			search(root->l,value);       // resursive search on left side of tree
    */
}

void BITR_SearchPointer(bnode_t * root, int value, bnode_t ** saved) {
    *saved = BITR_SearchVal(root, value);
}
