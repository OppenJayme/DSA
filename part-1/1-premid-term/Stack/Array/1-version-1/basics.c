#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s);
bool isEmpty(Stack s);
bool isFull (Stack s);
void push(Stack *s, char data);
void pop(Stack *s, char data);
char peek(Stack s);


int main(){

    Stack s;

    return 0;
}

void initStack(Stack *s){
    s->top = -1;
}
bool isEmpty(Stack s){
    return (s.top == -1) ? true : false;
}

bool isFull(Stack s){
    return (s.top == MAX - 1);
}

void push(Stack *s, char data){
    if (!isFull(*s)){
        s->data[++s->top] = data;
    }
}

void pop(Stack *s, char data){
    if (!isEmpty(*s)){
        s->top--;
    }
}

char peek(Stack s){
    if (!isEmpty(s)){
        return s.data[s.top];
    }
}



