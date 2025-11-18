#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// General Rule of Chidlren Pointer
// - Acts like a open hashing
// - Each index represent its parent and elements in that index corresponds to its children
// can have more than 2 children
// no order of tree and can have duplicates

typedef struct node{
    int elem;
    struct node *next;
} *Node;

typedef Node Tree[MAX];

void initTree(Tree T);
void display(Tree T);
void insert(Tree T, int elem, int parent);
void deleteT(Tree T, int elem, int parent);

int main(){
    Tree T;

    initTree(T);

    insert(T, 2, 5);
    insert(T, 6, 5);
    insert(T, 0, 5);
    insert(T, 1, 6);
    insert(T, 3, 6);
    insert(T, 7, 1);
    insert(T, 4, 1);
    insert(T, 8, 2);
    //deleteT(T, 6, 5);
    display(T);

    return 0;
}

void initTree(Tree T){
    for (int i = 0; i < MAX; ++i){
        T[i] = NULL;
    }
}

void insert(Tree T, int elem, int parent){
    Node newElem = (Node)malloc(sizeof(struct node));
    if (newElem != NULL){
        newElem->elem = elem;
        newElem->next = NULL;
        newElem->next = T[parent];
        T[parent] = newElem;
    }
}

void deleteT(Tree T, int elem, int parent){
    Node *trav;
    for (trav = &T[parent]; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->next){}
    if (*trav != NULL){
        Node temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}


void display(Tree T) {
    printf("Parent\tChildren\n");
    
    for (int i = 0; i < MAX; ++i) {
        printf("%d\t", i);  // print parent index
        
        if (T[i] == NULL) {
            printf("NULL\n");
        } else {
            Node trav;
            for (trav = T[i]; trav != NULL; trav = trav->next) {
                printf("%d", trav->elem);
                if (trav->next != NULL) {
                    printf(" -> ");
                } else {
                    printf(" -> -");
                }
            }
            printf("\n");
        }
    }
}
