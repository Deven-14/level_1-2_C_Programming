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
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int find_larger_element_from_left_bw_interval(int i,int j, int a[])
{
    while(i<=j)
    {
        if(a[i]>a[0])
            break;
        i++;
    }
    return i;
}
int find_smaller_element_from_right_bw_interval(int i,int j, int a[])
{
    while(j>i)
    {
        if(a[j]<=a[0])
            break;
        j--;
    }
    return j;
}
void partition(int n, int a[n])
{
    int i=1,i1,j1,j=n-1,p=a[0];
    i=find_larger_element_from_left_bw_interval(i,j,a);
    j=find_smaller_element_from_right_bw_interval(i,j,a);
    while(i<j)
    {
        i1=find_larger_element_from_left_bw_interval(i+1,j-1,a);
        j1=find_smaller_element_from_right_bw_interval(i1,j-1,a);
        if(i1!=i && j1!=j && i1<j1)
        {
            swap(&a[i],&a[j]);
            i=i1;
            j=j1;
        }
        else if(i!=j && i1==j1)
        {
            if(i1!=i+1)
            {
                swap(&a[i],&a[j]);
                swap(&a[i1-1],&a[0]);
                break;
            }
            else
            {
                a[0]=a[j];
                a[j]=a[i];
                a[i]=p;
                break;
            }
        }
        else if(i1>j1)
        {
            swap(&a[i],&a[j]);
            swap(&a[0],&a[i1-1]);
            break;
        }
    }
    if(i>=j)
        swap(&a[i-1],&a[0]);
}
void output(int n, int a[n])
{
    printf("The array elements after partition with efficient(trial to remove l,k) constraint 1 and 2 are:\n");
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
