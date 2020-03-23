#include<stdio.h>
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
void partition(int n, int a[n])
{
    int i,j=0,k=0,p=0;
    p=a[0];
    for(i=1;i<n;i++)                                                                                             //for all ele<=pivot
    {
        if(p>=a[i])
        {
            a[k]=a[i];
            j=i;
            k++;
        }
    }
    a[j]=a[k];//next ele after shifting all ele <= pivot to the left
    a[k]=p;
}
void output(int n, int a[n])
{
    printf("The array elements after partition with constraint 1 are:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n;
    n=input_no_of_ele();
    int a[n];
    input_ele(n,a);
    partition(n,a);
    output(n,a);
    return 0;
}
