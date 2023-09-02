/*************************
NAME : SAMAPTI CHAR
PROGRAM :MULTIPLY FIRST N NATURAL NUMBERS
Program no : 08
Date :  2021.02.17
**************************/
#include<stdio.h>
long int multiplyNumbers(int n);
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("product of %d numbers= %ld", n, multiplyNumbers(n));
    return 0;
}

long int multiplyNumbers(int n) {
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}

