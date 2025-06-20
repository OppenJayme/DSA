#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct {
    Element *Elements;
    int size;
} List_three;

void init(List_three *list);
void insert(List_three *list, int data);
void read(List_three list);
void delete(List_three *list, int data);

int main(){
    List_three list;

    init(&list);
    read(list);
    
    insert(&list, 1);
    read(list);
    insert(&list, 2);
    read(list);

    delete(&list, 2);
    read(list);


    return 0;
}

void init(List_three *list){
    list->size = 0;
    list->Elements = (Element*)malloc(sizeof(Element) * MAX);
    list->Elements[0].data = 0;
}

void read(List_three list){
    printf("List: ");
    for (int i = 0; i < list.size; ++i){
        printf("%d%s", list.Elements[i].data, (i != list.size - 1) ? ", " : ".\n");
    }
    if (list.size == 0){
        printf("EMPTY!\n");
    }
}

void insert(List_three *list, int data){
    if (list->size < MAX){
        list->Elements[list->size++].data = data;
    }
}

void delete(List_three *list, int data){
    int i = 0;
    for (; i < list->size && list->Elements[i].data != data; ++i){}
    if (i < list->size){
        for (++i; i < list->size;++i){
            list->Elements[i - 1] = list->Elements[i];
        }
        list->size--;
    }
}


