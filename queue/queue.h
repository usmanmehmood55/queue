/**
 * @file queue.h
 * @author Usman Mehmood (usmanmehmood55@gmail.com)
 * @brief Library for creating and manipulating queues.
 * 
 * ? Source code taken from https://www.geeksforgeeks.org/queue-data-structure/
 * * Added functionality to push and print the queue.
 * TODO: Add functionality to pop the queue.
 * 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _queue_h_
#define _queue_h_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief queue data structure containing a pointer to the data,
 * the front and the back of the queue, and the size of the queue.
 */
struct Queue
{
    uint16_t front, rear, size;
    uint16_t capacity;
    uint16_t *elements;
};

/**
 * @brief Create a queue object, initializes size of queue as 0.
 *
 * @param capacity number of elements in queue
 * @return struct Queue* pointer to queue object
 */
struct Queue *create_queue(uint16_t capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->elements = (uint16_t *)malloc(queue->capacity * sizeof(uint16_t));

    for (int i = 0; i < queue->capacity; i++)
    {
        queue->elements[i] = 0;
    }

    return queue;
}

/**
 * @brief Queue is full when size becomes equal to the capacity.
 *
 * @param queue pointer to queue object
 * @return true if queue is full
 */
bool is_full(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

/**
 * @brief Queue is empty when size is 0.
 *
 * @param queue pointer to queue object
 * @return true if queue is empty
 */
bool is_empty(struct Queue *queue)
{
    return (queue->size == 0);
}

/**
 * @brief Function to add an item to the queue. It changes rear and size.
 *
 * @param queue pointer to queue object
 * @param item item to be added
 */
void enqueue(struct Queue *queue, uint16_t item)
{
    if (is_full(queue))
        return;
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
    queue->size = queue->size + 1;
}

/**
 * @brief Function to push an item to the queue. It changes front and size.
 * 
 * @param queue pointer to queue object
 * @param item item to push into queue
 */
void push(struct Queue *queue, uint16_t item)
{
    // If queue is full, its size cannot be increased.
    if (!is_full(queue))
        queue->size++;

    // Move all elements from front to rear one position ahead.
    for (int i = queue->capacity - 1; i > 0; i--)
        queue->elements[i] = queue->elements[i - 1];

    // Assign the new element at the front.
    queue->elements[0] = item;

    // Set front and rear.
    queue->rear = item;
    queue->front = queue->elements[queue->size];
}

/**
 * @brief Function to remove an item from queue. It changes front and size.
 *
 * @param queue pointer to queue object
 * @return uint16_t item removed from queue
 */
uint16_t dequeue(struct Queue *queue)
{
    // Empty queue can't be dequeued.
    if (is_empty(queue))
        return 0;

    // Store the front item.
    uint16_t item = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

/**
 * @brief Function to get front of queue
 *
 * @param queue pointer to queue object
 * @return uint16_t front of queue
 */
uint16_t front(struct Queue *queue)
{
    if (is_empty(queue))
        return 0;
    return queue->elements[queue->front];
}

/**
 * @brief Function to get rear of queue
 *
 * @param queue pointer to queue object
 * @return uint16_t rear of queue
 */
uint16_t rear(struct Queue *queue)
{
    if (is_empty(queue))
        return 0;
    return queue->elements[queue->rear];
}

/**
 * @brief prints the queue to the console.
 * 
 * @param queue pointer to queue object
 */
void print_queue(struct Queue *queue)
{
    for (int i = 0; i < queue->capacity; i++)
    {
        printf("%d\t", queue->elements[i]);
    }
    printf("\n");
}

#endif // _queue_h_