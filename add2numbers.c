#include<stdio.h>

int input_num(char* ordinal_num)
{
    int num;
    printf("Enter %s number to be added: ", ordinal_num);
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
    num1 = input_num("1st");
    num2 = input_num("2nd");
    sum = add(num1, num2);
    print_sum(num1, num2, sum);
    return 0;
}
