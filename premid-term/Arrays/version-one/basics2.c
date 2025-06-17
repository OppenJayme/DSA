#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct {
    Element storage[MAX];
    int count;
} myList;

void read(myList list);
void init(myList *i);
void insert(myList *i, int num);
void delete(myList *list, int num);

int main(){
    myList Numbers;

    init(&Numbers);
    read(Numbers);

    insert(&Numbers, 1);
    read(Numbers);
    insert(&Numbers, 2);
    read(Numbers);

    delete(&Numbers,2);
    read(Numbers);
}

void read(myList list){
    printf("List: ");
    for (int i = 0; i < list.count; ++i){
        printf("%d%s", list.storage[i], (i != list.count - 1) ? ", " : ".\n");
    }
    if (list.count == 0){
        printf("EMPTY!\n");
    }
}


void init(myList *i){
    i->count = 0;
}

void insert(myList *i, int num){
   if (i->count < MAX){
    i->storage[i->count++].data = num;
   }
}

void delete(myList *list, int num){
    int i = 0;

    for (; i <= list->count && list->storage[i].data != num; ++i) {}

    if (i <= list->count){
        for (i++; i <= list->count; ++i){
            list->storage[i - 1] = list->storage[i];
        }
        list->count--;
    }
}
