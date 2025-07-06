#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8


typedef struct {
    char data[MAX];
    int front,rear;
} queue;


void initqueue(queue *Q);
void display(queue Q);
bool isEmpty(queue q);
bool isFull(queue q);
void enqueue(queue *q, char data);
void dequeue(queue *q);
char front(queue Q);

int main(){
    queue q;

    printf("%d\n", isEmpty(q));
    enqueue(&q, 'U');
    display(q);


    return 0;
}

void initqueue(queue *Q){
    Q->front = 0;
    Q->rear = MAX - 1;
}
void display(queue Q){
    printf("Queue: ");

    if (isEmpty(Q)){
        printf("Empty!");
    }

    while(!isEmpty(Q)){
        printf("%c", Q.data[Q.front]);
        dequeue(&Q);
        printf("%s", (!isEmpty(Q) ? ", " : ".\n"));
    }
}

char front(queue Q){
    char q = '\0';

    if (!isEmpty(Q)){
        q = Q.data[Q.front];
    }
    return q;
}
void enqueue(queue *q, char data){
    if (!isFull(*q)){
        q->rear = (q->rear + 1) % (MAX);
        q->data[q->rear] = data;
    }
}

void dequeue(queue *q){
    if (!isEmpty(*q)){
        q->front = (q->front + 1) % (MAX);
    }
}

bool isFull(queue q){
    return ((q.rear + 2) % (MAX) == q.front) ? true : false;
}

bool isEmpty(queue q){
    return ((q.rear + 1) % (MAX) == q.front) ? true : false;
}