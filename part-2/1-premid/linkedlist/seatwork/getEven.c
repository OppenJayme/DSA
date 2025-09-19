#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} *LIST;

LIST getEven(LIST L);
void insertFirst(LIST *L, int new);
void initLL(LIST *L);
void display(LIST L);
LIST getEven(LIST L);
LIST getEvenNoFunctions(LIST L);
int getCount(LIST L);

int main(){
    LIST real;
    initLL(&real);

    insertFirst(&real, 10);
    display(real);
    insertFirst(&real, 11);
    display(real);
    insertFirst(&real, 14);
    display(real);
    insertFirst(&real, 23);
    display(real);
    insertFirst(&real, 12);
    display(real);
    insertFirst(&real, 2);
    display(real);
    insertFirst(&real, 1);
    display(real);
    insertFirst(&real, 24);
    display(real);

    LIST even = getEven(real);
    display(even);
    LIST newEven = getEvenNoFunctions(real);
    display(newEven);

    int count = getCount(real);
    printf("There are %d numbers that are divisible by 6", count);

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

void insertFirst(LIST *L, int new){
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("MEMORY ALLOCATION FAILED!\n");
    } else {
        newNode->data = new; 
        newNode->link = *L;
        *L = newNode;
    }
}

//Exercise 1;
LIST getEven(LIST L){
    LIST newList;
    initLL(&newList);
    for (L; L != NULL; L = L->link){
        if ((L->data % 2) == 0){
            insertFirst(&newList, L->data);
        }
    }
    return newList;
}

LIST getEvenNoFunctions(LIST L){
    LIST newList = NULL;
    LIST temp;
    for (L; L != NULL; L = L->link){
        if ((L->data % 2) == 0){
            temp = (LIST)malloc(sizeof(struct node));
            if (temp != NULL){
                temp->data = L->data;
                temp->link = newList; 
                newList = temp;   
            } else {
                printf("Memory allocation failed!\n");
            }
        }
    }
    return newList;
}

//Exercise 2

int getCount(LIST L){// counts how many are divisible by 6
    int x = 0;
    for (; L != NULL; L = L->link){
        if ((L->data % 6) == 0){
            x++;
        }
    }
    return x;
}

