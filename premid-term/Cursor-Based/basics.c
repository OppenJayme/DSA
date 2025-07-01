// Given VirtualHeap and LIST
#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct {
    char data;
    int link;
} nodetype;
typedef struct {
    nodetype Nodes[MAX];
    int avail; // holds the index of the 1st cell
} Vheap;

typedef int LIST;

void initList(LIST *VH);
void insertFirst(Vheap *H, LIST *L, char data);

int main(){
    LIST lista;
    Vheap heap;

    initList(&lista);
    initHeap(&heap);

    insertFirst(&heap, &lista, 'U');


    return 0;
}

void initList(LIST *L){
    *L = -1;
}

void initHeap(Vheap *L){
    L->avail = 0;
    L->Nodes[MAX - 1].link = -1;
    for (int i = 1; i < MAX - 1; ++i){
        L->Nodes[i - 1].link = i;
    }
}

int allocSpace(Vheap *H){
    int idx = H->avail; //temp gets the current available address
    if (idx != -1){ 
        H->avail = H->Nodes[idx].link;
    }
    return idx; 
}

void insertFirst(Vheap *H, LIST *L, char data){
    int newNode = allocSpace(H);
    if (newNode != -1){
        H->Nodes[newNode].data = data;
        H->Nodes[newNode].link = *L;    
        printf("%d", *L);
        *L = newNode;
    }
    
}


