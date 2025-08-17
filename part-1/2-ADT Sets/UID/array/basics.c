#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int set[MAX];
    int size;
} Set;

void insertToSet(Set *S, int data);
void deleteFromSet(Set *S, int data);
void printSet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

// Sets have no duplicate elements
int main(){
    Set A = {{}, 0};
    Set B = {{}, 0};

    
    return 0;
}

void insertToSet(Set *S, int data){
    if (S->size < MAX){
        int i = 0;

        for (; S->set[i] != data ; ++i){} // traverses the SET if no data is equal to given data

        if (i == S->size){ // if it reaches to the end (no duplicate data).
            S->set[S->size++] = data; //insert at index size since its ahead by 1
        }
    }
}

void deleteFromSet(Set *S, int toDelete){
    if (S->size > 0){
        int i  = 0;
        for (; i < S->size && S->set[i] != toDelete; ++i){}

       if (i < S->size){
            S->size--;

            if (S->size > 0){
                S->set[i] = S->set[S->size];
            }
        }
    }
}

void printSet(Set S){
    if (S.size < MAX){
        for (int i = 0; i < MAX; ++i){
            printf("%d ", S.set[i]);
        }
    }
}
