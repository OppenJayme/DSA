#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char data;
} Element;
typedef struct node {
    Element letter;
    struct node *link;
} *LinkedList;


void init(LinkedList *L);
void read(LinkedList L);
void insertFirst(LinkedList *L, char data);
void insertLast(LinkedList *L,  char data);
void deleteData(LinkedList *A, char data);
int locate(LinkedList A, int data);
bool findElem(LinkedList A, int data);

int main(){
    LinkedList List;

    init(&List);
    read(List);

    insertFirst(&List, 'U');
    read(List);

    insertLast(&List, 'S');
    read(List);

    deleteData(&List, 'S');
    read(List);
    

    

    return 0;
}

void init(LinkedList *L){
    *L = NULL;
}

void read(LinkedList L){
    printf("List: ");
    LinkedList curr = L;
    for(; L; L = L->link){
        printf("%c%s", L->letter.data, (L->link != NULL) ? ", " : ".\n");
    }
    if (curr == NULL){
        printf("Empty!\n");
    }
}

void insertFirst(LinkedList *L, char data){
    LinkedList newNode = (LinkedList)malloc(sizeof(struct node));
    newNode->letter.data = data;
    newNode->link = *L;
    *L = newNode;
}

void insertLast(LinkedList *L, char data){
    LinkedList trav;

    for (trav = *L; trav->link != NULL; trav = trav->link){}
    LinkedList newNode = (LinkedList)malloc(sizeof(struct node));
    newNode->letter.data = data;
    newNode->link = NULL;
    trav->link = newNode; 
}
void deleteData(LinkedList *L, char data){
    LinkedList *trav;
    for(trav = L; trav != NULL && (*trav)->letter.data != data; trav = &(*trav)->link){}
    LinkedList temp = *trav;
    *trav = temp->link;
    free(temp);
}