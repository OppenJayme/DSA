#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
} Elements;

typedef struct node {
    Elements elem;
    struct node *next;
} *LinkedList;

void init(LinkedList *List);
void read(LinkedList List);
void insertFirst(LinkedList *List, int data);
void insertLast(LinkedList *List,  int data);
void deleteData(LinkedList *A, int data);
int locate(LinkedList A, int data);
bool findElem(LinkedList A, int data);

int main(){
    LinkedList List;

    init(&List);
    read(List);
    insertFirst(&List, 10);
    read(List);
    insertFirst(&List, 120);
    read(List);
    insertLast(&List, 130);
    read(List);
    deleteData(&List, 20);
    read(List);

    printf("%d\n", locate(List, 130));

    bool real = findElem(List, 120);
    printf("1 if found 0 if nah: %d", findElem(List, 10));

    
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

void insertFirst(LinkedList *A, int data){
    LinkedList newNode = (LinkedList)malloc(sizeof(struct node));

    if (newNode == NULL){
        printf("error!");
        exit;
    }
    
    newNode->elem.data = data;
    newNode->next = *A;
    *A = newNode;
}

void insertLast(LinkedList *A, int data){
    LinkedList trav;
    for (trav = *A; trav->next != NULL; trav = trav->next){}
    LinkedList newNode = (LinkedList)malloc(sizeof(struct node));

    if (newNode == NULL){
        printf("error!");
        exit;
    }

    newNode->elem.data = data;
    newNode->next = NULL;
    trav->next = newNode;
}

void deleteData(LinkedList *A, int data){
    LinkedList *trav = A;

    for (; *trav != NULL && (*trav)->elem.data != data; trav =  &(*trav)->next){}

    if (*trav != NULL){
        LinkedList temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

int locate(LinkedList A, int data){
    int index = 0;
    LinkedList trav;

    for (trav = A; trav && trav->elem.data != data; trav = trav->next, ++index){}
    return (trav == NULL) ? -1 : index; 
}

bool findElem(LinkedList A, int data){
    LinkedList trav;
    for (trav = A; trav != NULL && trav->elem.data != data; trav = trav->next){}
    return trav != NULL ? true : false;
}




