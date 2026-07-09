#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>

/**
 * @brief Status codes returned by BST operations
 */
typedef enum {
    BST_OK = 0,                /* < success */
    BST_ERR_WRONG_PTR = 1,     /* < a NULL or invalid pointer has been passed */
    BST_ERR_INIT_NODE = 2,     /* < malloc error when creating a BSTNode */
    BST_ERR_REPEATED_VAL = 3,  /* < an element is already on tree */
    BST_ERR_EMPTY_TREE = 4,    /* < tree doesn't have any elements */
    BST_ERR_VAL_NOT_FOUND = 5, /* < element is not on the tree */
} BST_status;

/**
 * @brief Every Node on a tree
 */
typedef struct BSTNode {
    int val;                     /* < each individual element */
    struct BSTNode *left_child;  /* < Pointer to the left node */
    struct BSTNode *right_child; /* < Pointer to the right node */
} BSTNode;

/**
 * @brief Binary search tree
 */
typedef struct {
    BSTNode *root; /* < root node */
    size_t height; /* < number of the longest path downward */
} BST;

/**
 * Initializes the binary search tree
 */
BST *bst_init(void);

/**
 * Destroys the binary search tree
 * @param bst a double pointer to the BST struct
 */
BST_status bst_deinit(BST **bst);

/**
 * Adds a new node to the tree, it will find where to add it to
 * @param bst a pointer to a BST struct
 * @param val value to be added
 */
BST_status bst_append(BST *bst, const int val);

/**
 * Not implemented yet
 */
BST_status bst_remove(BST *bst, int val);

/*
 * Prints to the console the tree values in preorder
 * Node -> left -> right
 * @param bst a pointer to a BST struct
 */
BST_status bst_println_pre(const BST *bst);

/*
 * Prints to the console the tree values in inorder
 * left -> Node -> right
 * @param bst a pointer to a BST struct
 */
BST_status bst_println_ino(const BST *bst);

/*
 * Prints to the console the tree values in postorder
 * left -> right -> Node
 * @param bst a pointer to a BST struct
 */
BST_status bst_println_pos(const BST *bst);

/*
 * stores the minimun value in the tree in the out variable
 * @param bst a pointer to a BST struct
 * @param out a poointer to the variable where the mininum
 *        value will be stored
 */
BST_status bst_get_min(const BST *bst, int *out);

/*
 * removes a value in the tree using recursion
 * @param bst a pointer to a Bst struct
 * @param val value to be removed
 * @return BST_OK on success, BST_ERR_WRONG_PTR on null bst,
 *         BST_ERR_EMPTY_TREE on null root
 *
 */
BST_status bst_remove_rec(BST *bst, int val);

#endif
