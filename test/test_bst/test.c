#include "../../binary_search_tree/binary_search_tree.h"

#include <stdio.h>
#include <stdlib.h>

unsigned short fail = 0;

void test_append(BST *bst, const int val);
void test_println_all(BST *bst);
void test_remove(BST *bst, const int val);
void test_remove_rec(BST *bst, const int val);
void test_get_min(BST *bst);

int main(void) {
    BST *bst = bst_init();
    if (!bst) {
        return EXIT_FAILURE;
    }

    test_append(bst, 10);
    test_append(bst, 4);
    test_append(bst, 15);
    test_append(bst, 2);
    test_append(bst, 20);
    test_append(bst, 1);
    test_append(bst, 23);

    test_println_all(bst);

    test_remove(bst, 23);
    test_println_all(bst);

    test_remove_rec(bst, 10);
    test_println_all(bst);

    test_remove_rec(bst, 15);
    test_println_all(bst);

    test_get_min(bst);

    bst_deinit(&bst);

    return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_append(BST *bst, const int val) {
    BST_status status = BST_OK;
    status = bst_append(bst, val);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE APPENDING\nSTATUS: %d\n", status);
        fail = 1;
    }
}

void test_println_all(BST *bst) {
    BST_status status = BST_OK;

    printf("inorder\n");
    status = bst_println_ino(bst);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE PRINTING\nSTATUS: %d\n", status);
        fail = 1;
    }

    printf("postorder\n");
    status = bst_println_pos(bst);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE PRINTING\nSTATUS: %d\n", status);
        fail = 1;
    }

    printf("perorder\n");
    status = bst_println_pre(bst);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE PRINTING\nSTATUS: %d\n", status);
        fail = 1;
    }
}

void test_remove(BST *bst, const int val) {
    BST_status status = BST_OK;
    status = bst_remove(bst, val);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE APPENDING\nSTATUS: %d\n", status);
        fail = 1;
    }
}

void test_remove_rec(BST *bst, const int val) {
    BST_status status = BST_OK;
    status = bst_remove_rec(bst, val);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE APPENDING\nSTATUS: %d\n", status);
        fail = 1;
    }
}

void test_get_min(BST *bst) {
    BST_status status = BST_OK;
    int out = 0;
    status = bst_get_min(bst, &out);

    if (status != BST_OK) {
        fprintf(stderr, "ERROR WHILE APPENDING\nSTATUS: %d\n", status);
        fail = 1;
    }

    printf("min value: %d\n", out);
}
