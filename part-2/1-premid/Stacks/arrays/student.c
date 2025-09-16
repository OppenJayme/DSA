#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
} studType;

typedef struct {
    studType name;
    int id;
    int yearlvl;
    char course[20];
} studRec;

typedef struct {
    studRec studs[MAX];
    int top;
} studStack;

void initStack(studStack *s);
studType createName(char Fname[], char Lname[], char mi);
studRec createStudRec(int id, int yrlvl, char course[], studType stud1);
void initStack(studStack *s);
bool isEmpty(studStack s);
bool isFull(studStack s);
void push(studStack *s, studRec stud1);
void pop(studStack *s);
void display(studStack s);
studRec top(studStack s);

int main(){
    studStack s;
    initStack(&s);

    studRec stud1 = createStudRec(23104847, 3, "BSIT", createName("Kyer Ivan", "Jayme", 'C'));
    push(&s, stud1);
    display(s);

    printf("---------------------\n");
    
    studRec stud2 = createStudRec(2300003, 3, "BSIT", createName("Kenward", "Maratas", 'C'));
    push(&s, stud2);
    display(s);

    printf("---------------------\n");
    pop(&s);
    display(s);

    return 0;
}

studType createName(char Fname[], char Lname[], char mi){
    studType here;
    strcpy(here.FName,Fname);
    strcpy(here.LName, Lname);
    here.MI = mi;
    return here;
}

studRec createStudRec(int id, int yrlvl, char course[], studType stud1){
    studRec stud;
    stud.id = id;
    stud.yearlvl = yrlvl;
    strcpy(stud.course, course);
    strcpy(stud.name.FName, stud1.FName);
    strcpy(stud.name.LName, stud1.LName);
    stud.name.MI = stud1.MI;
    return stud;
}

void initStack(studStack *s){
    s->top = -1;
}

bool isEmpty(studStack s){
    return (s.top == -1) ? true: false;
}

bool isFull(studStack s){
    return (s.top == MAX - 1) ? true : false;
}

void push(studStack *s, studRec stud1){
    if (!isFull(*s)){
        s->studs[++(s->top)] = stud1;
    }
}

void pop(studStack *s){
    if (!isEmpty(*s)){
        s->top--;
    }
}

studRec top(studStack s){
    return s.studs[s.top];
}

void display(studStack s){
    if (isEmpty(s)){
        printf("empty!\n");
    }
    while (!isEmpty(s)){
        studRec top1 = top(s);
        printf("Full Name: %s, %s, %c\n", top1.name.FName, top1.name.LName, top1.name.MI);
        printf("Student ID: %d\n", top1.id);
        printf("Student Year Level: %d\n", top1.yearlvl);
        printf("Student Course %s\n", top1.course);
        pop(&s);
    }
}