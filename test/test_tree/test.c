#include "../../binary_search_tree/binary_search_tree.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    PRINT_INORDER,
    PRINT_PREORDER,
    PRINT_POSTORDER,
} PrintCode;

int Fail = 0;

void test_append(BST *bst, int val);
void test_print(BST *bst, PrintCode code);
void test_remove(BST *bst, int val);
void test_get_min(BST *bst);
void test_get_max(BST *bst);

int main(void) {
    BST *bst = bst_init();
    if (!bst) {
        return EXIT_FAILURE;
    }

    test_append(bst, 10);
    test_append(bst, 30);
    test_append(bst, 5);
    test_append(bst, 35);

    test_print(bst, PRINT_INORDER);
    test_print(bst, PRINT_POSTORDER);
    test_print(bst, PRINT_PREORDER);

    test_remove(bst, 30);
    test_remove(bst, 23);
    test_remove(bst, 10);

    test_print(bst, PRINT_INORDER);
    test_print(bst, PRINT_POSTORDER);
    test_print(bst, PRINT_PREORDER);

    test_get_min(bst);
    test_get_max(bst);

    bst_deinit(&bst);

    return Fail ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_append(BST *bst, int val) {
    BST_status s = BST_OK;
    if ((s = bst_append(bst, val)) != BST_OK) {
        fprintf(stderr, "Error status: %d\n", s);
        Fail = 1;
    }
}

void test_print(BST *bst, PrintCode code) {
    BST_status s = BST_OK;

    switch (code) {
        case PRINT_INORDER:
            if ((s = bst_println_ino(bst)) != BST_OK) {
                fprintf(stderr, "Error status: %d\n", s);
                Fail = 1;
            }
            break;

        case PRINT_PREORDER:
            if ((s = bst_println_pre(bst)) != BST_OK) {
                fprintf(stderr, "Error status: %d\n", s);
                Fail = 1;
            }
            break;

        case PRINT_POSTORDER:
            if ((s = bst_println_pos(bst)) != BST_OK) {
                fprintf(stderr, "Error status: %d\n", s);
                Fail = 1;
            }
            break;
    }
}

void test_remove(BST *bst, int val) {
    BST_status s = BST_OK;
    if ((s = bst_remove(bst, val)) != BST_OK) {
        fprintf(stderr, "Error status: %d\n", s);
        Fail = 1;
    }
}

void test_get_min(BST *bst) {
    BST_status s = BST_OK;
    int out = 0;
    if ((s = bst_get_min(bst, &out)) != BST_OK) {
        fprintf(stderr, "Error status: %d\n", s);
        Fail = 1;
    }

    printf("min: %d\n", out);
}

void test_get_max(BST *bst) {
    BST_status s = BST_OK;
    int out = 0;
    if ((s = bst_get_max(bst, &out)) != BST_OK) {
        fprintf(stderr, "Error status: %d\n", s);
        Fail = 1;
    }

    printf("max: %d\n", out);
}
