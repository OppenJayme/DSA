#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

typedef struct {
    char LName[24];
    char FName[16];
    char Mi;
} Name;

typedef struct {
    Name studName;
    int id;
    char course[10];
    int yrlevel;
} studType;

typedef struct node{
    studType stud;
    struct node *link;
} *openStud;

typedef openStud Dic[MAX];


void initDictionary(Dic D);

int main(){
    Dic studRec = {};



    return 0;
}

Name createName(char f, char l, char mi){
    Name newName;
    strcpy(newName.FName, f);
    strcpy(newName.LName, l);
    newName.Mi = mi;
    return newName;
}
studType createStud(Name n, int id, char course[], int yearlevel){
    studType stud;
    strcpy(stud.course, course);
    stud.id = id;
    stud.yrlevel = yearlevel;
    stud.studName = n;
    return stud;
}
void initDictionary(Dic D){
    for (int i = 0; i < MAX; ++i){
        D[i] = NULL;
    }
}


int hashF(int id, int baseYearPrefix /* e.g., 21 */) {
    return id / 100000; // must have id that has 8 numbers (usc id)
}

// assuming sorted by id;
void insert(Dic D, studType stud1){
    openStud *trav;
    int key = hashF(key);

    for (trav = &D[key]; *trav != NULL && (*trav)->stud.id < stud1.id; trav = &(*trav)->link){}
    if (*trav != NULL){
        openStud newStud, temp;
        newStud->stud = stud1;
        newStud->link = *trav;
        *trav = newStud;
    }
}
