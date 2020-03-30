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
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void partition(int n, int a[n])
{
    int i=0,j,k=n-1;
    while(a[k]>a[0])
    {
          k--;
    }
    if(a[k]<=a[0])
    {
        swap(&a[0],&a[k]);
        i++;
    }
    j=k-1;
    while(j>=i)
    {
        while(a[j]>a[k]) // j should be above i while finding, because at last it will be i>j, and then we can swap a[i] with pivot,"the last element gets swapped twice(last ele and pivot is one of the 2 cases)--allowed"...order of finding j and i matters....
        {
            j--;
        }
        while(i<=j && a[i]<=a[k])
        {
            i++;
        }
        if(a[i]>a[k] && j>i)
        {
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
        if(i>j && i<n)
            swap(&a[i],&a[k]);
    }
}
void output(int n, int a[n])
{
    printf("The array elements after partition with constraint 4 are:\n");
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
