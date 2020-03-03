#include<stdio.h>
int input()
{
    int n;
    printf("Enter the number of inputs\n");
    scanf("%d",&n);
    return n;
}
void array_input(int n,int a[n])
{
    int i;
    printf("Enter the intergers\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
int process(intn,int a[n])
{
    int i,sum=0;
    for(i=0;i<n;i++)
        sum+=a[i];
    return sum;
}
void output(int n,int a[n],int sum)
{
    int i;
    printf("The sum of ");
    for(i=0;i<n-1;i++)
        printf("%d+",a[i]);
    printf("%d=%d",a[i],sum);
}
int main()
{
    int n,sum;
    n=input();
    int a[n];
    array_input(n,a[n]);
    sum=process(n,a[n]);
    output(n,a[n],sum);
    return 0;
}