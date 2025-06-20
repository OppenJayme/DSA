#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
} Elements;

typedef struct node {
    Elements elem;
    struct node *next;
} *LinkedList;

void init(LinkedList *List);
void read(LinkedList List);
void insertFirst(LinkedList List);
void insertLast(LinkedList List);

int main(){
    LinkedList List;

    init(&List);
    read(List);
}

void init(LinkedList *List){
    *List = NULL;
}
void read(LinkedList List){
    printf("List: ");
    for (LinkedList curr = List; curr != NULL; curr = curr->next){
        printf("%d%s", curr->elem.data, (curr->next != NULL) ? ", " : ".\n");
    }
    if (List == NULL){
        printf("EMPTY\n");
    }  
}

