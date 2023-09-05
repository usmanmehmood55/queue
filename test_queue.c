#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

static void test_create_queue(void)
{
    queue_t *q = NULL;
    assert(queue_create(&q, 0U) == -EINVAL);

    assert(queue_create(&q, 5U) == 0);
    assert(q->capacity == 5U);
    assert(q->front == 0U);
    assert(q->rear == 4U);
    assert(q->size == 0U);
    assert(queue_destroy(q) == 0);
}

static void test_enqueue(void)
{
    queue_t *q = NULL;
    assert(queue_enqueue(q, 1U) == -ENOMEM);

    assert(queue_create(&q, 5U) == 0);

    assert(queue_enqueue(q, 1U) == 0);
    assert(q->size == 1U);

    assert(queue_enqueue(q, 2U) == 0);
    assert(q->size == 2U);

    assert(queue_enqueue(q, 3U) == 0);
    assert(q->size == 3U);

    assert(queue_enqueue(q, 4U) == 0);
    assert(q->size == 4U);

    assert(queue_enqueue(q, 5U) == 0);
    assert(q->size == 5U);

    assert(queue_is_full(q) == true);

    assert(queue_destroy(q) == 0);
}

static void test_dequeue(void)
{
    queue_t *q = NULL;
    uint16_t item;

    assert(queue_dequeue(q, &item) == -ENOMEM);

    assert(queue_create(&q, 5U) == 0);

    assert(queue_is_empty(q) == true);
    assert(queue_dequeue(q, &item) == -EINVAL);

    assert(queue_enqueue(q, 1U) == 0);
    assert(queue_enqueue(q, 2U) == 0);

    assert(queue_dequeue(q, &item) == 0);
    assert(item == 1U);

    assert(queue_dequeue(q, &item) == 0);
    assert(item == 2U);

    assert(queue_is_empty(q) == true);

    assert(queue_destroy(q) == 0);
}

static void test_front_rear(void)
{
    queue_t *q = NULL;
    uint16_t item;
    assert(queue_get_front(q, &item) == -ENOMEM);
    assert(queue_get_rear(q, &item) == -ENOMEM);

    assert(queue_create(&q, 5U) == 0);

    assert(queue_get_front(q, &item) == -EINVAL);
    assert(queue_get_rear(q, &item) == -EINVAL);

    assert(queue_enqueue(q, 1U) == 0);
    assert(queue_get_front(q, &item) == 0);
    assert(item == 1U);
    assert(queue_get_rear(q, &item) == 0);
    assert(item == 1U);

    assert(queue_enqueue(q, 2U) == 0);
    assert(queue_get_front(q, &item) == 0);
    assert(item == 1U);
    assert(queue_get_rear(q, &item) == 0);
    assert(item == 2U);

    assert(queue_destroy(q) == 0);
}

static void test_empty_full(void)
{
    queue_t *q = NULL;
    assert(queue_is_empty(q) == true);
    assert(queue_is_full(q) == false);

    assert(queue_create(&q, 3U) == 0);
    assert(queue_is_empty(q) == true);
    assert(queue_is_full(q) == false);

    assert(queue_enqueue(q, 1U) == 0);
    assert(queue_is_empty(q) == false);
    assert(queue_is_full(q) == false);

    assert(queue_enqueue(q, 2U) == 0);
    assert(queue_is_empty(q) == false);
    assert(queue_is_full(q) == false);

    assert(queue_enqueue(q, 3U) == 0);
    assert(queue_is_empty(q) == false);
    assert(queue_is_full(q) == true);

    assert(queue_destroy(q) == 0);
}

static void test_destroy_queue(void)
{
    queue_t *q = NULL;
    assert(queue_destroy(q) == -ENOMEM);

    assert(queue_create(&q, 3U) == 0);
    assert(queue_enqueue(q, 1U) == 0);
    assert(queue_enqueue(q, 2U) == 0);
    assert(queue_enqueue(q, 3U) == 0);
    assert(queue_destroy(q) == 0);

    assert(q->elements == NULL);
    assert(q->capacity == 0U);
    assert(q->front == 0U);
    assert(q->rear == 0U);
    assert(q->size == 0U);
}

static void test_print_queue(void)
{
    queue_t *q = NULL;
    queue_print(q);

    assert(queue_create(&q, 3U) == 0);
    assert(queue_enqueue(q, 1U) == 0);
    assert(queue_enqueue(q, 2U) == 0);
    assert(queue_enqueue(q, 3U) == 0);
    queue_print(q);

    assert(queue_destroy(q) == 0);
}

int main(void)
{
    test_create_queue();
    test_print_queue();
    test_enqueue();
    test_dequeue();
    test_front_rear();
    test_empty_full();
    test_destroy_queue();
    (void)printf("All tests passed.\n");
    return 0;
}