// #define NDEBUG

#include "../../array_list/array_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned short Failure = 0;

AL_status test_append(ArrList *al, int val);
AL_status test_remove(ArrList *al, size_t i);
AL_status test_print(ArrList *al);
AL_status test_reverse(ArrList *al);
AL_status test_len(ArrList *al);
AL_status test_swap(ArrList *al, size_t i1, size_t i2);
AL_status test_get(ArrList *al, size_t i);

int main(void) {
    ArrList *al = array_list_init(10);
    if (!al) {
        return EXIT_FAILURE;
    }

    for (int i = 1; i <= 10; ++i) {
        assert(test_append(al, i) == ARRAYLIST_OK);
    }

    assert(test_print(al) == ARRAYLIST_OK);
    assert(test_remove(al, 3) == ARRAYLIST_OK);
    // assert(test_remove(al, 30) == ARRAYLIST_OK);
    assert(test_print(al) == ARRAYLIST_OK);
    assert(test_reverse(al) == ARRAYLIST_OK);
    assert(test_print(al) == ARRAYLIST_OK);
    assert(test_len(al) == ARRAYLIST_OK);
    assert(test_swap(al, 0, 1) == ARRAYLIST_OK);
    assert(test_print(al) == ARRAYLIST_OK);
    // assert(test_swap(al, 0, array_list_len(al)) == ARRAYLIST_OK);
    assert(test_swap(al, 0, array_list_len(al) - 1) == ARRAYLIST_OK);
    assert(test_print(al) == ARRAYLIST_OK);
    assert(test_get(al, 4) == ARRAYLIST_OK);
    assert(test_get(al, array_list_len(al) - 1) == ARRAYLIST_OK);
    // assert(test_get(al, 19) == ARRAYLIST_OK);

    assert(array_list_deinit(&al) == ARRAYLIST_OK);

    return Failure ? EXIT_FAILURE : EXIT_SUCCESS;
}

AL_status test_append(ArrList *al, int val) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_append(al, val);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while appending\n");
        Failure = 1;
        return status;
    }

    return status;
}

AL_status test_remove(ArrList *al, size_t i) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_remove(al, i);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while removing item at idx: %zu\nSTATUS: %d\n",
                i, status);
        Failure = 1;
        return status;
    }

    return status;
}

AL_status test_print(ArrList *al) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_println(al);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while printing\n");
        Failure = 1;
        return status;
    }

    return status;
}

AL_status test_reverse(ArrList *al) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_reverse(al);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while reversing\n");
        Failure = 1;
        return status;
    }

    return status;
}

AL_status test_len(ArrList *al) {
    printf("array_list_len(al): %zu\n", array_list_len(al));
    printf("al->length: %zu\n", al->length);
    return ARRAYLIST_OK;
}

AL_status test_swap(ArrList *al, size_t i1, size_t i2) {
    AL_status status = ARRAYLIST_OK;
    status = array_list_swap(al, i1, i2);
    if (status != ARRAYLIST_OK) {
        fprintf(stderr, "Error while swapping %zu with %zu\n", i1, i2);
        Failure = 1;
        return status;
    }

    return status;
}

AL_status test_get(ArrList *al, size_t i) {
    int out = 0;
    AL_status status = ARRAYLIST_OK;
    if ((status = array_list_get(al, i, &out)) != ARRAYLIST_OK) {
        fprintf(stderr, "Error while getting item %zu\n", i);
        Failure = 1;
        return status;
    }
    printf("the value at i: %zu is : %d\n", i, out);

    return status;
}
