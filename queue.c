//Implement a queue using Array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct queue{
    int *data;
    int size;
    int head;
    int tail;
} queue;

void create_queue(queue **p_q, int size)
{
    *p_q = (queue*)malloc(sizeof(queue));
    (*p_q)->data = (int*)malloc(sizeof(int)*size);
    (*p_q)->size = size;
    (*p_q)->head = 0;
    (*p_q)->tail = -1;
}

void enqueue(queue *q, int new_elem)
{
    if(q->tail == q->size-1){
        q->data = (int*)realloc(q->data, sizeof(int)*q->size*2);
        q->size *= 2;
        // printf("Queue is full");
        // return;
    }
    q->tail++;
    q->data[q->tail] = new_elem;
}

int dequeue(queue *q)
{
    if(q->head > q->tail){
        printf("Queue is empty");
        return -1;
    }
    int elem = q->data[q->head];
    q->head++;

    if ((q->tail - q->head + 1) <= (q->size / 2) && (q->head) > (q->size) / 4) {
        int num_elems = q->tail - q->head + 1;
        memmove(q->data, q->data + q->head, sizeof(int) * num_elems);
        q->tail = num_elems - 1;
        q->head = 0;        
    }

    return elem;
}

int main()
{
    queue *q;
    create_queue(&q, 3);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 6);
    enqueue(q, 6);
    enqueue(q, 6);
    enqueue(q, 6);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
}