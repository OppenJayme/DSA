#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define EMPTY -1
#define DELETED -99

typedef int Dic[MAX];

void initDic(Dic D);

int main(){




    return 0;
}

void initDic(Dic D){
    for (int i = 0; i < MAX; ++i){
        D[i] = EMPTY;
    }
}

int hashF(int n){
    int hash = 0;
    while (hash != 0){
        hash = hash + (n % 10);
        hash = hash / 10; // hash /= 10
    }
    return hash;
}

//GOLDEN RULES!
// keep track of deleted
// if deleted was found first, search next until next empty or is full, still insert at deleted
// if empty was found first then insert immediately
// if no empty no deleted was found then its full!
void insertUnique(int c, Dic D){
    int key = hashF(c);
    int sl, firstDelete = -1;

    for (sl =  1; sl < MAX; ++sl){
        // 
        if (D[key] == c){
            printf("Duplicate Exists\n");
            return;
        }
        // FIRST INSTANCE OF DELETED!
        if (firstDelete == -1 && D[key] == DELETED){
            firstDelete = key;
        }

        // EMPTY SPOT, stop here but check if there is firstdeleted or not then insert there 
        // deleted = insert there
        // no deleted = insert at EMPTY
        if (D[key] == EMPTY) {
            if (firstDelete != -1){
                D[firstDelete] = c;
            } else {
                D[key] = c;
            }
            return 
        }
        key = (key + 1) % MAX;
        // if its full
    }
    if (firstDelete != -1) {
        D[firstDelete] = c; 
    } else {
        printf("FULL\n!");
    }
}

void deleteMember(int c, Dic D){
    int key = hash(c);
    for (int i = 0; i < MAX && D[key] != EMPTY && D[key] != c; ++i, key = (key + 1) % MAX){}
        if (D[key] == c){ 
            D[key] = DELETED; 
        }
}

int searchLength(int c, Dic D){
    int key = hashF(c), sl;
    for (sl = 1; sl != MAX && D[key] != c; sl++, key = (key + 1) % MAX){}
    return sl;
}

bool isMember(int c, Dic D){
    int key = hashF(c), sl;
    for (sl = 1; sl != MAX && D[key] != c ; )
}