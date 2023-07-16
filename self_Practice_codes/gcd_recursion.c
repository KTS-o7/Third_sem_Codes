#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//  GCD is found by subtraction

int GCD(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return GCD(a - b, b);
    if (b > a)
        return GCD(a, b - a);
}

// gcd is found by Euclid's algorithm

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int num1, num2, res1, res2;
    printf("\nEnter the first number: ");
    scanf("%d", &num1);
    printf("\nEnter the second number : ");
    scanf("%d", &num2);
    res1 = gcd(num1, num2);
    res2 = GCD(num1, num2);
    printf("The GCD is %d and %d\n", res1, res2);
    return 0;
}