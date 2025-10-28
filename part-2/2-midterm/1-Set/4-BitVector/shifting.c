#include <stdio.h>

// Function to display number in binary
void displayBinary(int n) {
    int i;
    printf("Binary: ");
    for (i = 7; i >= 0; i--) {  // loop through all 32 bits
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

// Function to perform left shift
int leftShift(int num, int shift) {
    return num << shift;
}

// Function to perform right shift
int rightShift(int num, int shift) {
    return num >> shift;
}

// Function to display results
void displayResult(int num, int shiftedNum, char *operation) {
    printf("\n--- %s ---\n", operation);
    printf("Original number (decimal): %d\n", num);
    displayBinary(num);
    printf("Shifted number (decimal): %d\n", shiftedNum);
    displayBinary(shiftedNum);
}

int main() {
    int num, shift;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter number of positions to shift: ");
    scanf("%d", &shift);

    int leftResult = leftShift(num, shift);
    int rightResult = rightShift(num, shift);

    displayResult(num, leftResult, "Left Shift");
    displayResult(num, rightResult, "Right Shift");

    return 0;
}
