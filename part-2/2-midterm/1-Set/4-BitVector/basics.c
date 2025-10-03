#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef int SET[MAX];

void display(SET A, char S[]);
void insertToSet(SET A, int x);
SET *Union(SET A, SET B);
SET *Intersection(SET A, SET B);
SET *Difference(SET A, SET B);

int main(){
    SET A = {};
    SET B = {};

    insertToSet(A, 3);
    insertToSet(A, 1);
    insertToSet(A, 5);
    insertToSet(A, 6);
    insertToSet(A, 7);

    insertToSet(B, 4);
    insertToSet(B, 9);
    insertToSet(B, 3);
    insertToSet(B, 1);

    display(A, "Displaying A\n");
    display(B, "Displaying B\n");

    SET *C = Union(A, B); 
    display(*C, "A u B\n");
    SET *D = Intersection(A,B);
    display(*D, "A n B\n");
    SET *E = Difference(A,B);
    display(*E, "A - B\n");

    return 0;
}

void insertToSet(SET A, int x){
    if (A[x] != 1 && A[x] < MAX){
        A[x] = 1;
    } else {
        printf("Duplicated or over MAX\n");
    }
    
}
void display(SET A, char S[]){
    printf("%5s", S);
    for (int i = 0; i < MAX; ++i){
        printf("%d", A[i]);
        printf("%s", (i < MAX - 1) ? ", " : ".\n");
    }
}

SET* Union(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));
    if (*C != NULL){
        for (int i = 0; i < MAX; ++i){
            (*C)[i] = A[i] | B[i];
        }
    }
    return C;
}

SET *Intersection(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));
    if (*C != NULL){
        for (int i = 0; i < MAX; ++i){
            (*C)[i] = A[i] & B[i];
        }
    }
    return C;
}

SET *Difference(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));
    if (*C != NULL){
        for (int i = 0; i < MAX; ++i){
            (*C)[i]= A[i] & ~(B[i]);
        }
    }
    return C; 
}