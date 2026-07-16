#ifndef SLICE_H
#define SLICE_H

#include <stddef.h>

typedef struct {
    int *items;
    size_t len;
} intSlice;

void *slice_make(int *src, size_t srclen, size_t start, size_t end);
void slice_deinit(intSlice **s);
int slice_init(intSlice *s, int *src, size_t srclen, size_t start, size_t end);
void slice_println(intSlice *s);

#endif
