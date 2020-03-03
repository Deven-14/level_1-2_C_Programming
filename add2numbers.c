#include<stdio.h>
int input()
{
    int a;
    printf("Enter a number:\n");
    scanf("%d",&a);
    return a;
}
int process(int a, int b)
{
    int sum=a+b;
    return sum;
}
void output(int a,int b,int sum)
{
    printf("The sum of %d + %d = %d",a,b,sum)
}
int main()
{
    int a,b,sum;
    a=input();
    b=input();
    sum=process(a,b);
    output(a,b,sum);
    return 0;
}