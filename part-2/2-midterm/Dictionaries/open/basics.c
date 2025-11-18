#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *link;
} *NodeType;

typedef NodeType Dic[MAX];

void initDictionary(Dic D);
int hashF(int elem);
void insertElem(Dic D, int x);
void display(Dic D);
bool isMember(Dic D, int x);
void deleteElem(Dic D, int x);

int main(){
    Dic D = {};
    
    initDictionary(D);
    insertElem(D, 40);
    insertElem(D, 50);
    insertElem(D, 23);
    insertElem(D, 11);
    insertElem(D, 1234);
    insertElem(D, 12);
    insertElem(D, 122);
    insertElem(D, 31);
    insertElem(D, 11);
    
    
    
    display(D);

    printf("\n");
    deleteElem(D, 23);
    display(D);

    bool findElem = isMember(D, 22);
    printf("%s", (findElem == 0) ? "Yep that dont exist" : "Bro he exists!" );

    return 0;
}

void initDictionary(Dic D){
    for (int i = 0; i < MAX; ++i){
        D[i] = NULL;
    }
}
// this hash function basically  adds the digits individually and then divided by MAX
int hashF(int elem) { // EX. 1234 = 10 % 10  = 0
    int sum = 0;
    while (elem != 0) {
        sum += (elem % 10);   // get the ones place
        elem /= 10;           // remove the ones place
    }
    return sum % MAX;
}

// Assuming list is unsorted!
void insertElem(Dic D, int x){
    NodeType *trav;
    int key = hashF(x);

    for (trav = &D[key]; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link){}; // if this breaks  while trav is not null meaning there is a duplicate wh
    
    if (*trav == NULL){ // meaning we have reached the end and no duplicate found.
        NodeType newNode = (NodeType)malloc(sizeof(struct node));
        if (newNode != NULL){ // you can insert at front or can insertLast by *trav!;
                              // in this case insertfirst for faster;
            newNode->data = x;
            newNode->link = D[key];
            D[key] = newNode;
        }
    } else {
        printf("%x already exists in the SET!\n", x);
    }
}

void display(Dic D) {
    for (int i = 0; i < MAX; ++i) {
        printf("[%d]: ", i);
        if (D[i] == NULL) {
            printf("NULL\n");
        } else {
            for (NodeType trav = D[i]; trav != NULL; trav = trav->link) {
                printf("%d%s", trav->data, trav->link ? " -> " : "\n");
            }
        }
    }
}

bool isMember(Dic D, int x){
    int key = hashF(x);
    NodeType trav;
    for (trav = D[key]; trav != NULL && trav->data != x; trav = trav->link){};
    return (trav != NULL) ? true : false;
}

void deleteElem(Dic D, int x){
    int key = hashF(x);
    NodeType *trav;

    for (trav = &D[key]; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link){} // look for the elem to delete the node behind it (elem to delete) will be used to delete the node next to it (elem to delete)

    if (*trav != NULL) { 
        NodeType temp;
        temp = *trav;
        *trav = temp->link;
        free(temp);
    } else {
        printf("Out of bounds!\n");
    }
}

// to draw this its like this say we deelte 4
// 1 -> 3  -> 4  -> 2
//      |
// where *trav is at we can access 4 through *trav

// we create a new temp to point to 4 using *trav (so now temp is pointing at 4)
// and we point 3 to 2
// and free 4