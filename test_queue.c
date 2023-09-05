#include <stdio.h>
#include "queue.h"

int main(void)
{
    struct Queue *queue = create_queue(10);
    
    for (int i = 0; i < 20; i++)
    {
        push(queue, i);
        print_queue(queue);
    }

    return 0;
}