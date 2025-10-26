#include <stdio.h>
#include <stdlib.h>
#include <Stdbool.h>
#define MAX 0xFF

typedef struct {
    int elem[MAX];
    int count;
}maxHeap, minHeap;

//Heap has two MinHeap and MinHeap
// Max heap = biggest on top , Every parernt >= children, parent is larger than its chilren
// Min Heap = smallest on top, Every parent <= children parent is lesser than its children  


void insertMaxHeap(maxHeap *A, int x);
void initHeap(maxHeap *A, minHeap *B);

int main(){
    maxHeap A;

    return 0;
}

void initHeap(maxHeap *A, minHeap *B){
    A->count = 0;
    B->count = 0;
}

void insertMaxHeap(maxHeap *A, int x){ //inserts at last available position, and then while the child is greater than parent swap them until reach root or satisfied.
    if (A->count < MAX){
        int i = A->count;
        A->elem[i] = x;
        A->count++;

    
        int parent = (i - 1) / 2;
        
        for (; i > 0 && A->elem[i] > A->elem[parent]; i = parent, parent = (i - 1) / 2){
            int temp = A->elem[i];
            A->elem[i]  = A->elem[parent];
            A->elem[parent] = temp;

        }
    }
}