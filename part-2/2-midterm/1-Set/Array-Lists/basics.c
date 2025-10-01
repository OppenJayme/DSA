#include <stdio.h>
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

int main(){
    Set A = {{}, 0};
    Set B = {{}, 0};

    insertToSet(&A, 10);
    printSet(A);
    insertToSet(&A, 5);
    printSet(A);
    insertToSet(&A, 5);
    printSet(A);
    insertToSet(&A, 20);
    printSet(A);
    insertToSet(&A, 30);
    printSet(A);
    insertToSet(&A, 11);
    printSet(A);
    deleteFromSet(&A, 10);
    printSet(A);

    deleteFromSet(&B, 10);


}

void insertToSet(Set *S, int data){ // since there should be no duplicates
    if (S->size < MAX){
        int x = 0;
        for (; S->set[x] != data && x < S->size; ++x){};

        if (x == S->size){
            S->set[S->size++] = data;
        } else {
            printf("Duplicate %d Found in SET not inserting...\n", data);
        }
    }
}

void deleteFromSet(Set *S, int data){
    if (S->size != 0){
        int x;
c
        for (; S->set[x] != data && x < S->size; x++){}

        for(int i = x; i < S->size; ++i){
            S->set[i] = S->set[i + 1];
        }
        S->size--;
    } else {
        printf("empty SET\n");
    }
}
void printSet(Set S){
    if (S.size < MAX){
        for (int i = 0; i < S.size; ++i){
            printf("%d", S.set[i]);
            printf("%s", (i < S.size - 1) ? ", " : ".\n");
        }
    }
}

Set Union(Set A, Set B){
    if (A.size != 0 && B.size != 0){
        Set C = {{}, 0};

        for (int i = 0; i < A.size; ++i){
            C.set[C.size++] = A.set[i];
        }
        
        for (int j = 0; j < B.size && C.size < MAX; ++j){
            int found = 0;
            for (int i = 0; i < C.size; ++i){
                if (C.set[i] == B.set[j]){
                    int found = 1;
                    break;
                }
            }
            if (!found){
                C.set[C.size++] = B.set[j];
            }
        }
    return C;
    }
}
