#ifndef SLICE_H
#define SLICE_H

#include <stddef.h>

/**
 * @brief A slice into a region of memory
 */
typedef struct {
    int *items; /* < Pointer to the start of the values */
    size_t len; /* < Number of elements following after start*/
} intSlice;

/**
 * @brief Heap Allocates a intSlice and initializes it
 *
 * @param src Pointer to the buffer where the slice will read from
 * @param srclen Number of elements in the src buffer
 * @param start Index where the slice will start pointing at
 * @param end Index where the slice will stop pointing at
 *
 * @return Pointer to heap allocated intSlice
 */
void *slice_make(int *src, size_t srclen, size_t start, size_t end);

/**
 * @brief Frees from memory a heap allocated intSlice
 *
 * @param s Double pointer to a intSlice since it also sets to null
 *          the owner pointer
 */
void slice_deinit(intSlice **s);

/**
 * @brief Sets the fields of a intSlice
 *
 * @param s Pointer to intSlice
 * @param src Pointer to the buffer where the slice will read from
 * @param srclen Number of elements in the src buffer
 * @param start Index where the slice will start pointing at
 * @param end Index where the slice will stop pointing at
 *
 * @return 1 on success
 *         0 on start being greater than end or them being at the same time or
 *         eather the length of the slice being greater than
 *         the length of the src
 */
int slice_init(intSlice *s, int *src, size_t srclen, size_t start, size_t end);

/**
 * @brief Prints the values of a intSlice
 *
 * @param s pointer to intSlice
 */
void slice_println(intSlice *s);

#endif
