#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1
#define DELETED -9999 // The purpose of marking it delete is to probe/search that slot or treat it as an occupied slot 
                     //and search the next slot untill u reach an EMPTY or occupied
#define MAX 10

// DELETED
// If you didn’t mark it (and just made it empty), then any search that depends on that probe chain would stop too early and 
// falsely report “not found”, even if the element was just a few slots later due to earlier collisions.

//🔹 Deleted slot = keep searching during lookup
//🔹 Deleted slot = can be reused during insertion
//🔹 Deleted slot ≠ completely empty (never used before)

typedef int Dictionary[MAX];

void initDictionary(Dictionary M);
int hash(int elem);
void insertUnique(Dictionary D, int x);
void display(Dictionary D);
bool isMember(Dictionary D, int x);
void deleteElem(Dictionary D, int x);
int getSearchLength(Dictionary D, int x);
float getAverageSearchLength(Dictionary D);

int main(){
    Dictionary D;

    initDictionary(D);

    printf(" INDEX\tELEMENTS\n");
    insertUnique(D, 10);
    insertUnique(D, 21);
    insertUnique(D, 23);
    insertUnique(D, 5);
    insertUnique(D, 1);
    insertUnique(D, 911);

    

    display(D);

    int elem = 5;
    bool real = isMember(D, elem);
    printf("Element %d %s\n", elem, (real == 1) ? "exists" : "doesnt exist");

    int elem2 = 5;
    int sl = getSearchLength(D, elem2);
    printf("Total search length of %d: %d\n", elem2, sl );

    float avg = getAverageSearchLength(D);
    printf("AVG Search Length: %f", avg);
    return 0;
}

void initDictionary(Dictionary M){
    for (int i = 0; i < MAX; ++i){
        M[i] = EMPTY;
    }
}

int hash(int elem) { // EX. 1234 = 10 % 10  = 0
    int sum = 0;
    while (elem != 0) {
        sum += (elem % 10);   // get the ones place
        elem /= 10;           // remove the ones place
    }
    return sum % MAX;
}

void display(Dictionary D){
    for (int i = 0; i < MAX; ++i){
        printf("%d: \t%d\n", i, D[i]);
    }
}

//SL set to 1
// search for an EMPTY SLOT
// if its Anything that is not EMpty and Deleted then move to next slot by hashValue = hashvalue + 1 % SIZE
// if the Search length is still not equal to MAX meaning we havent went around the array ( Circular array)
void insertUnique(Dictionary D, int x){
    int ndx = hash(x), sl;
    for (sl = 1; D[ndx] != x && sl != MAX && D[ndx] != EMPTY && D[ndx] != DELETED; sl++, ndx = (ndx + 1) % MAX){}
    if (D[ndx] != x){
        D[ndx] = x;
    } else {
        printf("Hash value of %d exists already!\n", x);
    }
}

bool isMember(Dictionary D, int x){
    int ndx = hash(x), sl;
    for (sl = 1; D[ndx] != x && sl != MAX && D[ndx] != EMPTY && D[ndx] != DELETED; sl++, ndx = (ndx + 1) % MAX){}
    printf("Total search legnth: %d\n", sl);
    return (D[ndx] == x) ? true : false;
}

void deleteElem(Dictionary D, int x){
    int ndx = hash(x), sl;
    for(sl = 1; D[ndx] != x && sl != MAX && D[ndx] != EMPTY && D[ndx] != DELETED; sl++, ndx = (ndx + 1) % MAX){}
    if (sl != MAX && D[ndx] == x){
        D[ndx] = DELETED;
    } else {
        printf("No element found.\n");
    }
}

int getSearchLength(Dictionary D, int x){
    int ndx = hash(x), sl;
    for(sl = 1; sl <= MAX && D[ndx] != x; sl++, ndx = (ndx + 1) % MAX){}
    return sl;
}
float getAverageSearchLength(Dictionary D){
    int totalSearch = 0, numElements = 0;
    for (int i = 0; i < MAX; ++i){
        if (D[i] != EMPTY){
            int temp = getSearchLength(D, D[i]);
            totalSearch += temp;
            numElements++;
        }     
    }
    float avgSearchLength = (float)totalSearch / numElements;
    return (numElements != 0) ? avgSearchLength : 0.0;
}



