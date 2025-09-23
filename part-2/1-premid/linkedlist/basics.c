#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *link;
} *LIST;

typedef enum {TRUE, FALSE} Boolean;

void insertFirst(LIST *L, int data);
void initLL(LIST *L);
void display(LIST L);
Boolean deleteElem(LIST *L, int x);

int main(){
    LIST L;
    initLL(&L);
    int x = 99;
    insertFirst(&L, 10);
    display(L);
    insertFirst(&L, 23);
    display(L);
    insertFirst(&L, 11);
    display(L);
    insertFirst(&L, 2);
    display(L);

    Boolean isDeleted = deleteElem(&L, x);
    printf("Number %d: %s\n", x, (isDeleted == 0) ? "Deleted!\n" : "Not Found!\n");
    display(L);
    

    return 0;
}

void initLL(LIST *L){
    *L = NULL;
}

void display(LIST L){
    if (L != NULL){
        for (L; L != NULL; L = L->link){
            printf("%d", L->data);
            printf("%s", (L->link != NULL) ? ", " : ".\n");
        }
    }
}

void insertFirst(LIST *L, int data){
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("MEMORY ALLOCATION FAILED!\n");
    } else {
        newNode->data = data; 
        newNode->link = *L;
        *L = newNode;
    }
}

Boolean deleteElem(LIST *L, int x){
    Boolean result = FALSE;
    for (; *L != NULL && (*L)->data != x; L = &(*L)->link) {}
    if (*L != NULL) {
        LIST temp = *L;
        *L = temp->link;
        free(temp);
        result = TRUE;
    }
    return result;    
}
