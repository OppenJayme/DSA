#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10


typedef struct {
    int data[MAX];
    int front, rear;
} queue;

void initQueue(queue *q);
void enqueue(queue *q, int data);
bool isFull(queue q);
bool isEmpty(queue q);
void enqueue(queue *q, int data);
void dequeue(queue *q);
int front(queue q);
void display(queue q);

int main(){
    queue q;

    initQueue(&q);

    enqueue(&q, 10);
    display(q);
    enqueue(&q, 20);
    display(q);
    enqueue(&q, 30);
    display(q);
    enqueue(&q, 40);
    display(q);

    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);

    return 0;
}

void initQueue(queue *q){ // clock wise traversal.
    q->rear = MAX - 1;
    q->front = 0;
}

bool isEmpty(queue q){
    return ((q.rear + 1) % (MAX) == q.front) ? true : false;
}

bool isFull(queue q){
    return ((q.rear + 2) % (MAX) == q.front) ? true : false;
}
 
void enqueue(queue *q, int data){ // an element is added at rear so its going clockwise, top stays at index 0, rear stays at last index of last element inserted.
    if (!isFull(*q)){
        q->rear = (q->rear + 1) % (MAX); // if first element rear becomes 0, 2nd element  rear becomes 1.
        q->data[q->rear] = data;
    }
}
void dequeue(queue *q){ // basically just goes up in index. BASICALLY q->front++! but this is more speicifc and strict;
    if (!isEmpty(*q)){
        q->front = (q->front + 1) % MAX;
    }
}

int front(queue q){
    return (!isEmpty(q)) ? q.data[q.front] : -1;
}

void display(queue q){
    if (isEmpty(q)){
        printf("queue is Empty!\n");
    }

    while (!isEmpty(q)){
        printf("%d", q.data[q.front]); // prints the front
        dequeue(&q); // since we dequeue the front gets move up to one more index.
        printf("%s", (!isEmpty(q)) ? ", " : ".\n");
    }
}