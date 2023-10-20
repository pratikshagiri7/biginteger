#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef bigint.c
#define bigint.c


// Function to subtract two large integers represented as strings
char* subtractBigIntegers(char* n1, char* n2) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int maxLen = (len1 > len2) ? len1 : len2;
    char* result = (char*)malloc((maxLen + 1) * sizeof(char)); // +1 for digits and null terminator
    result[maxLen] = '\0';

    int carry = 0;
    int i, j, k;

    for (i = len1 - 1, j = len2 - 1, k = maxLen - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;

        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result[k] = diff + '0';
    }

    // Trim leading zeros from the result
    int startIndex = 0;
    while (result[startIndex] == '0' && result[startIndex + 1] != '\0') {
        startIndex++;
    }

    if (startIndex > 0) {
        for (int i = 0; i <= maxLen - startIndex; i++) {
            result[i] = result[i + startIndex];
        }
    }

    return result;
}



int max(int a, int b) {
    return (a > b) ? a : b;
}

char* multiplyBigIntegers(const char* n1, const char* n2) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int maxLength = len1 + len2; 
    int* result = (int*)malloc(maxLength * sizeof(int));

    for (int i = 0; i < maxLength; i++) {
        result[i] = 0;
    }
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int digit1 = n1[i] - '0';

        for (int j = len2 - 1, k = i + j + 1; j >= 0; j--, k--) {
            int digit2 = n2[j] - '0';
            int product = digit1 * digit2 + result[k] + carry;

            result[k] = product % 10;
            carry = product / 10;
        }

        result[i] += carry;
    }
    char* product = (char*)malloc((maxLength + 1) * sizeof(char));
    int start = 0;
    while (start < maxLength && result[start] == 0) {
        start++;
    }

    int k = 0;
    for (int i = start; i < maxLength; i++) {
        product[k++] = result[i] + '0';
    }
    product[k] = '\0';

    free(result); 
    return product;
}


void divideBigIntegers(char* dividend, int divisor) {
    int len = strlen(dividend);
    int quotient[len];
    int temp = 0;

    for (int i = 0; i < len; i++) {
        quotient[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        temp = temp * 10 + (dividend[i] - '0');
        quotient[i] = temp / divisor;
        temp = temp % divisor;
    }

    int startIndex = 0;
    while (startIndex < len && quotient[startIndex] == 0) {
        startIndex++;
    }
    if (startIndex == len) {
        printf("Quotient: 0\n");
        return;
    }

    printf("Quotient: ");
    for (int i = startIndex; i < len; i++) {
        printf("%d", quotient[i]);
    }
    printf("\nRemainder: %d\n", temp);
}

#endif