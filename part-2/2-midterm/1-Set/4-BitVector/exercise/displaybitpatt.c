#include <stdio.h>
#include <stdlib.h>

typedef int SET;

void displayBit(int num);
void displayBitC(char C);
int returnThird(int num);

int main(){
    SET a = 0;
    int test = 2;
    char test2 = 'c';

    displayBit(test);
    printf("\n");
    displayBitC(test2);
    printf("\n");

    int third = returnThird(test);
    printf("%d", third);

    return 0;
}

void displayBit(int num){
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    for (; mask > 0; mask = mask >> 1){
        printf("%d", ((num & mask) != 0) ? 1 : 0);
    }
}

void displayBitC(char num){
    unsigned char mask = 1 << (sizeof(char) * 8 - 1);
    for (; mask > 0; mask = mask >> 1){
        printf("%d", ((num & mask) != 0) ? 1 : 0);
    }
}

// display third exercise 2
int returnThird(int num){
    return ((num & (1 << 2)) != 0) ? 1 : 0;
}

//insert into position exercise 3
void insert(SET *num, int pos){
    int mask = 1 << (pos - 1); // 0001 will be placed at where pos is at so say pos 4 then 1 should be shifted until 1000 so 0001 -> 1000
    *num = (*num) | mask; // so at num since its 0000 (32 0's) at the position where mask is at it will always be 1 since 1 or 0 or 1 or 0 is always 1;
}

//delete at pos exercise 4
void delete(SET *num, int pos){
    int mask = 1 << (pos - 1); // position where to delete
    *num = (*num) & ~(mask);  // at position is 1, so mask is complemented (1 -> 0) 1 and 0 is 0;
}

