#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct node {
    Element Elements[MAX];
    int size;
} *Lista;

void init(Lista *list);
void read(Lista list);
void insert(Lista list, int data);
void delete(Lista list, int data);

int main(){
    Lista list;

    init(&list);

    insert(list,1);
    read(list);
    insert(list,2);
    read(list);

    delete(list,2);
    read(list);
    return 0;
}

void init(Lista *list){
    *list = (Lista)malloc(sizeof(struct node));
    (*list)->size = 0;
}

void read(Lista list){
    printf("List: ");
    for (int i = 0; i < list->size; ++i){
        printf("%d%s", list->Elements[i].data, (i != list->size - 1) ? ", " : ".\n");
    }
    if (list->size == 0){
        printf("EMPTY!");
    }
}

void insert(Lista list, int data){
    if (list->size < MAX){
        list->Elements[list->size++].data = data;
    }
}

void delete(Lista list, int data){
    int i = 0;

    for (; i < list->size && list->Elements[i].data != data; ++i){}

    if (i < list->size){
        for (++i; i <= list->size; ++i){
            list->Elements[i - 1] = list->Elements[i];
        }
        list->size--;
    }
}