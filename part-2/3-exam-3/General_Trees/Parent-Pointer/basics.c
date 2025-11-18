#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //defines as the highest element thaat can be stored


// general tree rule
//  - index = element
//  - value in that index = parent of that index (element);
typedef int tree[MAX];

void inittree(tree t);
void insert(tree t, int elem, int parent);
void display(tree t);

int main(){
    tree t;

    inittree(t);
    insert(t, 3, 10 );

    return 0;
}

void inittree(tree t){
    for (int i = 0; i < MAX; ++i){
        t[i] = -1; // empty = no parent 
    }
}

void insert(tree t, int elem, int parent){
    if (elem > 0 && elem < MAX){
        t[elem] = parent;
    } else{
        printf("Out of bounds!\n");
    }
}

void display(tree t){
    printf("Element\tParent");
    for (int i = 0;i < MAX; ++i){
        printf("%d\t%d", i, t[i]);
    }
}
