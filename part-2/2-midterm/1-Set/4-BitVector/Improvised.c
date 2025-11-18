#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef unsigned int SET[MAX]; //universal set size
int findHighest(SET U); 
unsigned int *createBitVectorArray(SET U, int size);
void init(unsigned int *A, int size);
void display(SET A, int size);

int main(){
    SET uSET = {0,2,5,4,10,7};
    SET aSET = {2,5,7};

    int size = findHighest(aSET);

    unsigned int *setA = createBitVectorArray(aSET, size);

    display(setA, size);


    return 0;
}


int findHighest(SET U){
    int high = U[0];
    for (int i = 0; i < MAX; ++i){
        if (U[i] > high){
            high = U[i];
        }
    }
    return high;
}

unsigned int *createBitVectorArray(SET U, int size){
    int arr = size + 1;
    unsigned int *newArr = malloc(sizeof(int) * arr);
    if (newArr != NULL){
        init(newArr, size);
        for (int i = 0; i < arr; ++i){
            if (U[i] != 0 && U[i] <= (unsigned int)size){
                newArr[U[i]] = 1;
            }
        }
    }
    return newArr;
}

void init(unsigned int *A, int size){
    for (int i  =0 ;i < size; ++i){
        A[i] = 0;
    }
}

void display(SET A, int size){
    int arr = size + 1;
    printf("{ ");
    for (int i = 0; i < arr; ++i){
        printf("%d%s", A[i], (i < arr - 1) ? ", " : ". }\n" );
    }
}
