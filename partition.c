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
    while(k>i && a[k]>a[0])
    {
          k--;
    }
    if(a[k]<=a[0])
    {
        swap(&a[0],&a[k]);
        j=k-1;
    }
    while(j>i)
    {
         while(i<j && a[i]<=a[k]) // j and i swpped then, we have to find next i and then j.....order of finding j and i matters....
        {
            i++;
        }
        while(j>i && a[j]>a[k]) //"the last element gets swapped twice(last ele and pivot is one of the 2 cases)--allowed"
        {
            j--;
        }
        if(j>i)
        {
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }
    if((i==j && a[i]>a[k]) || i>j)
        swap(&a[i],&a[k]);
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
