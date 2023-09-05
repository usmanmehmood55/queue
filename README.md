# Queue

An implementation of a queue in C. Most of the code is based on the implementation 
found in [this article](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/).

[![Build and Test](https://github.com/usmanmehmood55/queue/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/usmanmehmood55/queue/actions/workflows/build_and_test.yml)
[![codecov](https://codecov.io/gh/usmanmehmood55/queue/graph/badge.svg?token=XK0MXKCR5N)](https://codecov.io/gh/usmanmehmood55/queue)

## Usage

The queue is implemented as a structure with the front, rear, size, and an array.

```c
typedef struct queue_t
{
    uint16_t   front;
    uint16_t   rear;
    uint16_t   size;
    uint16_t   capacity;
    uint16_t * elements;
} queue_t;
```

The user can enqueue items in it until the capacity is filled. After which old
items must be dequeued to enqueue new ones.

A queue with capacity `5` can be initialized like this.
```c
queue_t *q = NULL;
int err = queue_create(&q, 5U);
if (err != 0)
{
    // error handling
}
```

After use, the queue can be de-initialized like this.
```c
err = queue_destroy(q)
if (err != 0)
{
    // error handling
}
```