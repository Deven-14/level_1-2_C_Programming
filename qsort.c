#include<stdio.h>
#include<stdlib.h>
int input_no_of_ele()
{
    int a;
    printf("Enter the number of elements:\n");
    scanf("%d",&a);
    return a;
}
void input_ele(int n,int a[n])
{
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}
int cmpint(const void *x,const void *y)
{
    return *(int *)x-*(int *)y;
}
void output(int n, int a[n])
{
    printf("The array elements after qsort are:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n;
    n=input_no_of_ele();
    int a[n];
    input_ele(n,a);
    qsort(&a[0],n,sizeof(a[0]),cmpint);
    output(n,a);
    return 0;
}
