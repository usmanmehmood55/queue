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
 * @param[in,out] p_queue  Pointer to queue object
 * @param[in]     capacity Number of elements in queue
 * 
 * @return 0 on success,
 * @return -EINVAL if buffer_size is 0,
 * @return -ENOMEM if memory allocation failed
 */
int queue_create(queue_t ** p_queue, uint16_t capacity);

/**
 * @brief Checks if the queue is full
 *
 * @param[in] p_queue Pointer to queue object
 * 
 * @return true if queue is full
 */
bool queue_is_full(const queue_t * p_queue);

/**
 * @brief Checks if the queue is empty
 *
 * @param[in] p_queue Pointer to queue object
 * 
 * @return true if queue is empty
 */
bool queue_is_empty(const queue_t * p_queue);

/**
 * @brief Function to add an item to the queue. It changes rear and size.
 *
 * @param[in,out] p_queue Pointer to queue object
 * @param[in]     item    Item to be enqueued
 * 
 * @return 0 on success,
 * @return -EINVAL if queue is full
 * @return -ENOMEM if queue has not been initialized
 */
int queue_enqueue(queue_t * p_queue, uint16_t item);

/**
 * @brief Function to remove an item from queue. It changes front and size.
 *
 * @param[in,out] p_queue Pointer to queue object
 * @param[out]    p_item  Address for item to be dequeued into
 * 
 * @return 0 on success,
 * @return -EINVAL if queue is empty
 * @return -ENOMEM if queue has not been initialized
 */
int queue_dequeue(queue_t * p_queue, uint16_t * p_item);

/**
 * @brief Function to get front of queue
 *
 * @param[in]  p_queue Pointer to queue object
 * @param[out] p_item  Address for front element to be placed into
 * 
 * @return 0 on success,
 * @return -EINVAL if queue is empty
 * @return -ENOMEM if queue has not been initialized
 */
int queue_get_front(const queue_t * p_queue, uint16_t * p_item);

/**
 * @brief Function to get rear of queue
 *
 * @param[in]  p_queue Pointer to queue object
 * @param[out] p_item  Address for rear element to be placed into
 * 
 * @return 0 on success,
 * @return -EINVAL if queue is empty
 * @return -ENOMEM if queue has not been initialized
 */
int queue_get_rear(const queue_t * p_queue, uint16_t * p_item);

/**
 * @brief Prints the queue to the console.
 * 
 * @param p_queue pointer to queue object
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