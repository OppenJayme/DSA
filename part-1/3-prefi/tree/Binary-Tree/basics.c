#include <stdio.h>
#include <stdlib.h>
#define MAX 10;

// Binary Tree - Each node has at MOST 2 children, labeled left and right
// has only right
// only left
// both;


typedef struct {
    int data;
    int left;
    int right;
} Node;

typedef Node Tree[MAX];

void initTree(Tree T){
    for (int i = 0; i < MAX; ++i){
        T[i].data = -1;
        T[i].left = -1;
        T[i].right = -1;
    }
}


void display(Tree T) {
    printf("Idx | Data | Left | Right\n");
    printf("--------------------------\n");
    for (int i = 0; i < MAX; i++) {
        if (T[i].data != -1) {
            printf("%3d | %4d | %4d | %5d\n", i, T[i].data, T[i].left, T[i].right);
        }
    }
}


//adds like a floating node;
void addNode(Tree T, int idx, int data){
    if (idx >= 0 && idx < MAX){
        T[idx].data = data;
        T[idx].left = -1;
        T[idx].right = -1;
     }
}

// assigns children to the floating node
void addLeft(Tree T, int parentidx, int childidx){
    if ((parentidx >= 0 && parentidx < MAX) && childidx >= 0 && childidx < MAX){
        T[parentidx].left = childidx;
    }
}

void addright(Tree T, int parentidx, int childidx){
    if ((parentidx >= 0 && parentidx < MAX) && childidx >= 0 && childidx < MAX){
        T[parentidx].right = childidx;
    }
}


int main(){

    Tree T;

    initTree(T);
    addNode(T, 0, 15); //root 
    addNode(T, 1, 14);
    addNode(T, 2, 31);
    addNode(T, 3, 3);

    addLeft(T, 0, 1)
    addLeft(T, 1, 2)
    addLeft(T, 2, 3);
    addright(T, 2, 4)

    return 0;
}