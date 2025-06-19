# What it means
- A pointer is a variable that stores the memory address of another variable.
Ex. 
int x = 5;
int *p = &x;  // p points to the address of x

But you can do this too

int *p = malloc(sizeof(int)); // allocates memory for an int
*p = 5; // store value 5 in that newly allocated memory

# What i Think Always

If the structure is a pointer to a structure type:
typedef struct node {
} *structureType

Its syntax will always be ->
and if you are NOT pointing to a structure type:
jsut stick with the . syntax

Pointer to a structure Type
(*L)->
No pointer/Alias only
L.


