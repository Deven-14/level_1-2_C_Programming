#include<stdio.h>

int input_no_of_integers()
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    return n;
}

void input_integers(int n, int numbers[])
{
    printf("Enter the intergers: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
}

int add(int n, int numbers[])
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += numbers[i];
    return sum;
}

void print_sum(int n , int numbers[n], int sum)
{
    for(int i = 0; i < n-1; ++i)
        printf("%d + ", numbers[i]);
    printf("%d = %d", numbers[n-1], sum);
}

int main()
{
    int n = input_no_of_integers();
    int numbers[n];
    input_integers(n, numbers);
    int sum = add(n, numbers);
    print_sum(n, numbers, sum);
    return 0;
}