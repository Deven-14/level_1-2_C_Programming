#include<stdio.h>

int main()
{
    int num1, num2;
    printf("Enter two integers to be added: ");
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, sum);
    return 0;
}