#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10


typedef struct {
    int data[MAX];
    int front,rear;
} queue;

void initQueue(queue *q);
bool isEmpty(queue q);
bool isFull(queue q);
void enqueue(queue *q, int data);
void dequeue(queue *q);
int front(queue q);
void display(queue q);
void transferQueue(queue *q1, queue *q2);
void transfer(queue *q1, queue *q2);

int main(){
    queue q;
    queue q1;

    initQueue(&q);
    initQueue(&q1);

    enqueue(&q, 2);
    display(q);
    enqueue(&q, 4);
    display(q);
    enqueue(&q, 8);
    display(q);
    printf("transfering 1 element from q to q2...\n");
    transfer(&q,&q1);
    printf("Stack 1: ");
    display(q);
    printf("Stack 2: ");
    display(q1);
    printf("\n");

    enqueue(&q, 16);
    display(q);

    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);

    transferQueue(&q, &q1);
    printf("Stack 1: ");
    display(q);
    printf("Stack 2: ");
    display(q1);


    return 0;
}

void initQueue(queue *q){
    q->front = 0;
    q->rear = MAX - 1;
}

bool isEmpty(queue q){
    return ((q.rear + 1) % MAX == q.front);
}

bool isFull(queue q){
    return ((q.rear + 2) % MAX == q.front);
}

void enqueue(queue *q, int data){
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

int front(queue q){
    return (!isEmpty(q) ? q.data[q.front] : -1);
}

void display(queue q){
    if (isEmpty(q)){
        printf("Empty!\n");
    }

    while (!isEmpty(q)){
        int top = front(q);
        printf("%d", top);
        dequeue(&q);
        printf("%s", (!isEmpty(q) ? ", " : ".\n"));
    }
}

void transferQueue(queue *q1, queue *q2){ // transfer all of queue 1 to queue 2
    if (isEmpty(*q1)){
        printf("Empty! Stack 1\n");
    }
    if (isFull(*q2)){
        printf("Stack 2 is Full!\n");
    }

    while (!isEmpty(*q1) && !isFull(*q2)){
        enqueue(&(*q2), q1->data[q1->front]);
        dequeue(&(*q1));
    }
}

void transfer(queue *q1, queue *q2){ // transfer 1 from queue 1 to queue 2
    if (isEmpty(*q1)){
        printf("Empty! Stack 1\n");
    }
    if (isFull(*q2)){
        printf("Stack 2 is Full!\n");
    }
    
    enqueue(&(*q2), q1->data[q1->front]);
    dequeue(&(*q1));
}

void enqueueSorted(queue *q, int data){ // ascending
    if (!isFull(*q)){
        if (q->data[front] > data){
            enqueue(&(*q));
        }  else {
            queue temp;
        initQueue(&temp);
        
        while (!isEmpty(*q) && q->data[q->front] < data){
            enqueue(&temp, q->data[front]);
            dequeue(q);
        }
        enqueue(&temp, data);

        while (!isEmpty(*q)){
            enqueue(q, temp.data[front]);
            dequeue(temp);
        }
        *q = temp;
        }
    }
}