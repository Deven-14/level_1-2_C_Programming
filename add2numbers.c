#include<stdio.h>

int input_ith_num(int i)
{
    int num;
    printf("Enter number %d to be added: ", i);
    scanf("%d", &num);
    return num;
}

int add(int num1, int num2)
{
    return num1 + num2;
}

void print_sum(int num1,int num2,int sum)
{
    printf("%d + %d = %d\n", num1, num2, sum);
}

int main()
{
    int num1, num2, sum;
    num1 = input_ith_num(1);
    num2 = input_ith_num(2);
    sum = add(num1, num2);
    print_sum(num1, num2, sum);
    return 0;
}
