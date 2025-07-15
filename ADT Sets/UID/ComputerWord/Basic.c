#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef unsigned int Set;

void insertElem(Set *S, int elem);
void deleteElem(Set *S, int elem);
void displayElem(Set S);

int main(){
    Set A;

    return 0;
}

void initSet(Set *A){
    *A = 0;
}

void insertElem(Set *S, int elem){
    *S |= 1 << elem;
}
void deleteElem(Set *S, int elem){
    *S &= ~(1 << elem);
}

bool isMember(Set s, int indx){
    return (s >> indx & 1) ? true : false;
}