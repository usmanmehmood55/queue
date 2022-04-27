# [Queue](https://github.com/usmanmehmood55/queue)

An implementation of a queue in C. Most of the code is based on implementation found in [this article](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/).

## Usage
The queue is implemented as a structure with the front, rear, size, and an array. The size of array gets assigned dynamically based on the number of elements in the queue.
```c
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
```

## To Do
* Check the code for memory leaks.
* Add more examples of usage in [main.c](main/main.c)