#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Set[MAX];

void populateSet(Set s);
void displaySet(Set s);
Set *Union(Set B, Set A);
Set *Intersection(Set A, Set B);
Set *Difference(Set A, Set B);

int main(){
    Set A = {};
    Set B = {};



    return 0;
}


void populateSet(Set s){
    for (int i = 0; i < MAX; ++i){
        int data;
        printf("enter data: ");
        scanf("%d", &data);
        if (data > 0 && data < MAX){
            s[i] = 1;
        }
    }   
}

void displaySet(Set S){
    for (int i = 0; i < MAX; ++i ){
        if (S[i] == 1){
            printf("%d ", i);
        }
    }
    printf("\n");
}

Set *Union(Set B, Set A){
    Set *s = (Set *)malloc(sizeof(Set));

    if (s != NULL){
        for (int i = 0; i < MAX; ++i){
            (*s)[i] = A[i] | B[i];
        }
    }
    return s;
}

Set *Intersection(Set A, Set B){
    Set *s = (Set *)malloc(sizeof(Set));

    if (s != NULL){
        for (int i = 0; i < MAX; ++i){
            (*s)[i] = A[i] & B[i];
        }
    }
    return s;
}

Set *Difference(Set A, Set B){
    Set *s = (Set *)malloc(sizeof(Set));

    if (s != NULL){
        for (int i = 0; i < MAX; ++i){
            (*s)[i] = A[i] & (~B[i]); // difference
        }
    }
    return s;
}
