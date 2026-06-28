#include "../../linked_list/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void test_append(LinkedList *ll, int val);
void test_remove(LinkedList *ll, size_t i);
void test_reverse(LinkedList *ll);

int main(void) {
    LinkedList *ll = ll_init();
    if (!ll) {
        goto cleanup;
    }

    ll_println(ll);

    test_append(ll, 1);
    test_append(ll, 2);
    test_append(ll, 3);
    test_append(ll, 4);

    ll_println(ll);

    test_remove(ll, 10);
    test_remove(ll, ll_len(ll) - 1);
    test_remove(ll, 0);

    ll_println(ll);

    test_append(ll, 5);
    test_append(ll, 6);
    test_append(ll, 7);

    ll_println(ll);

    test_reverse(ll);

    ll_println(ll);

    int arr[] = {1, 2, 3, 4, 5, 6, 9};

    LinkedList *ll2 = arr_to_ll(arr, sizeof arr / sizeof arr[0]);
    if (!ll2) {
        goto cleanup;
    }

    ll_println(ll2);

cleanup:
    if (ll) {
        ll_deinit(&ll);
    }

    if (ll2) {
        ll_deinit(&ll2);
    }

    return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}

void test_append(LinkedList *ll, int val) {
    LL_status status = LL_OK;

    if ((status = ll_append(ll, val)) != LL_OK) {
        fprintf(stderr, "Error appending status: %d\n", status);
        fail = 1;
        return;
    }
}

void test_remove(LinkedList *ll, size_t i) {
    LL_status status = LL_OK;

    if ((status = ll_remove(ll, i)) != LL_OK) {
        fprintf(stderr, "Error removing status: %d\n", status);
        fail = 1;
        return;
    }
}

void test_reverse(LinkedList *ll) {
    LL_status status = LL_OK;

    if ((status = ll_reverse(ll)) != LL_OK) {
        fprintf(stderr, "Error reversing status: %d\n", status);
        fail = 1;
        return;
    }
}
