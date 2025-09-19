#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int count;
} LIST;

LIST getEven(LIST L);

int main(){
    LIST mainList = {{24,1,23,14,10}, 5};
    LIST even = getEven(mainList);

    for (int i = 0; i < even.count; ++i){
        printf("%d", even.data[i]);
        printf("%s", (i < even.count - 1) ? ", " : ".\n");
    }
    return 0;
}

LIST getEven(LIST L){
    LIST evenArr;
    evenArr.count = 0;

    for (int i = 0; i < L.count; ++i){
        if ((L.data[i] % 2) == 0){
            evenArr.data[evenArr.count++] = L.data[i] ;
        }
    }
    return evenArr;
}