#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char data;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAX];
    int avail;
} VirtualHeap;

typedef int LIST;

int allocSpace(VirtualHeap *VH){
    int ndx = VH->avail;
    if (ndx != -1) {
        VH->avail = VH->nodes[ndx].link;
    }
    return ndx;
}

void deallocSpace(VirtualHeap *VH, int ndx){
    if (ndx > 0 && ndx < MAX){
        VH->nodes[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void initVirtualHeap(VirtualHeap *VH){ // -1 starts at indx 0
    for (int i = 0; i < MAX; ++i){
        VH->nodes[i] = i - 1;
    }
    VH->avail = MAX - 1;

}

void insertFirst(VirtualHeap *VH, LIST *L, char data){
    int newNode = allocSpace(H);
    if (newNode != -1){
        VH->nodes[newNode].link = *L
        VH->nodes[newNode].data = data;
        *L = newNode;
    }
}
void insertLast(VirtualHeap *VH, LIST *L, char data){
    int newNode = allocSpace(H);
    (if newNode != -1){

    }
}
int main(){


    return 0;
}
