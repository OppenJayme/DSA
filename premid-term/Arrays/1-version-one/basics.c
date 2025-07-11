#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10


typedef struct {
    int data;
} Element;

typedef struct {
    Element Elements[MAX];
    int size;
} list_one;

void init(list_one *myList);
void read(list_one myList);
void insert(list_one *myList, int num);
void delete(list_one *myList, int data);

int main(){
    list_one myList;

    init(&myList);
    read(myList);

    insert(&myList, 1);
    read(myList);
    insert(&myList, 2);
    read(myList);

    delete(&myList, 2);
    read(myList);
    

    return 0;
}

void init(list_one *myList){
    myList->size = 0;
} 

void read(list_one myList){
    printf("List: ");
    for (int i = 0; i < myList.size; ++i){
        printf("%d%s", myList.Elements[i].data, (i != myList.size - 1) ? ", " : ".\n");
    }
    if (myList.size == 0){
        printf("EMPTY!\n");
    }
}

void insert(list_one *myList, int num){
    if (myList->size < MAX){
        myList->Elements[myList->size++].data = num;
    } 
}

void delete(list_one *myList, int data){
    int i = 0;

    for (; i < myList->size && myList->Elements[i].data != data; ++i) {} // i is always the index of the number to be deleted

    if (i != myList->size){ // conditional 
        for (++i; i <= myList->size; ++i){ // makes i(1) = to the index number of the number to be deleted, executes code below, and adds + 1 to i
            myList->Elements[i - 1] = myList->Elements[i]; // makes the number before i(1) become the number i(2) is. so 1 is now 2 {2,2}, size = 2
         }
        myList->size--; // removes the last ({2,2} becomes 2 now). 
    }
}