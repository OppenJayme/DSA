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
        T[i].data = 0;
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


}