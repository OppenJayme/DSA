// Given VirtualHeap and LIST
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void initList(LIST *VH); //initalizes list for a value/null
void read(Vheap H, LIST L); // display
void initHeap(Vheap *L); // initializes the vheap and link to the next node/indexs
void freeVH(Vheap *H, int idx); // unlinkes trhe specific index/
void insertFirst(Vheap *H, LIST *L, char data);
void insertLast(Vheap *H, LIST *L, char data);

int allocSpace(Vheap *H); //returns the index of the available node and sets the avail to the next available node uising link/
void delete(Vheap *H, LIST *L, char data); // deletes the node.
bool locate(Vheap H, LIST L, char data);

int main(){
    LIST lista;
    Vheap heap;

    initList(&lista);
    initHeap(&heap);

    insertFirst(&heap, &lista, 'U');
    read(heap,lista);
    
    insertFirst(&heap, &lista, 'C');
    read(heap,lista);
    insertLast(&heap, &lista, 'S');
    read(heap,lista);
    delete(&heap, &lista, 'C');
    read(heap,lista);

    printf("%d", locate(heap, lista, 'U'));
   

    return 0;
}

void initList(LIST *L){
    *L = -1;
}

void initHeap(Vheap *L){
    L->avail = 0;
    
    for (int i = 1; i < MAX; ++i){
        L->Nodes[i - 1].link = i;
    }
    L->Nodes[MAX - 1].link = -1;
}

void read(Vheap H, LIST L) {
    printf("CB List: ");

    for(int i = L; i != -1; i = H.Nodes[i].link) {
        printf("%c%s", H.Nodes[i].data, (H.Nodes[i].link == -1) ? ".\n" : ", ");
    }

    if(L == -1) {
        printf("EMPTY\n");
    }
}

void insertFirst(Vheap *H, LIST *L, char data){
    int newNode = allocSpace(H);
    if (newNode != -1){
        H->Nodes[newNode].data =  data;
        H->Nodes[newNode].link = *L;
        *L = newNode;
    }
    
}

void insertLast(Vheap *H, LIST *L, char data){
    int newNode = allocSpace(H); // finds index to where to insert
    if (newNode != -1){
        int *curr; // assigns it to List
        for (curr = L; *curr != -1; curr = &(H->Nodes[*curr].link)){} // if curr is not the end of the list then next
        H->Nodes[newNode].data = data; // assign data on the avail spot
        H->Nodes[newNode].link = -1; // assign -1 on the link of the avail spot because its the last to be inserted.
        *curr = newNode; // the previous -1 will be overwritten by the index of where data will be inserted.
    }
}

void delete(Vheap *H, LIST *L, char data){
    int *curr;
    for (curr = L; *curr != -1 && H->Nodes[*curr].data != data; curr = &H->Nodes[*curr].link){}
        if (*curr != -1){
            int temp = *curr;
            *curr = H->Nodes[*curr].link;
            freeVH(H, temp);
        }
}

int allocSpace(Vheap *H){
    int idx = H->avail; //temp gets the current available address
    if (idx != -1){ 
        H->avail = H->Nodes[idx].link;
    }
    return idx; 
}
void freeVH(Vheap *H, int idx){
    if (idx >= 0 && idx < MAX){
        H->Nodes[idx].link = H->avail; // at the index of where link is, assign link to h->avail for the index to be flagged available;
        H->avail = idx; // assign h->avail to ihe index of the newly allocated space. meaning there will be an available space in that index.
    }
}

bool locate(Vheap H, LIST L, char data){
    int curr;
    for (curr = L; curr != -1 && H.Nodes[curr].data != data; curr = H.Nodes[curr].link){}
    return  (curr != -1) ? true : false;
}
    
