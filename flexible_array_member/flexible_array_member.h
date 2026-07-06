#ifndef FLEXIBLE_ARRAY_MEMBER_H
#define FLEXIBLE_ARRAY_MEMBER_H
#include <stddef.h>

/**
 * @brief Status codes returned by Array List operations.
 */
typedef enum {
    FA_OK,
    FA_ERR_WRONG_PTR,
    FA_ERR_RANGE,
    FA_ERR_REALLOC,
} FA_status;

/**
 * @brief Dynamic array of ints.
 *
 * @var cap Number of items that the buffer can hord
 * @var len Number of items stored
 * @var arr Buffer for items
 */
typedef struct {
    size_t cap;
    size_t len;
    int arr[];
} FlexArr;

/**
 * @brief Creates a FlexArr and initializes it
 *
 * @param cap Initial capacity
 * @return Pointer to a heap allocated FlexArr or NULL on failure on cap 0
 */
FlexArr *flex_arr_init(const size_t cap);

FA_status flex_arr_deinit(FlexArr **fa);
FA_status flex_arr_push(FlexArr **fa, int val);
FA_status flex_arr_pop(FlexArr *fa);
FA_status flex_arr_get(const FlexArr *fa, const size_t i, int *out);
FA_status flex_arr_println(const FlexArr *fa);
size_t flex_arr_len(const FlexArr *fa);

#endif
