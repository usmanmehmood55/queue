/**
 * @file    queue.h
 * @author  Usman Mehmood (usmanmehmood55@gmail.com)
 * @brief   Library for creating and manipulating queues.
 * 
 * @version 0.1
 * @date    2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief queue data structure containing a pointer to the data,
 * the front and the back of the queue, and the size of the queue.
 */
typedef struct queue_t
{
    uint16_t   front;
    uint16_t   rear;
    uint16_t   size;
    uint16_t   capacity;
    uint16_t * elements;
} queue_t;

/**
 * @brief Create a queue object, initializes size of queue as 0.
 *
 * @param capacity number of elements in queue
 * @return struct Queue* pointer to queue object
 */
int queue_create(queue_t ** p_queue, uint16_t capacity);

/**
 * @brief Queue is full when size becomes equal to the capacity.
 *
 * @param queue pointer to queue object
 * @return true if queue is full
 */
bool queue_is_full(queue_t * p_queue);

/**
 * @brief Queue is empty when size is 0.
 *
 * @param queue pointer to queue object
 * @return true if queue is empty
 */
bool queue_is_empty(queue_t * p_queue);

/**
 * @brief Function to add an item to the queue. It changes rear and size.
 *
 * @param queue pointer to queue object
 * @param item item to be added
 */
int queue_enqueue(queue_t * p_queue, uint16_t item);

/**
 * @brief Function to remove an item from queue. It changes front and size.
 *
 * @param queue pointer to queue object
 * @return uint16_t item removed from queue
 */
int queue_dequeue(queue_t * p_queue, uint16_t * p_item);

/**
 * @brief Function to get front of queue
 *
 * @param queue pointer to queue object
 * @return uint16_t front of queue
 */
int queue_get_front(queue_t * p_queue, uint16_t * p_item);

/**
 * @brief Function to get rear of queue
 *
 * @param queue pointer to queue object
 * @return uint16_t rear of queue
 */
int queue_get_rear(queue_t * p_queue, uint16_t * p_item);

/**
 * @brief prints the queue to the console.
 * 
 * @param queue pointer to queue object
 */
void queue_print(queue_t * p_queue);

/**
 * @brief Destroys the queue, freeing its memory.
 *
 * @param[in,out] p_queue Pointer to the queue to destroy.
 *
 * @return 0 on success, or a negative error code on failure.
 * @return -ENOMEM on uninitialized buffer
 */
int queue_destroy(queue_t * p_queue);

#endif // QUEUE_H_