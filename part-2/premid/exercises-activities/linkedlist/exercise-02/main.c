#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
  }*charList; 

  /*
  Activity:
A)  Declare a variable of type charList. How many bytes is allocated to variable of charList?
    Assume that after the declaration, there are statements that will populate the list with 3 elements.
    Draw the list with 3 elements. For each variable, draw a box and label the box with a name, value, and address.
*/

int main(){
    charList L; // 8 bytes
}

/*
B)  Given a function specification:
    Given a list and an element X, function findElem() will return true if element X is in the list; otherwise return false.
    Note:  The header file stdbool.h has a bool data type with values: true and false
    Constraints:  Only 1 return statement
                  No break and continue statements

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
    charList trav;
    for (trav = L; trav != NULL && trav->elem != data; trav = trav->link){}
    return (trav != NULL) ? true : false;
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

void deleteData(charList *L, char data){
    charList *trav;
    for(trav = L; trav != NULL && (*trav)->letter.data != data; trav = &(*trav)->link){}
    charList temp = *trav;
    *trav = temp->link;
    free(temp);
}