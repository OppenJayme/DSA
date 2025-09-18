#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct {
    Element Elements[MAX];
    int size;
} List;

void initList(List *L);
void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void deleteFirst(List *L);
void deleteLast(List *L);
int findElem(List L, int data);
void insertSorted(List *L, int data);
void display(List);


int main(){
    List Otin;

    initList(&Otin);

    insertFirst(&Otin, 10);
    display(Otin);
    insertFirst(&Otin, 20);
    display(Otin);
    insertSorted(&Otin, 25);
    display(Otin);
    insertLast(&Otin, 5);
    display(Otin);
    insertLast(&Otin, 1);
    display(Otin);
    deleteFirst(&Otin);
    display(Otin);
    deleteLast(&Otin);
    display(Otin);

    int found = findElem(Otin, 100);
    printf("Found Element: %d.", found);
    return 0;
}

void initList(List *L){
    L->size = 0;
}

void insertFirst(List *L, int data){
    if (L->size < MAX){
        L->size++;
        int i;
        for (i = L->size; i > 0; --i){
            L->Elements[i].data = L->Elements[i - 1].data;
        }
        L->Elements[i].data = data;
    }
}

void insertLast(List *L, int data){
    if (L->size < MAX){
        L->Elements[++(L->size)].data = data;
    }
}

void deleteFirst(List *L){
    if (L->size != 0){
        for (int i = 0; i < L->size; ++i){
            L->Elements[i].data = L->Elements[i + 1].data;
        }
        L->size--;
    }
}

void deleteLast(List *L){
    if (L->size != 0){
        L->size--;
    }
}
void display(List L){
    for (int i = 0; i < L.size; ++i){
        printf("%d", L.Elements[i].data);
        printf("%s", (i < L.size - 1) ? ", " : ".\n");
    }
}

int findElem(List L, int data){
    int i;
    for (i = 0; i < L.size && L.Elements[i].data != data; ++i){}
    return (i != L.size) ? L.Elements[i].data : -1;
}

void insertSorted(List *L, int data){
    if (L->size != MAX){
        L->size++;
        int pos, i;
    for (pos = 0; pos < L->size - 1 && L->Elements[pos].data < data; ++pos){}

    for (i = L->size - 1; i >= pos; --i){
        L->Elements[i + 1].data = L->Elements[i].data;
        }
    L->Elements[pos].data = data;
    }
}
