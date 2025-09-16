#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100


typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack *s, int data);
void pop(Stack *s);
void display(Stack s);
void transferStack(Stack *s, Stack *s1);

int main(){

    Stack s1;
    Stack s2;

    initStack(&s1);
    initStack(&s2);

    push(&s1, 3);
    display(s1);
    push(&s1, 5);
    display(s1);
    push(&s1,10);
    push(&s1, 20);
    display(s1);

    pop(&s1);
    display(s1);


    transferStack(&s1, &s2);
    printf("Stack 1: ");
    display(s1);
    printf("Stack 2: ");
    display(s2);



    return 0;
}

void initStack(Stack *s){
    s->top = -1;
}

bool isEmpty(Stack s){
    return (s.top == -1) ? true : false;
}
bool isFull(Stack s){
    return (s.top == MAX - 1) ? true : false;
}

void push(Stack *s, int data){
    if (!isFull(*s)){
        s->data[++(s->top)] = data;
    } 
}
void pop(Stack *s){
    if (!isEmpty(*s)){
        s->top--;
    } else {
        printf("Empty na!\n");
    }
}

int top (Stack s){
    return (!isEmpty(s)) ? s.data[s.top] : -1;
}

void display(Stack s){
    if (isEmpty(s)){
        printf("Empty!\n");
    }
    while (!isEmpty(s)){
        int taas = top(s);
        printf("%d", taas);
        pop(&s);
        printf("%s", (!isEmpty(s)) ? ", " : ".\n");
    }
}

void transferStack(Stack *s1, Stack *s2){
    if (isEmpty(*s1)){
        printf("Stack 1 is empty!\n");
    } 
    if (isFull(*s2)){
        printf("Stack 2 is Full!\n");
    }

    while (!isEmpty(*s1) && !isFull(*s2)){ // insert stack 1 to stack 2;
        int taas = top(*s1);
        s2->data[++s2->top] = taas;
        pop(&(*s1));
    }
}