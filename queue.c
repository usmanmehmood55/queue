/**
 * @file    queue.c
 * @author  Usman Mehmood (usmanmehmood55@gmail.com)
 * @brief   Library for creating and manipulating queues.
 * 
 * @version 0.1
 * @date    2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

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
int queue_create(queue_t ** p_queue, uint16_t capacity)
{
    if (capacity == 0U)
    {
        return -EINVAL;
    }

    (* p_queue) = (queue_t *)malloc(sizeof(queue_t));
    if((* p_queue) == NULL)
    {
        return -ENOMEM;
    }

    (* p_queue)->elements = NULL;
    (* p_queue)->capacity = capacity;
    (* p_queue)->front    = 0U;
    (* p_queue)->size     = 0U;
    (* p_queue)->rear     = capacity - 1U;

    (* p_queue)->elements = (uint16_t *)malloc((* p_queue)->capacity * sizeof(uint16_t));
    if((* p_queue)->elements == NULL)
    {
        free((* p_queue));
        return -ENOMEM;
    }

    (void)memset((* p_queue)->elements, 0, capacity * sizeof(uint16_t));

    return 0;
}

/**
 * @brief Checks if the queue is full
 *
 * @param[in] p_queue Pointer to queue object
 * 
 * @return true if queue is full
 */
bool queue_is_full(const queue_t * p_queue)
{
    return (p_queue != NULL) ? (p_queue->size == p_queue->capacity) : false;
}

/**
 * @brief Checks if the queue is empty
 *
 * @param[in] p_queue Pointer to queue object
 * 
 * @return true if queue is empty
 */
bool queue_is_empty(const queue_t * p_queue)
{
    return (p_queue != NULL) ? (p_queue->size == 0U) : true;
}

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
int queue_enqueue(queue_t * p_queue, uint16_t item)
{
    int err = -EINVAL;

    if (p_queue != NULL)
    {
        if (queue_is_full(p_queue) == false)
        {
            p_queue->rear = (p_queue->rear + 1U) % p_queue->capacity;
            p_queue->elements[p_queue->rear] = item;
            p_queue->size++;
            err = 0;
        }
    }
    else
    {
        err = -ENOMEM;
    }

    return err;
}

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
int queue_dequeue(queue_t * p_queue, uint16_t * p_item)
{
    int err = -EINVAL;

    if (p_queue != NULL)
    {
        if (queue_is_empty(p_queue) == false)
        {
            * p_item = p_queue->elements[p_queue->front];
            p_queue->front = (p_queue->front + 1U) % p_queue->capacity;
            p_queue->size--;
            err = 0;
        }
    }
    else
    {
        err = -ENOMEM;
    }

    return err;
}

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
int queue_get_front(const queue_t * p_queue, uint16_t * p_item)
{
    int err = -EINVAL;

    if (p_queue != NULL)
    {
        if (queue_is_empty(p_queue) == false)
        {
            * p_item = p_queue->elements[p_queue->front];
            err = 0;
        }
    }
    else
    {
        err = -ENOMEM;
    }

    return err;
}

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
int queue_get_rear(const queue_t * p_queue, uint16_t * p_item)
{
    int err = -EINVAL;

    if (p_queue != NULL)
    {
        if (queue_is_empty(p_queue) == false)
        {
            * p_item = p_queue->elements[p_queue->rear];
            err = 0;
        }
    }
    else
    {
        err = -ENOMEM;
    }

    return err;
}

/**
 * @brief Prints the queue to the console.
 * 
 * @param p_queue pointer to queue object
 */
void queue_print(queue_t * p_queue)
{
    if (p_queue != NULL)
    {
        for (uint16_t i = 0U; i < p_queue->capacity; i++)
        {
            (void)printf("%d\t", p_queue->elements[i]);
        }
        (void)printf("\n");
    }
}

/**
 * @brief Destroys the queue, freeing its memory.
 *
 * @param[in,out] p_queue Pointer to the queue to destroy.
 *
 * @return 0 on success, or a negative error code on failure.
 * @return -ENOMEM on uninitialized buffer
 */
int queue_destroy(queue_t * p_queue)
{
    int err = -ENOMEM;

    if (p_queue != NULL)
    {
        free(p_queue->elements);
        p_queue->elements = NULL;
        p_queue->capacity = 0U;
        p_queue->front    = 0U;
        p_queue->rear     = 0U;
        p_queue->size     = 0U;
        err = 0;
    }

    return err;
}