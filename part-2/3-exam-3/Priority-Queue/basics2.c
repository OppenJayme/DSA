#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int Pq[MAX];
    int lastndx;
} MinHeap, MaxHeap;

void initHeap(MaxHeap *max, MinHeap *min);
void insertMax(MaxHeap *max, int elem);
void deleteMax(MaxHeap *max);

void display(MaxHeap heap){
    for (int i = 0; i < heap.lastndx; ++i){
        printf("%d ", heap.Pq[i]);
    }
}

int main(){
    MinHeap Mh;
    MaxHeap Max;

    initHeap(&Max, &Mh);

    insertMax(&Max, 10);
    insertMax(&Max, 23);
    insertMax(&Max, 36);
    insertMax(&Max, 13);
    insertMax(&Max, 15);

    display(Max);

    printf("\n");
    deleteMax(&Max);

    display(Max);
    


    return 0;
}

void initHeap(MaxHeap *max, MinHeap *min){
    max->lastndx = 0;
    min->lastndx = 0;
}

void insertMax(MaxHeap *max, int elem){

    // parent = (child - 1) / 2
    // child =  2  * paarent  + 1 lc + 2 rc

    max->Pq[max->lastndx] = elem;
    int child = max->lastndx;
    int parent = (child - 1) / 2;
    max->lastndx++;

    while(child != 0 && max->Pq[child] > max->Pq[parent]){
        int temp = max->Pq[child];
        max->Pq[child] = max->Pq[parent];
        max->Pq[parent] = temp;

        child = parent; 
        parent = (child - 1) / 2;
    }

}

void deleteMax(MaxHeap *max){
    if (max->lastndx > 0){ // meaning there are elements

        max->Pq[0] = max->Pq[max->lastndx - 1]; // root becomes the element of the last index
        max->lastndx--; // shrink
        int parent = 0; // index

        while((2 * parent + 1) <= max->lastndx){ // there is atleast a left child
            int lc = 2 * parent + 1; // lc 
            int rc = 2 * parent + 2; // rc
            int best = lc; // assume left child is best 
            if (rc <= max->lastndx && max->Pq[rc] > max->Pq[lc]) { // comparison in finding the best/biggest element
                best = rc;
            }

            if (max->Pq[parent] >= max->Pq[best]){ // POT property is satisfied, parent is bigger than child or MAX HEAP
                return;
            }

            int temp = max->Pq[parent]; // swap
            max->Pq[parent] = max->Pq[best];
            max->Pq[best] = temp; 

            parent = best; // parent becomes the index of the largest element and repeat
        }
    }
}