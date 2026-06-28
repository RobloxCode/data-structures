#include "../../linked_list/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void test_append(LinkedList *ll, int val);
void test_remove(LinkedList *ll, size_t i);

int main(void) {
    LinkedList *ll = ll_init();
    if (!ll) {
        return EXIT_FAILURE;
    }

    ll_println(ll);

    test_append(ll, 1);
    test_append(ll, 2);
    test_append(ll, 3);
    test_append(ll, 4);

    ll_println(ll);

    test_remove(ll, 10);

    ll_deinit(&ll);

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
