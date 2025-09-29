#include <stdlib.h>
#include <stdio.h>

typedef unsigned char SET; // only contains 8 bits of data
                           // 1 bit = 1 element;
                           // technically only 6 elements can be inserted

void initSet(SET *A);
void display(SET A, char name[]);
void insert(SET *A, int x);
void delete(SET *A, int x);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET difference(SET A, SET B);
SET Union(SET A, SET B);

int main(){
    SET A;
    SET B;
    
    
    initSet(&A);
  
    insert(&A, 6);
    insert(&A,2);
    insert(&A, 3);
    insert(&A, 1);
    

    initSet(&B);
    insert(&B, 4);
    insert(&B,6);
    insert(&B, 2);
    insert(&B, 5);
    
    display(A, "A");
    display(B, "B ");

    
    SET C = Union(A, B);
    display(C,"A U B");

    SET D = Intersection(A, B);
    display(D, "A n B");

    SET E = difference(A, B);
    display(E, "A - B");
    
    
    
    return 0;
}

void initSet(SET *A){
    *A = 0;
}

void insert(SET *A, int x){
    if (x < 8){
        *A |= (1 << x ); // shift 1 by x elements
                         // example 
                         // 3 to be inserted, 3 is 0000 0011, 1 is 0000 0001
                         // (1 << 3) = 0000 1000 which is basically 2^3 
                         // *A = *A | (1 << x);
    }
}

void delete(SET *A, int x){
     if (x < 8){
        *A &= ~(1 << x); // shift 1 by x elements then compliment 
                         // example 
                         // 
                         // *A = *A | ~(1 << x);
    }
}

void display(SET A, char name[]){ //add some label;
    printf("%5s = { ", name);
    for (int i = 0; i < 8; ++i){
        if (((A >> i ) & 1) == 1){
            printf("%d", i);
            printf("%s", (((A >> i) & 0) == 0) ? ", " : ".\n");
        }
    }
    printf("}\n");
}
SET Union(SET A, SET B){
    SET C = A | B;
    return C;
}
SET Intersection(SET A, SET B){
    SET C = A & B;
    return C;
}
SET difference(SET A, SET B){
    SET C = A & ~B; 
    return C;
}
