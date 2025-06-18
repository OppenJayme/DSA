// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int elemCount;
} LIST;

bool locate(LIST l, char c);
void reversal(LIST *l);

int main() {
    LIST l = {"gwapo", 5};
    
    bool locator = locate(l,'D');
    printf("%s\n", (locator == 0) ? "False" : "True");
    
    reversal(&l);
    for (int i = 0; i < l.elemCount;++i) {
        printf("%c", l.elem[i]);
    }
    
    return 0;
}

bool locate(LIST l, char c){
    int i = 0;
    
    for (; i < l.elemCount && l.elem[i] != c; ++i){
        printf("Letter Currently at %c and i = %d\n", l.elem[i], i);
    }
    return (i < l.elemCount) ? true : false; // if i < than l.elemCount then char c is equal to l.elem[i]. if its not lower than elemCount
}

void reversal(LIST *l){
    int i;
    int j = 0;
    int median = l->elemCount / 2; 
        for (i = l->elemCount-1; i > 0;  --i){ 
            if (i - j != 1 || (i != median && j != median)){
                char temp = l->elem[i];
                l->elem[i] = l->elem[j];
                l->elem[j] = temp;
            }
            j++;
        }
}
