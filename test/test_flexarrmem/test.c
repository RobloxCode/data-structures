#include "../../flexible_array_member/flexible_array_member.h"

#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void test_push(FlexArr **fa, int val);
void test_pop(FlexArr *fa);
void test_get(FlexArr *fa, size_t i);
void test_len(FlexArr *fa);

int main(void) {
    FlexArr *arr = flex_arr_init(2);
    if (!arr) {
        return EXIT_FAILURE;
    }

    test_push(&arr, 10);
    test_push(&arr, 20);
    test_push(&arr, 30);
    test_push(NULL, 40);
    test_push(&arr, 50);
    test_push(&arr, 40);

    flex_arr_println(arr);

    test_pop(arr);
    test_pop(arr);

    flex_arr_println(arr);

    test_get(arr, 0);
    test_get(arr, 34);
    test_get(arr, flex_arr_len(arr) - 1);

    flex_arr_deinit(&arr);

    return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_push(FlexArr **fa, int val) {
    FA_status status = FA_OK;
    if ((status = flex_arr_push(fa, val)) != FA_OK) {
        fprintf(stderr, "ERROR status: %d\n", status);
        fail = 1;
        return;
    }
}

void test_pop(FlexArr *fa) {
    FA_status status = FA_OK;
    if ((status = flex_arr_pop(fa)) != FA_OK) {
        fprintf(stderr, "ERROR status: %d\n", status);
        fail = 1;
        return;
    }
}

void test_get(FlexArr *fa, size_t i) {
    FA_status status = FA_OK;
    int out = 0;

    if ((status = flex_arr_get(fa, i, &out)) != FA_OK) {
        fprintf(stderr, "ERROR status: %d\n", status);
        fail = 1;
        return;
    }

    printf("item at %zu is %d\n", i, out);
}
