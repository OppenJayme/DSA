#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// minHEAP parent <= childrne
// Priority queue, is parent node should be higher, which means it is a descending type shi ashh so in a MaxHeap root will be highest order otherwise lowest.
// MIN HEAP parent <= children
// parent node is lower, root is lowest 

typedef struct {
    int PQ[MAX];
    int lastNdx;
} minHeap;

//parent node = (childndx - 1) / 2 
// left child = 2i + 1
// right child = 2i + 2

void initMinHeap(minHeap *min);
void insertMinHeap(minHeap *min, int elem);
void deleteMin(minHeap *min);
void display(minHeap heap);

int main(){
    minHeap min;

    initMinHeap(&min);

    insertMinHeap(&min, 10);
    insertMinHeap(&min, 24);
    insertMinHeap(&min, 15);
    insertMinHeap(&min, 4);
    insertMinHeap(&min, 34);
    insertMinHeap(&min, 15);
    insertMinHeap(&min, 56);
    insertMinHeap(&min, 34);
    insertMinHeap(&min, 25);
    insertMinHeap(&min, 11);

    display(min);


    return 0;
}

void initMinHeap(minHeap *min){
    min->lastNdx = 0;
}

// minHeap = parent <= children
void insertMinHeap(minHeap *min, int elem){
    if (min->lastNdx < MAX){

        min->PQ[min->lastNdx] = elem; // put at lastndx 
        int child = min->lastNdx; // child = last index
        min->lastNdx++; // grow!

        int parent = (child - 1) / 2; // parent index!

        while (min->PQ[parent] < min->PQ[child]){
            int temp = min->PQ[parent];
            min->PQ[parent] = min->PQ[child];
            min->PQ[child] = temp;

            child = parent; //child now is the index of the parent where it will then compare itself to its parent
            parent = (child - 1) / 2;
        }

    } else {
        printf("FULL!\n");
    }
}

void display(minHeap heap){
   for (int i = 0; i < heap.lastNdx; ++i){
         printf("%d ", heap.PQ[i]);
     }
 }


void deleteMin(minHeap *min){
    if (min->lastNdx > 0){

        min->PQ[0] = min->PQ[min->lastNdx];
        min->lastNdx--;
        int parent = 0;

        while ((2 * parent) + 1 <= min->lastNdx){
            int lc = (parent * 2) + 1;
            int rc = (parent * 2) + 2;
            int best = lc; // assume biggest is lc
            if (rc <= min->lastNdx && min->PQ[rc] > min->PQ[lc]){
                best = rc;
            }

            if (min->PQ[parent] <= min->PQ[best]){
                return;
            }

            int temp = min->PQ[parent];
            min->PQ[parent] = min->PQ[best];
            min->PQ[best] = temp;

            parent = best;
        }   


    } else {
        printf("Nothing to delete idiot\n");
    }
}