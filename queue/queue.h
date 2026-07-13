#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>

/**
 * @brief A single node in the queue, holding a value and a pointer
 *        to the next node.
 */
typedef struct QueueNode {
    int val;   /**< Value stored in this node. */
    struct QueueNode
        *next; /**< Pointer to the next node, or NULL if this is the tail. */
} QueueNode;

/**
 * @brief A singly-linked FIFO queue of ints.
 *
 * Elements are pushed onto the queue and popped in the order they
 * were inserted (first-in, first-out).
 */
typedef struct {
    QueueNode *
        start; /**< Pointer to the front node of the queue, or NULL if empty. */
    size_t len; /**< Number of elements currently in the queue. */
} Queue;

/**
 * @brief Allocate and initialize a new, empty queue.
 *
 * @return Pointer to a newly heap-allocated Queue, or NULL if allocation fails.
 * @note Caller is responsible for releasing the queue with queue_deinit().
 */
Queue *queue_init();

/**
 * @brief Free a queue and all of its remaining nodes.
 *
 * @param q Pointer to the Queue pointer to deinitialize. On return, *q is set
 * to NULL.
 */
void queue_deinit(Queue **q);

/**
 * @brief Push a new value onto the back of the queue.
 *
 * @param q   Queue to push onto. Must not be NULL.
 * @param val Value to enqueue.
 */
void queue_push(Queue *q, int val);

/**
 * @brief Remove the value at the front of the queue.
 *
 * @param q Queue to pop from. Must not be NULL.
 *
 * if queue already empty it just returns
 */
void queue_pop(Queue *q);

/**
 * @brief Print the contents of the queue, from front to back.
 *
 * @param q Queue to print. Must not be NULL.
 */
void queue_println(Queue *q);

#endif
