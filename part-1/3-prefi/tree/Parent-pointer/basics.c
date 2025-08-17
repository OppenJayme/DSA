/*
    Ivan Jayme idea
    - Complete binary tree using an array + parent‐pointer implementation
    - Stored in level order (top-to-bottom, left-to-right)
    - Each Node has:
        • data   → the node’s value
        • parent → the index of this node’s parent in the array (–1 if it’s the root)
    - Child indices are implicit:
        • left  child of i → 2*i + 1
        • right child of i → 2*i + 2
    - Unused slots have parent = –1 and data = 0 after initTree()
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int parent; 
} Node;

typedef Node Tree[MAX];

void initTree(Tree T){
    for (int i = 0; i < MAX; ++i){
        T[i].parent = -1;
    }
}

void addchild(Tree T, int parentndx, int Cndx, int data){
    T[Cndx].data = data; //assigns data to the child
    T[Cndx].parent = parentndx; // link child to parent
}

void readTree(Tree T){
    printf("Idx | Data | Parent\n");
    printf("--------------------\n");
    for (int i = 0; i < MAX; ++i) {
        printf("%3d | %4d | %6d\n",
               i,
               T[i].data,
               T[i].parent);
               
    }
}

//visit note, left and right
void preorder(Tree T, int idx){
    if (idx < MAX){
        printf("%d ", T[idx].data); //prints node;
        preorder(T, 2 * idx + 1); // prints left;
        preorder(T, 2 * idx + 2);// printright; 
    }
}
void inorder(Tree T, int idx){
    if (idx < MAX){
        inorder(T, 2 * idx + 1); // prints left;
        printf("%d ", T[idx].data); //prints node;
        inorder(T, 2 * idx + 2);// printright; 
    }
}

void postorder(Tree T, int idx){
    if (idx < MAX){
        postorder(T, 2 * idx + 1); // prints left;
        postorder(T, 2 * idx + 2);// printright;
        printf("%d ", T[idx].data); //prints node; 
    }
}



int main(){
    Tree T;
    int data[] = {10,2,5,7,1,8,9,1,5,8};

    initTree(T);
    //add root
    addchild(T, -1, 0, data[0]);

    for (int i = 0; i < MAX; ++i){
        int left = 2 * i + 1; // index of left child
        int right = 2 * i + 2; // index of right

        if (left < MAX)  addchild(T, i, left, data[left]);
        if (right < MAX) addchild(T, i, right, data[right]); 
    }

    readTree(T);
    printf("\n\n");
    preorder(T, 0); 
}