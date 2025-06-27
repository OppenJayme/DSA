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
    int avail; // holdsthe index of the 1st cell
} Vheap;

typedef int LIST;

int main(){
    LIST lista;
    Vheap heap;


    return 0;
}

void initList(LIST *VH){
    *VH = -1;
}

void insertFirst(Vheap *H, LIST L*, int data)

