#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef bigint.h


int main() {
    char n1[1000], n2[1000]; // Assuming maximum input size is 1000 characters

    printf("Enter first num: ");
    scanf("%s", n1);
    printf("Enter second num: ");
    scanf("%s", n2);

    char* differ = subtractBigIntegers(n1, n2);
    printf("Differences: %s\n", differ);

    free(differ);


    char* product = multiplyBigIntegers(n1, n2);
    printf("Product: %s\n", product);

    free(product); 

    char dividend[1000]; 
    int divisor;

    printf("Enter dividend: ");
    scanf("%s", dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);
    divideBigIntegers(dividend, divisor);

    return 0;
}

#endif