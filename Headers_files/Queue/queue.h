#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Queue Queue;

Queue *queueCreate(size_t element_size);
void queueDelete(Queue *queue);
bool queueEnqueue(Queue *queue, const void *element);
bool queueDequeue(Queue *queue);
bool queuePeek(const Queue *queue, void *element);
bool queueIsEmpty(const Queue *queue);

#endif 