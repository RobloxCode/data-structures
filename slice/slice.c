#include "slice.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *slice_make(int *const src, const size_t srclen, const size_t start,
                 const size_t end) {
    if (start > end || end == start || (end - start) > srclen) {
        return NULL;
    }

    intSlice *s = malloc(sizeof *s);
    if (!s) {
        return NULL;
    }

    s->len = end - start;
    s->items = src + start;

    return s;
}

void slice_deinit(intSlice **s) {
    free(*s);
    *s = NULL;
}

int slice_init(intSlice *s, int *const src, const size_t srclen,
               const size_t start, const size_t end) {
    if (start > end || end == start || (end - start) > srclen) {
        return 1;
    }

    s->len = end - start;
    s->items = src + start;

    return 0;
}

void slice_println(const intSlice *s) {
    for (size_t i = 0; i < s->len; ++i) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
