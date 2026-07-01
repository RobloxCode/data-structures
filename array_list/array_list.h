#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <stddef.h>

/**
 * @brief Status codes returned by ArrList operations.
 */
typedef enum {
    ARRAYLIST_OK,            /**< Operation completed successfully. */
    ARRAYLIST_ERR_WRONG_PTR, /**< A NULL or invalid pointer was passed. */
    ARRAYLIST_ERR_REALLOC, /**< Internal reallocation failed (out of memory). */
    ARRAYLIST_ERR_OVERFLOW, /**< Requested capacity/size would overflow. */
    ARRAYLIST_ERR_SRC_LARGER_THAN_DST, /**< Source list has more elements than
                                          destination can hold. */
    ARRAYLIST_IDX_OUT_OF_RANGE, /**< Provided index is outside [0, length). */
} AL_status;

/**
 * @brief Dynamic array of ints.
 *
 * @var items    Pointer to the underlying heap-allocated buffer.
 * @var length   Number of elements currently stored.
 * @var capacity Number of elements the buffer can hold before it must grow.
 */
typedef struct {
    int *items;
    size_t length;
    size_t capacity;
} ArrList;

/**
 * @brief Allocate and initialize a new ArrList.
 *
 * @param cap Initial capacity to reserve.
 * @return Pointer to the newly allocated ArrList, or NULL on allocation
 * failure.
 */
ArrList *array_list_init(const size_t cap);

/**
 * @brief Append an item to the end of the list, growing capacity if needed.
 *
 * @param al   List to append to.
 * @param item Value to append.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if al is NULL,
 *         ARRAYLIST_ERR_REALLOC if growing the buffer fails.
 */
AL_status array_list_append(ArrList *al, const int item);

/**
 * @brief Free an ArrList and its internal buffer, then set the pointer to NULL.
 *
 * @param al Pointer to the ArrList pointer to deinitialize.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if al or *al is
 * NULL.
 */
AL_status array_list_deinit(ArrList **al);

/**
 * @brief Print the contents of the list, one line, space- or comma-separated.
 *
 * @param al List to print.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if al is NULL.
 */
AL_status array_list_println(const ArrList *al);

/**
 * @brief Reverse the order of elements in the list, in place.
 *
 * @param al List to reverse.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if al is NULL.
 */
AL_status array_list_reverse(ArrList *al);

/**
 * @brief Copy all elements from src into dst.
 *
 * @param src Source list (unmodified).
 * @param dst Destination list; must have enough capacity to hold src's
 * elements.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if src or dst is
 * NULL, ARRAYLIST_ERR_SRC_LARGER_THAN_DST if dst cannot hold all of src's
 * elements.
 */
AL_status array_list_copy(const ArrList *src, ArrList *dst);

/**
 * @brief Remove the element at index i, shifting subsequent elements left.
 *
 * @param al List to modify.
 * @param i  Index of the element to remove.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if al is NULL,
 *         ARRAYLIST_IDX_OUT_OF_RANGE if i >= al->length.
 */
AL_status array_list_remove(ArrList *al, const size_t i);

/**
 * @brief Get the number of elements currently in the list.
 *
 * @param al List to query.
 * @return Current length of the list (0 if al is NULL).
 */
size_t array_list_len(const ArrList *al);

/**
 * @brief Swap the elements at two indices.
 *
 * @param al List to modify.
 * @param i1 First index.
 * @param i2 Second index.
 * @return ARRAYLIST_OK on success, ARRAYLIST_ERR_WRONG_PTR if al is NULL,
 *         ARRAYLIST_IDX_OUT_OF_RANGE if i1 or i2 is out of range.
 */
AL_status array_list_swap(ArrList *al, const size_t i1, const size_t i2);

/**
 * @brief Get the value stored at index i.
 *
 * @param al List to query.
 * @param i  Index to access.
 * @return The value at index i. Note: current signature has no way to signal
 *         an out-of-range error to the caller (see note below).
 */
AL_status array_list_get(ArrList *al, const size_t i, int *out);

#endif
