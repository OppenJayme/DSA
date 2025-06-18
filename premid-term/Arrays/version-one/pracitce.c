#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int elemCount;
} LIST;

bool locate(LIST l, char c);

int main() {
    LIST l = {"USC", 3};
    
    bool locator = locate(l,'C');
    printf("%s", (locator == 0) ? "False" : "True");

    return 0;
}

bool locate(LIST l, char c){
    int i = 0;
    
    for (; i < l.elemCount && l.elem[i] != c; ++i){
        printf("Letter Currently at %c and i = %d\n", l.elem[i], i);
    }
    return (i < l.elemCount) ? true : false; // if i < than l.elemCount then char c is equal to l.elem[i]. if its not lower than elemCount
}
