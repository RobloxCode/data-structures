#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stddef.h>

/**
 * @brief Single node in a linked list
 */
typedef struct Node {
    int val;           /* < Single element */
    struct Node *next; /* < Pointer to the next Node */
} Node;

/**
 * @brief Linked list of ints
 */
typedef struct {
    Node *start; /* < Pointer to the first node (NULL upon initialization) */
    size_t len;  /* < Number of elements in the linked list */
} LinkedList;

typedef enum {
    LL_OK,                   /* < Success */
    LL_ERR_WRONG_PTR,        /* < Invalid or NULL pointer */
    LL_ERR_MALLOC,           /* < Internal malloc failed*/
    LL_ERR_IDX_OUT_OF_RANGE, /* < Index greater than length */
    LL_ERR_OVERFLOW,         /* < Destination length is greater than
                                  linked list length when turning into a c array*/
    LL_ERR_EMPTY,            /* < Empty list */
    LL_ERR_VALUE_NOT_FOUND,  /* < Element not found in list */
} LL_status;

/**
 * @brief Creates a heap allocated LinkedList and sets every field to a
 *        default value
 *
 * @return Pointer to LinkedList
 */
LinkedList *ll_init(void);

/**
 * @brief Frees a LinkedList
 *
 * @param ll double pointer to a LinkedList the pointer to the linked list
 *           is set to NULL
 *
 * @return LL_OK on success
 *         LL_ERR_WRONG_PTR on NULL pointer
 */
LL_status ll_deinit(LinkedList **ll);

/**
 * @brief adds a new element to the list
 *
 * @param ll Pointer to LinkedList
 * @param val new value to be added
 *
 * @return LL_OK on success
 *         LL_ERR_WRONG_PTR on NULL pointer
 *         LL_ERR_MALLOC on internal malloc allocation
 */
LL_status ll_append(LinkedList *ll, const int val);

/**
 * @brief removes an element at a given index
 *
 * @param ll Pointer to LinkedList
 * @param idx position of element to be removed
 *
 * @return LL_OK on success
 *         LL_ERR_WRONG_PTR on NULL pointer
 *         LL_ERR_IDX_OUT_OF_RANGE on index being greater than list length
 */
LL_status ll_remove(LinkedList *ll, const size_t idx);

/**
 * @brief prints elements from the list
 *
 * @param ll Pointer to LinkedList
 *
 * @return LL_OK on success
 *         LL_ERR_WRONG_PTR on NULL pointer
 */
LL_status ll_println(LinkedList *ll);

/**
 * @brief Reverts the elements in the linked list
 *
 * @param ll Pointer to LinkedList
 *
 * @return LL_OK on success
 *         LL_ERR_WRONG_PTR on NULL pointer
 */
LL_status ll_reverse(LinkedList *ll);

/**
 * @brief Retrieves the length of the list
 *
 * @param ll Pointer to LinkedList
 *
 * @return number of elements in the list
 */
size_t ll_len(LinkedList *ll);

/**
 * @brief converts a LinkedList into a c array
 *
 * @param ll Pointer to LinkedList
 * @param dst Pointer where the elements will be stored
 * @param dst_len size of the dst buffer
 *
 * @return LL_OK on success
 * @return LL_ERR_WRONG_PTR on NULL pointer
 * @return LL_ERR_OVERFLOW on dst_len being greater than the list's length
 * @return LL_ERR_EMPTY on NULL start or empty list
 */
LL_status ll_to_arr(const LinkedList *ll, int *dst, const size_t dst_len);

/**
 * @brief Turns a c array into a LinkedList
 *
 * @param arr Pointer to c array
 * @param arr_len number of elements in arr
 *
 * @return Pointer to a heap allocated LinkedList
 */
LinkedList *arr_to_ll(const int *arr, const size_t arr_len);

/**
 * @brief Searches for an element and stores its index
 *
 * @param ll Pointer to LinkedList
 * @param val number to search in the list
 * @param out buffer for the element
 *
 * @return LL_OK on success
 * @return LL_ERR_WRONG_PTR on NULL pointer
 * @return LL_ERR_VALUE_NOT_FOUND on none found element
 */
LL_status ll_search(const LinkedList *ll, const int val, size_t *out);

#endif
