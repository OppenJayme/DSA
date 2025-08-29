/*
For each of the implementations (Array and Linked list), write the code of the following insert and delete operations:
Constraints:  One(1) return statement ONLY if the function’s return type is not void.
               NO break or exit statement 

1) insertFirst(). The function will insert the given element at the first position of the given list.
2) insertLast(). The function will insert the given element at the last position of the given list.
3) insertLastUnique(). The function will insert the given element at the last position of the given 
list if the element does not yet exist. Elements are uniquely identified through the ID.
4) insertAtPosition(). The function will insert a given element at the given valid position in the given list. 
Note the position is integral and may not be valid.
5) deleteElem(). The function will delete the element bearing the given ID in the given list. In addition, the 
deleted element will be returned to the calling function. If no element is deleted, a dummy variable is returned 
to the calling function containing “XXXXX”, ‘X, and 0 (zero) for string, char, and integer fields respectively.
6) separateCourse(). The function will remove from the given list all elements bearing the given course and put 
them in a new list which will be returned to the calling function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARR_LENGTH 0XA
#include <string.h>

typedef struct {
    char FN[24];
    char MI;
    char LN[16];
} nametype;

typedef struct {
    char ID[9];
    nametype name;
    char course[8]; 
    int yrlevel;
} studtype;

typedef struct {
    studtype studs[ARR_LENGTH];
    int count;
} ArrayList;

typedef struct cell{
     studtype stud;
    struct cell *Link
} *LinkList;

// array Implementation
void insertFirstArr(ArrayList *A, studtype student);
void insertLastArr(ArrayList *A, studtype student);
void insertLastUniqueArr(ArrayList *A, studtype student);
void insertAtPositionArr(ArrayList *A, studtype student, int position);
studtype deleteElemArr(ArrayList *A, studtype student, char id[]);
void seperateCourseArr(ArrayList *A, studtype student);

//LinkedList Implemnetation

void insertFirstLL(LinkList *A, studtype student);
void insertLastLL(LinkList *A, studtype student);
void insertLastUniqueLL(LinkList *A, studtype student);
void insertAtPositionLL(LinkList *A, studtype student, int position);
void deleteElemLL(LinkList *A, studtype student);
void seperateCourseLL(LinkList *A, studtype student);


// helper
void initArrList(ArrayList *A);
void initLinkedList(LinkList *L);
studtype createStud(char id[], nametype name, int year);
nametype createName(char FN[], char MI, char LN[]);

int main(){
    ArrayList college;
    LinkList Highschool;

    studtype name1 = createstud("23104847", createName("Kyer Ivan",'C',"Jayme"), 3);
    studtype name2 = createstud("23000003", createName("Kentward",'C',"Maratas"), 3);

    insertFirstArr(&college, name1);





    return 0;
}

void insertFirstArr(ArrayList *A, studtype student){
     if (A->count < ARR_LENGTH){
        for (int i = A->count; i > 0; --i){
            A->studs[i] = A->studs[i - 1];
        }
        A->studs[0] = student;
        A->count++;
    } else {
        printf("FULL!");
    }
}
void insertLastArr(ArrayList *A, studtype student) {
    (A->count < ARR_LENGTH) ? A->studs[A->count++] = student : printf("List is FULL!\n");
}

void insertLastUniqueArr(ArrayList *A, studtype student) {
    int found = 0;

    for (int i = 0; i < A->count; i++) {
        if (strcmp(A->studs[i].ID, student.ID) == 0) {
            found = 1;
        }
    }

    (A->count < ARR_LENGTH && !found) 
        ? (A->studs[A->count++] = student)
        : (found ? printf("Duplicate ID Found\n") : printf("List is FULL\n"));
}

void insertAtPositionArr(ArrayList *A, studtype student, int position){

    if (position < 0 || position > A->count){
        printf("Out of bounds!");
    }
    if (A->count >= ARR_LENGTH){
        printf("Full!");
    }

    for (int i = A->count; i > position; --i){
        A->studs[i] = A->studs[i - 1];
    }
    if (A->count < ARR_LENGTH){
        A->studs[position] = student;
        A->count++;
    }
}
/*5) deleteElem(). The function will delete the element bearing the given ID in the given list. In addition, the 
deleted element will be returned to the calling function. If no element is deleted, a dummy variable is returned 
to the calling function containing “XXXXX”, ‘X, and 0 (zero) for string, char, and integer fields respectively.
*/
studtype deleteElemArr(ArrayList *A, studtype student, char id[]) {
    int i = 0;
    for (; i < A->count && strcmp(A->studs[i].ID, id) != 0; ++i) {}

    studtype result = (i < A->count) ? A->studs[i]
                                     : (studtype){"XXXXX", {'X',"XXXXX",'X'}, 0};

    if (i < A->count) {
        for (int j = i; j < A->count - 1; ++j)
            A->studs[j] = A->studs[j + 1];
        A->count--;
    }
    return result;
}
//6) separateCourse(). The function will remove from the given list all elements bearing the given course and put 
//them in a new list which will be returned to the calling function.
ArrayList seperateCourseArr(ArrayList *A, char course[]){
    ArrayList newList;
    newList.count = 0;
    int i = 0;

    for (; i < A->count; ++i){
        if (strcmp(A->studs[i].course, course) == 0){
            if (newList.count < ARR_LENGTH){
                newList.studs[newList.count++] = A->studs[i];
                for (int j = i; j < A->count - 1; ++j){
                    A->studs[j] = A->studs[j + 1];
                    A->count--;
                }
            }
        }
    }
    return newList;
    
}

void initArrList(ArrayList *A){
    A->count = 0;
}

void initLinkedList(LinkList *L){
    *L = NULL;
}
nametype createName(char FN[], char MI, char LN[]){
    nametype name;
    strcpy(name.FN, FN);
    name.MI = MI;
    strcpy(name.LN, LN);
    return name;
}

studtype createStud(char id[], nametype name, int year){
    studtype gwapo;
    strcpy(gwapo.ID, id);
    gwapo.name = name;
    gwapo.yrlevel = year;
    return gwapo;
}