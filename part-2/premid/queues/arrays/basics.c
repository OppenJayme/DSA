#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10


typedef struct {
    int data[MAX];
    int front, rear;
} queue;

void initQueue(queue *q)
void enqueue(queue *q, int data);
bool isFull(queue q);
bool isEmpty(queue q);

int main(){
    queue q;

    initQueue(&q);


    return 0;
}

void initQueue(queue *q){
    q->rear = MAX - 1;
    q->front = 0;
}

bool isEmpty(queue q){
    return ((q.rear + 1) % (MAX) == q.front) ? true : false;
}

bool isFull(queue q){
    return ((q.rear + 1) % (MAX) == q.front) ? true : false;
}
 
void enqueue(queue *q, int data){
    if (!isFull(*q)){
        q->rear = (q->rear + 1) % (MAX); // 
        q->data[q->rear] = data;
    }
}
void dequeue(queue *q){
    if (!isEmpty(*q)){
        q->front = (q->front + 1) % MAX;
    }
}

int front(queue q){
    return (!isEmpty(q)) ? q.data[q.front] : "empty";
}