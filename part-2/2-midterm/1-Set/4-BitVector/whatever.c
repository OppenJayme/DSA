#include <stdio.h>
#include <stdlib.h>

void convert(int n){
    int binary[32];
    
    int i = 0;
    while (n > 0){
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }       
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);    
    printf("\n");
}



int main(){
    signed int num = -28 >> 1;

    convert(num);

    
    return 0;
}
