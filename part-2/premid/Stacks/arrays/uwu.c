#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int Elem[MAX];
    int top;
} Stack;

// Function prototypes
void initStack(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack *s, int data);
int pop(Stack *s);
int top(Stack s);
void display(Stack s);

int main() {
    Stack S;
    
    initStack(&S);
    push(&S, 30);
    push(&S, 40);
    push(&S, 50);

    display(S);   // should print: 50 40 30

    return 0;
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack s) {
    return (s.top == -1);
}

bool isFull(Stack s) {
    return (s.top == MAX - 1);
}

void push(Stack *s, int data) {
    if (!isFull(*s)) {
        s->Elem[++(s->top)] = data;
    } else {
        printf("Stack overflow!\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(*s)) {
       s->top--;
    }
}
int top(Stack s) {
    if (!isEmpty(s)) {
        return s.Elem[s.top];
    } 
}

void display(Stack S) {
    printf("Stack: \n");
    if (isEmpty(S)){
        printf("Empty!\n");
    }
    
    while (!isEmpty(S)){
        int taas = top(S);
        printf("%d", taas);
        pop(&S);
        printf("%s", (!isEmpty(S) ? ", " : ".\n"));
    }
}
