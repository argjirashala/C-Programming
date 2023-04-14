
#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;  
} Node;
typedef struct Queue {
    Node *front;  
    Node *back;   
} Queue;

void initialize(Queue *queue);
void enqueue(Queue *queue, int value);
void dequeue(Queue *queue);
void empty(Queue *queue);
bool isEmpty(Queue *queue);
int front(Queue *queue);
int back(Queue *queue);
int length(Queue *queue);
void display(Queue *queue);

#endif




