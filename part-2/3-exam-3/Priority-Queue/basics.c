#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// MaxHEAP parent >= childrne
// Priority queue, is parent node should be higher, which means it is a descending type shi ashh so in a MaxHeap root will be highest order otherwise lowest.
// MIN HEAP parent <= children
// parent node is lower, root is lowest 

typedef struct {
    int PQ[MAX];
    int lastNdx;
} MaxHeap, MinHeap, Heap;


//parent node = (childndx - 1) / 2 
// left child = 2i + 1
// right child = 2i + 2

void insertMaxHeap(MaxHeap *Heap, int elem);
void initMaxHeap(MaxHeap *max);
void initMinHeap(MinHeap *max);
void display(Heap heap);

int main(){
    MaxHeap max;
    MinHeap min;

    initMinHeap(&min);
    initMaxHeap(&max);

    insertMaxHeap(&max, 8);
    insertMaxHeap(&max, 23);
    insertMaxHeap(&max, 75);
    insertMaxHeap(&max, 14);
    insertMaxHeap(&max, 13);
    
    display(max);

    return 0;
}

void initMinHeap(MinHeap *max){
    max->lastNdx = 0;
}
void initMaxHeap(MaxHeap *max){
    max->lastNdx = 0;
}

void display(Heap heap){
    for (int i = 0; i < heap.lastNdx; ++i){
        printf("%d ", heap.PQ[i]);
    }
}
void insertMaxHeap(MaxHeap *Heap, int elem){
    if (Heap->lastNdx < MAX){
        // if heap is not full insert
        // insert at last
        int child = Heap->lastNdx; 
        Heap->PQ[child] = elem;
        Heap->lastNdx++;

        int parent = (child - 1) / 2;


        while (child > 0 && Heap->PQ[child] > Heap->PQ[parent]){
            // swapping mechanisms
            int temp = Heap->PQ[parent]; 
            Heap->PQ[parent] =  Heap->PQ[child];
            Heap->PQ[child] = temp;

            // child becomes parent or like moves up the tree bcs they swapped.
            // child now becomes the new parent.
            // then we will find its parent.
            child = parent; 
            parent = (child - 1) / 2;
        }
        printf("Inserted\n");
    } else {
        printf("Already Full\n");
    }
}   

void deleteMax(MaxHeap *max){
    if (max->lastNdx == 0){
        printf("empty\n");
        return;
    }

    max->PQ[0] = max->PQ[max->lastNdx--]; //root bcomes last element 
    int parent = 0;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int best = left;
    while (max->PQ[parent] <= max->PQ[best]){ // if parent is >= than the child then heap property is satisifed
        if (right < max->lastNdx && max->PQ[right] < max->PQ[left]){
            best = right;
        }

        int temp = max->PQ[best];
        max->PQ[best] = max->PQ[parent];
        max->PQ[parent] = max->PQ[temp];

        parent = best;
    }
}