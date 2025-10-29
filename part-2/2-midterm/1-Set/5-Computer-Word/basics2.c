#include <stdio.h>
#include <stdio.h>

typedef unsigned char SET;

void insert(SET *A, int elem); // element must be within 8 bits (char is 1 byte) only so 1-8
void delete(SET *A, int elem);
void display(SET A);

SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);

int main(){
    SET A;

    insert(&A, 6);
    insert(&A, 3);
    insert(&A, 2);
    insert(&A, 7);
    display(A);

    delete(&A, 6);
    printf("SET A: ");
    display(A);

    SET B;
    insert(&B, 2);
    insert(&B, 1);
    insert(&B, 4);
    insert(&B, 7);
    printf("SET B: ");
    display(B);

    SET U = Union(A, B);
    printf("A U B: \n");
    display(U);

    printf("A n B: \n");
    SET I = Intersection(A, B);
    display(I);
    
    printf("A - B: \n");
    SET D = Difference(A, B);
    display(D);  


    return 0;
}

void display(SET A){
    int i = 7; // 8 bits (char)  7 bcs of 1 in the condition
    for (i; i >= 0; i--){ 
        printf("%d ", (A & (1 << i) ? 1 : 0)); // i = 7 = 0100 0000 
                                               // 1 < 7 = 1000 0000 = 0
                                               // i < 6 = 0100 0000 = 1
                                               // i < 5 = 0010 0000 = 0
                                               // i < 4 = 0001 0000 = 0 and so on
    }
    printf("\n");
}

void insert(SET *A, int elem){
    *A = *A | (1 << elem - 1); // A = 0000 0000
                              // 1 << elem (6 - 1)  = 0010 0000 
                              // 0000 0000  or (*A)
                              // 0010 0000  or (i << elem)
                              // 0010 0000 this is ur *A now  
}
void delete(SET *A, int elem){
    *A = *A & ~(1 << elem - 1); // 1 << elem (6) - 1 0010 0000
                                // 0010 0000 and  
                                // 0000 0000 and (0 bcs of complement(~))
                                // 0000 0000 this is ur A now  
}

SET Union(SET A, SET B){ // all elements in a and b
    SET C = A | B;
    return C;
}

SET Intersection(SET A, SET B){ // elements that are both in a and B
    SET C = A & B;
    return C;
}

SET Difference(SET A, SET B){ //elemets that are in A but not in B
    SET C = A & ~B;
    return C;
}