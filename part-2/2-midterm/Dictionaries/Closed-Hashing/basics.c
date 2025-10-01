#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1
#define DELETED '!'
#define MAX 10


typedef int Dictionary[MAX];

void initDictionary(Dictionary M);
int hash(int x);
void insertUnique(Dictionary D, int x);
void display(Dictionary D);

int main(){
    Dictionary D;

    initDictionary(D);

    printf(" INDEX\tELEMENTS\n");
    insertUnique(D, 10);
    insertUnique(D, 21);

    display(D);
    return 0;
}

void initDictionary(Dictionary M){
    for (int i = 0; i < MAX; ++i){
        M[i] = EMPTY;
    }
}

int hash(int x){
    return x % MAX - 1;
}

void display(Dictionary D){
    for (int i = 0; i < MAX; ++i){
        printf("%d: \t%d\n", i, D[i]);
    }
}

void insertUnique(Dictionary D, int x){
    int ndx = hash(x), sl;
    for (sl = 1; D[ndx] != x && sl != MAX && D[ndx] != EMPTY && D[ndx] != DELETED; sl++, ndx = (ndx + 1) % MAX){}
    if (D[ndx] != x && sl){
        D[ndx] = x;
    } else {
        printf("Hash value of %d exists already!\n", x);
    }
}