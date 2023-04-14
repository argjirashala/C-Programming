
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void initialize(Queue *queue){
    queue->front=NULL;
    queue->back=NULL;
}

void enqueue(Queue *queue, int value){
    Node *nNode;
    nNode=malloc(sizeof(struct Node));
    if (nNode==NULL) {
        perror("Error: ");
        free (nNode);
        empty(queue);
        exit(EXIT_FAILURE);
    }
    nNode->value=value;
    nNode->next=NULL; 
    if (isEmpty(queue)){
        queue->front=nNode;
        queue->back=nNode;
    }
    else{
        queue->back->next=nNode;
        queue->back=nNode;
    }
}


void dequeue(Queue *queue){
    Node *frontN;
    if (!isEmpty(queue)){
        frontN=queue->front;
        queue->front=frontN->next;
        if (queue->front==NULL){
            queue->back=NULL;
        }
       
        free(frontN);
    }
}


void empty(Queue *queue){
    Node *tempN;
    while (queue->front != NULL){
        tempN=queue->front;
        queue->front=queue->front->next;
        free(tempN);
    }
    queue->back=NULL;
}


bool isEmpty(Queue *queue){
    return queue->front==NULL && queue->back==NULL;
}


int front(Queue *queue){
    if (isEmpty(queue)){
        return -1;
    }
    return queue->front->value;
}


int back(Queue *queue){
    if (isEmpty(queue)){
        return -1;
    }
    return queue->back->value;
}


int length(Queue *queue){
    int mylength = 0;
    Node *currNode=queue->front;
    while (currNode != NULL){
        currNode=currNode->next;
        mylength++;
    }
    return mylength;
}


void display(Queue *queue){
    Node *currNode=queue->front;
    if (isEmpty(queue)){
        printf("The queue is empty!\n");
    }
    else{
        while (currNode != NULL){
            printf("%d -> ", currNode->value);
            currNode=currNode->next;
        }
        printf("nil\n");
    }
}

void deallocate(struct Node *node) {
    free (node);
}