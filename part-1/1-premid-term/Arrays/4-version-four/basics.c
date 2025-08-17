#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int data;
}  Element;

typedef struct node {
    Element *elements;
    int size;
} *verFour;

void init(verFour *L);
void read(verFour L);
void insert(verFour *L, int data);
void delete(verFour *L, int data);

int main(){
    verFour L;
    
    init(&L);
    insert(&L, 1);
    read(L);
    insert(&L, 12);
    read(L);
    
    delete(&L, 12);
    read(L);
    
    return 0;
}

void init(verFour *L){
    *L = (verFour)malloc(sizeof(struct node));
    (*L)->elements = (Element*)malloc(sizeof(Element) * MAX);
    (*L)->size = 0;
}

void read(verFour L){
    printf("List: ");
    for (int i = 0; i < L->size; ++i){
        printf("%d%s", L->elements[i], (i != L->size-1) ? ", " : ".\n");
    }
    if (L->size == 0){
        printf("Empty!");
    }
}

void insert(verFour *L, int data){
    if ((*L)->size < MAX){
        (*L)->elements[(*L)->size++].data = data;
    }
}

void delete(verFour *L, int data){
    int i = 0;
    for (; i < (*L)->size && (*L)->elements[i].data != data; ++i){}
    for (++i; i < (*L)->size; ++i){
        (*L)->elements[i - 1] = (*L)->elements[i];
    }
    (*L)->size--;
}
