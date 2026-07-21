#ifndef STACK_H
#define STACK_H
#include <stddef.h>

/**
 * @brief A dynamically-growable LIFO stack of ints.
 *
 * Backed by a resizable array. Grows its capacity as needed when
 * items are pushed.
 */
typedef struct {
    int *items; /**< Pointer to the underlying dynamically-allocated array. */
    size_t len; /**< Number of elements currently stored. */
    size_t cap; /**< Total allocated capacity of items. */
} Stack;

/**
 * @brief Status codes returned by stack operations.
 */
typedef enum {
    STACK_OK,            /**< Operation completed successfully. */
    STACK_ERR_WRONG_PTR, /**< A NULL or otherwise invalid pointer was passed in.
                          */
    STACK_ERR_REALLOC,   /**< Internal reallocation failed (out of memory). */
    STACK_ERR_EMPTY, /**< Operation requires a non-empty stack, but the stack is
                        empty. */
    STACK_ERR_OVERFLOW, /**< Operation would exceed the maximum supported
                           capacity. */
} Stack_status;

/**
 * @brief Allocate and initialize a new stack.
 *
 * @param init_cap Initial capacity to reserve for the internal array.
 *
 * @return Pointer to a newly heap-allocated Stack, or NULL if allocation fails.
 *         Caller is responsible for releasing the stack with stack_free().
 */
Stack *stack_init(const size_t init_cap);

/**
 * @brief Free a stack and its underlying storage.
 *
 * @param stack Pointer to the Stack pointer to free. On success, *stack is set
 * to NULL.
 *
 * @return STACK_OK on success, STACK_ERR_WRONG_PTR if stack or *stack is NULL.
 */
Stack_status stack_free(Stack **stack);

/**
 * @brief Push a value onto the top of the stack.
 *
 * Grows the internal array (reallocating as needed) if the stack is at
 * capacity.
 *
 * @param stack Stack to push onto.
 * @param item  Value to push.
 *
 * @return STACK_OK on success, STACK_ERR_WRONG_PTR if stack is NULL,
 *         STACK_ERR_REALLOC if growing the internal array fails,
 *         STACK_ERR_OVERFLOW if the stack cannot grow further.
 */
Stack_status stack_push(Stack *stack, const int item);

/**
 * @brief Remove the value at the top of the stack and return it.
 *
 * @param stack Stack to pop from.
 * @param out   Pointer to receive the popped value. Must not be NULL.
 *
 * @return STACK_OK on success, STACK_ERR_WRONG_PTR if stack or out is NULL,
 *         STACK_ERR_EMPTY if the stack has no elements to pop.
 */
Stack_status stack_pop(Stack *stack, int *out);

/**
 * @brief Retrieve the value at the top of the stack without removing it.
 *
 * @param stack Stack to inspect.
 * @param out   Pointer to receive the top value. Must not be NULL.
 *
 * @return STACK_OK on success, STACK_ERR_WRONG_PTR if stack or out is NULL,
 *         STACK_ERR_EMPTY if the stack has no elements.
 */
Stack_status stack_top(const Stack *stack, int *out);

/**
 * @brief Print the contents of the stack, from top to bottom (or bottom
 *        to top, depending on implementation).
 *
 * @param stack Stack to print.
 *
 * @return STACK_OK on success, STACK_ERR_WRONG_PTR if stack is NULL.
 */
Stack_status stack_println(const Stack *stack);

/**
 * @brief Remove all elements from the stack without freeing its storage.
 *
 * After this call, the stack's length is 0 but its capacity is unchanged.
 *
 * @param stack Stack to clear.
 *
 * @return STACK_OK on success, STACK_ERR_WRONG_PTR if stack is NULL.
 */
Stack_status stack_clear(Stack *stack);

/**
 * @brief Get the current number of elements in the stack.
 *
 * @param stack Stack to query.
 *
 * @return Number of elements currently stored.
 */
size_t stack_len(const Stack *stack);

#endif
