#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 8

typedef struct node{
    char data[MAX];
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Queue is a structure containing front and rear pointers to dynamically allocated node/s

int main(){
    Queue real;

    return 0;
}

Queue* initQueue(Queue *q){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    if (!Q){
        printf("Error");
    }
    Q->front = Q->rear = NULL;
    return Q;
}

bool isEmpty(Queue *Q){
    return (Q->front == NULL) ? true : false;
}   

void enqueue(Queue *Q, char data){
    Node *newNode = (Node*)malloc(sizeof(struct node));
    if (isEmpty(Q)){
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

void dequeue(Queue *Q){
    if (isEmpty(Q)){
        printf("Empty");
    }
    Node *temp = Q->front;
    Q->front = temp->next;
    if (Q->front == NULL){
        Q->rear = NULL;
    }
    free(temp);
}

char front(Queue *Q){
    char temp = "\0";

    if (!isEmpty(Q)){
        temp = Q->front->data;
    }
    return temp;
}

void deleteData(Queue *Q, char data){
    Node **trav = &Q->front;
    for (; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if (*trav != NULL){
        Node *temp = *trav;
        bool tail = (temp == Q->rear);
        *trav = temp->next;
        free(temp);

        if (tail){
            if (Q->front == NULL){
                Q->rear == NULL;
            } else {
                Node *cur;
                for (cur = Q->front; cur->next; cur = cur->next){}
                Q->rear = cur;
            }
        }
    }
}



