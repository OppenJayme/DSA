#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// basically like a priority queue and this is MAX HEAP or parent >= children
// definition of partially oredered tree eis that there is a relationship between its parents and children, and parent is either bigger or smaller than its children

typedef struct {
    int pot[MAX];
    int lastNdx; // last index of the array not next available.
} POT;

void initPOT(POT *pot);
void display(POT tree);
void insert(POT *tree, int elem);

int main(){
    POT greater; // parent >= children

    initPOT(&greater);

    insert(&greater, 10);
    display(greater);

    return 0;
}

void initPOT(POT *pot){
    pot->lastNdx = 0;
}

void insert(POT *tree, int elem){
    if (tree->lastNdx == 0){
        tree->pot[tree->lastNdx] = elem;
        return;
    }
    
    if (tree->lastNdx < MAX){
        tree->pot[++tree->lastNdx] = elem; // next available space
        int child = tree->lastNdx; // index of the now occupied space 
        int parent = (child - 1) / 2;

        while (child > 0  && tree->pot[child] > tree->pot[parent]){
            int temp = tree->pot[child];
            tree->pot[child] = tree->pot[parent];
            tree->pot[parent] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    } else {
        printf("The list is FULL!");
    }
}

void display(POT tree){ // heap stored in an array and displayig it per index  is doing BReadth-fIrst search already.
    for (int i = 0; i <= tree.lastNdx; i++){
        printf("%d ", tree.pot[i]);
    }
}