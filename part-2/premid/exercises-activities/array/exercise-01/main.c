#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// A)  Write an appropriate definition of datatype charList. In addition, define MAX as a macro name for the maximum size of the array.

typedef struct {
    char elem[MAX];
    int count;
} charList;

/*B)  Given a function specification:
    Given a list and an element X, function findElem() will return true if element X is in the list; otherwise return false.
    Note:  The header file stdbool.h has a bool data type with values: true and false
    Constraints:  Only 1 return statement
                  No break and continue statement

    Do the following steps to better understand functions and how to create them:
    1)  Write an appropriate function header of function findElem().
    2)  Write an appropriate function call. Before the call, declare the variable/s used in the call and 
        initialize the variable/s if necessary. Note: Do not pass garbage values to the called function.
    3)  Assume that the function call in #2 is in main() function, draw the execution stack (call stack) representing the call.
        For each variable, draw a box and label it with name, value, and address. Note: You can use arbitrary addresses such as A100, B100, etc.
    4)  Write the code of the function findElem().
    5)  Simulate the function using the following test cases:
        a) the list is empty
        b) the list is not empty and element X is in the list
        c) the list is not empty and element X is not in the list  
*/

bool findElem(charList L, char data){
    int i;
    for (i = 0; i < L.count && L.elem[i] != data; ++i){}
    return (i < L.count) ? true : false;
}

/*
C) Given a function specification:
   Given a list and an element X, function deleteElem() will remove the 1st occurrence of element X from the list.
   Constraint: NO break and continue statements
   TO DO: Perform 5 steps in B)
   Modified Test Cases:
     a) List is not empty and element X is at the
         i) first position in the list
        ii) last position in the list
       iii) middle position in the list
     b) List is not empty and element X is not in the list
     c) List is empty    
*/

void deleteElem(charList *L, char data){
    int i = 0;
    for (; i < L.count && L->elem[i] != data; ++i){}

    if (i < L.count){
        for (int j = i; j < L->count - 1; j++){
            L->elem[j] = L->elem[j + 1];
        }
        L->count--;
    }
}

/*
    D) Given a function specification:
   Given a list and an element X, function deleteAllOccur() will remove all occurrences of element X from the list.
   Constraint: NO break and continue statements
   TO DO: Perform steps 1-4 in B) and Test cases in C)
*/

void deleteAllOccur(charList *L, char data) {
    int write = 0;                  // next position to keep
    for (int i = 0; i < L->count; ++i) {
        if (L->elem[i] != data){  // keep only non-matching chars
            L->elem[write++] = L->elem[i];
        }
    }
    L->count = write;               // shrink logical size
    // (Optional) clear the tail for cleanliness:
    // for (int i = write; i < MAX; ++i) L->elem[i] = '\0';
}

