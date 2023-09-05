# Queue

An implementation of a queue in C. Most of the code is based on implementation 
found in [this article](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/).

[![Build and Test](https://github.com/usmanmehmood55/queue/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/usmanmehmood55/queue/actions/workflows/build_and_test.yml)
[![codecov](https://codecov.io/github/usmanmehmood55/queue/graph/badge.svg)](https://codecov.io/github/usmanmehmood55/queue) 

## Usage
The queue is implemented as a structure with the front, rear, size, and an array.
The size of array gets assigned dynamically based on the number of elements in 
the queue.

```c
struct Queue
{
    uint16_t front, rear, size;
    uint16_t capacity;
    uint16_t *elements;
};
```