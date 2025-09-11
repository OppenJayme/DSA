#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} *nodeType;

typedef struct {
    nodeType top;
} Stack;

// Prototypes
void initStack(Stack *S);
bool isEmpty(Stack s);
void push(Stack *S, int data);
void pop(Stack *S);
void top(Stack s);

int main(){
    Stack S;
    initStack(&S);



    return 0;
}

void initStack(Stack *S){
    S->top = NULL;
}

bool isEmpty(Stack s){
    return (s.top == NULL) ? true : false;
}

void push(Stack *S, int data){
    nodeType newNode = (nodeType)malloc(sizeof(struct node));
    if (newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;
        newNode->next = *S;
        *S = newNode;
    }
}

void pop(Stack *S){
    if (!isEmpty(*S)){
        nodeType temp = *S;
        *S = temp->next;
        free(temp);
    }
}

int top(Stack S){
    return (S != NULL) ? S.top->data : "Empty List"; 
}

void read(Stack *Stack) {
    Stack temp;
    init(&temp);
    printf("Stack: ");

    if(isEmpty(*Stack)) {
        printf("EMPTY");
    }
    
    while(!isEmpty(*Stack)) {
        int d = top(*Stack);
        pop(Stack);
        printf("%d ", d.data);
        push(&temp, d.data);
    }

    while(!isEmpty(temp)) {
        int d = top(temp);
        pop(&temp);
        push(Stack, d.data);
    }

    printf("\n");
}


