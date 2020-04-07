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
    int i=1,j=n-1;
    while(a[j]>a[0])
    {
        j--;
    }
     while(a[i]<=a[0])
    {
        i++;
    }
    while(j>i)
    {
        swap(&a[i],&a[j]);// where swap is placed also matters...
        i++;
        j--;
        while(a[j]>a[0]) //"the last element gets swapped twice(last ele and pivot is one of the 2 cases)--allowed"
        {
            j--;
        }
         while(a[i]<=a[0]) //smaller element is swapped last, so j has to be found first.....order of finding j and i matters....
        {
            i++;
        }
    }
    swap(&a[j],&a[0]);// only i>j case gets terminated
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
