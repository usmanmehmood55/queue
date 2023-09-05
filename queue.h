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

#ifndef QUEUE_H_
#define QUEUE_H_

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
struct Queue *create_queue(uint16_t capacity);

/**
 * @brief Queue is full when size becomes equal to the capacity.
 *
 * @param queue pointer to queue object
 * @return true if queue is full
 */
bool is_full(struct Queue *queue);

/**
 * @brief Queue is empty when size is 0.
 *
 * @param queue pointer to queue object
 * @return true if queue is empty
 */
bool is_empty(struct Queue *queue);

/**
 * @brief Function to add an item to the queue. It changes rear and size.
 *
 * @param queue pointer to queue object
 * @param item item to be added
 */
void enqueue(struct Queue *queue, uint16_t item);

/**
 * @brief Function to push an item to the queue. It changes front and size.
 * 
 * @param queue pointer to queue object
 * @param item item to push into queue
 */
void push(struct Queue *queue, uint16_t item);

/**
 * @brief Function to remove an item from queue. It changes front and size.
 *
 * @param queue pointer to queue object
 * @return uint16_t item removed from queue
 */
uint16_t dequeue(struct Queue *queue);

/**
 * @brief Function to get front of queue
 *
 * @param queue pointer to queue object
 * @return uint16_t front of queue
 */
uint16_t front(struct Queue *queue);

/**
 * @brief Function to get rear of queue
 *
 * @param queue pointer to queue object
 * @return uint16_t rear of queue
 */
uint16_t rear(struct Queue *queue);

/**
 * @brief prints the queue to the console.
 * 
 * @param queue pointer to queue object
 */
void print_queue(struct Queue *queue);

#endif // QUEUE_H_