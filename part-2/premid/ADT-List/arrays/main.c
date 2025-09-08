#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Elements;

typedef struct node{
    Elements *elem;
    int count;
} *elemList;

void init(elemList *A){
    *A = malloc(sizeof(struct node));
    (*A)->count = 0;
    (*A)->elem = (Elements*)malloc(sizeof(Elements) * MAX);
}


int main(){
    elemList A;

    init(&A);



    return 0;
}
