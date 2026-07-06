#ifndef FLEXIBLE_ARRAY_MEMBER_H
#define FLEXIBLE_ARRAY_MEMBER_H
#include <stddef.h>

/**
 * @brief Status codes returned by Array List operations.
 */
typedef enum {
    FA_OK,            /* Operation completed succesfully. */
    FA_ERR_WRONG_PTR, /* A NULL or invalid pointer was passed. */
    FA_ERR_RANGE,     /* Index is greater the length. */
    FA_ERR_REALLOC,   /* Internal reallocation failed. */
} FA_status;

/**
 * @brief Dynamic array of ints.
 *
 * @var cap Number of elements that the buffer can hold
 * @var len Number of elements stored
 * @var arr Buffer for elements
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
 *
 * @return Pointer to a heap allocated FlexArr or NULL on failure on cap 0
 */
FlexArr *flex_arr_init(const size_t cap);

/**
 * @brief Frees a FlexArr and its buffer, also set the passed pointer to NULL
 *
 * @param fa Pointer to the Pointer to FlexArr to be freed
 *
 * @return FA_OK on success
 *         FA_ERR_WRONG_PTR on NULL pointer
 */
FA_status flex_arr_deinit(FlexArr **fa);

/**
 * @brief Adds an element to the buffer, resizes if needed
 *
 * @param fa Pointer to the Poinetr to FlexArr since it might resize
 * @param val element to be added
 *
 * @return FA_OK on success
 *         FA_ERR_WRONG_PTR on NULL pointer
 *         FA_ERR_REALLOC on failure while realloc
 */
FA_status flex_arr_push(FlexArr **fa, int val);

/**
 * @brief Removes the last element
 *
 * @param fa Pointer to the Poinetr to FlexArr
 *
 * @return FA_OK on success
 *         FA_ERR_WRONG_PTR on NULL pointer
 */
FA_status flex_arr_pop(FlexArr *fa);

/**
 * @brief Retrieves the element at the ith index
 *
 * @param fa Pointer to FlexArr
 * @param i Index to get the value
 * @param out Pointer to where the result will be stored
 *
 * @return FA_OK on success
 *         FA_ERR_WRONG_PTR on NULL pointer
 *         FA_ERR_RANGE on i out of bounds
 */
FA_status flex_arr_get(const FlexArr *fa, const size_t i, int *out);

/**
 * @brief Prints to stdout the elements of the buffer
 *
 * @param fa Pointer to FlexArr
 *
 * @return FA_OK on success
 *         FA_ERR_WRONG_PTR on NULL pointer
 */
FA_status flex_arr_println(const FlexArr *fa);

/**
 * @brief Gets the number of elements stored in the buffer
 *
 * @param fa Pointer to FlexArr
 *
 * @return Number of elements in buffer
 */
size_t flex_arr_len(const FlexArr *fa);

#endif
