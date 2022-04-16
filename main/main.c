#include <stdio.h>
#include "queue.h"

void main()
{
    struct Queue *queue = create_queue(10);
    
    for (int i = 0; i < 20; i++)
    {
        push(queue, i);
        print_queue(queue);
    }
}