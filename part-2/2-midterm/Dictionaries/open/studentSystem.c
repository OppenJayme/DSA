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
Name createName(char f[], char l[], char mi);
studType createStud(Name n, int id, char course[], int yearlevel);
int hashF(int id);
void insert(Dic D, studType stud1);
bool isMember(Dic D, studType stud);
void delete(Dic D, int id);
void display(Dic D);

int main(){
    Dic studRec = {};

    initDictionary(studRec);

    studType stud1 = createStud(createName("Kyer Ivan", "Jayme", 'C'), 23104847, "BSIT", 3);
    insert(studRec, stud1);

    studType stud2 = createStud(createName("Kentward", "Maratas", 'C'), 23100003, "BSIT", 3);
    insert(studRec, stud2);

    studType stud3 = createStud(createName("Clareicne", "Diangzco", 'C'), 23101045, "BSIT", 3);
    insert(studRec, stud3);

    studType stud4 = createStud(createName("John Mark", "Gerozaga", 'C'), 7139741, "BSIT", 3);
    insert(studRec, stud4);

    studType stud5 = createStud(createName("John Cena", "yes", 'C'), 25104297, "BSIT", 3);
    insert(studRec, stud5);

    printf("Index\tStudent Id\n");
    display(studRec);

    return 0;
}

Name createName(char f[], char l[], char mi){
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


int hashF(int id) {
    int firstTwo = (id / 1000000) % 100;   // e.g., 23101234 → 23 
    return firstTwo % MAX;        
}

// assuming sorted by id;
void insert(Dic D, studType stud1){
    openStud *trav, newStud;
    int key = hashF(stud1.id);

    for (trav = &D[key]; *trav != NULL && (*trav)->stud.id < stud1.id; trav = &(*trav)->link){}
    // traverses the dictionary of that group, finds the element that is bigger than the student and insert before it.

    newStud = (openStud) malloc(sizeof(struct node));
    if (newStud != NULL) {
        newStud->stud = stud1;
        newStud->link = *trav;
        *trav = newStud;  
    }
}

bool isMember(Dic D, studType stud){
    int key = hashF(stud.id);
    openStud trav;
    for (trav = D[key]; trav != NULL && trav->stud.id != stud.id; trav = trav->link){}
    return (trav != NULL) ? true : false;
}

void delete(Dic D, int id){
    int key = hashF(id);
    openStud *trav;

    for (trav = &D[key]; *trav != NULL && (*trav)->stud.id != id; trav = &(*trav)->link){}
    if (*trav != NULL){
        openStud temp;
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void display(Dic D){
    openStud trav;

    for (int i = 0; i < MAX; ++i){
        printf("[%d]\t", i+1);
        if (D[i] == NULL){
            printf("NULL\n");
        } else {
            for (trav = D[i]; trav != NULL; trav = trav->link){
                printf("%d%s", trav->stud.id, trav->link ? "-> " : ".\n");
            }
        }
    }
}
