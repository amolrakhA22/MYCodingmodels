// C Program to demonstarte odd_even Number
// By Amol Rakh

#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number : ");
    scanf( "%d",&num);
    if ( num % 2 == 0 ) // Comparison opreater for odd-even number
    {
        printf("%d is Even number", num);
    }
    else
    {
        printf("%d is Odd number", num);
    }
    return 0;
    
}