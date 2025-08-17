#include <stdio.h>
#include <stdio.h>
#define MAX 10

typedef struct tree {
    int child;
    struct tree *next;
} *Node;

typedef Node Tree[MAX];

void initTree(){
    for (int i = 0; i < MAX; ++i){
        T[i] = NULL;
    }
}

void insertTree(Node *T, int data){
    Node Temp = (Node*)malloc(sizeof(Node));

    if (Temp != NULL && data >= 0 && data < MAX){
        Temp->child = data;
        Temp->next = *T;
        *T = Temp;
    }
}

void display(Tree T, int root){
    printf("%d", root);
    for (T[root] != NULL){
        for (Node trav = T[root]; trav != NULL; trav = trav->next){
            display(T, trav->child);
        }
    }
}

void LeftMost_child(node n, Tree T){
   // function to find leftmost; 
}

int main(){
    Tree T;
    int root = 0;

    initTree(T);


    return 0;
}