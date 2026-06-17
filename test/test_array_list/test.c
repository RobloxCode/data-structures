#include "../../array_list/array_list.h"

#include <stdio.h>
#include <stdlib.h>

unsigned short Failure = 0;

void test_append(ArrList *al, int val);
void test_remove(ArrList *al, size_t i);
void test_print(ArrList *al);
void test_reverse(ArrList *al);
void test_len(ArrList *al);
void test_swap(ArrList *al, size_t i1, size_t i2);
void test_get(ArrList *al, size_t i);

int main(void) {
    ArrList *al = array_list_init(10);
    if (!al) {
        return EXIT_FAILURE;
    }

    for (int i = 1; i <= 10; ++i) {
        test_append(al, i);
    }

    test_print(al);
    test_remove(al, 3);
    test_remove(al, 30);
    test_print(al);
    test_reverse(al);
    test_print(al);
    test_len(al);
    test_swap(al, 0, 1);
    test_print(al);
    test_swap(al, 0, array_list_len(al));
    test_swap(al, 0, array_list_len(al) - 1);
    test_print(al);
    test_get(al, 4);

    array_list_deinit(&al);
    return Failure ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_append(ArrList *al, int val) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_append(al, val);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while appending\n");
        Failure = 1;
    }
}

void test_remove(ArrList *al, size_t i) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_remove(al, i);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while removing item at idx: %zu\nSTATUS: %d\n",
                i, status);
        Failure = 1;
    }
}

void test_print(ArrList *al) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_println(al);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while printing\n");
        Failure = 1;
    }
}

void test_reverse(ArrList *al) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_reverse(al);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while reversing\n");
        Failure = 1;
    }
}

void test_len(ArrList *al) {
    printf("array_list_len(al): %zu\n", array_list_len(al));
    printf("al->length: %zu\n", al->length);
}

void test_swap(ArrList *al, size_t i1, size_t i2) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_swap(al, i1, i2);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while swapping %zu with %zu\n", i1, i2);
        Failure = 1;
    }
}

void test_get(ArrList *al, size_t i) {
    printf("i: %zu, item: %d\n", i, array_list_get(al, i));
}
