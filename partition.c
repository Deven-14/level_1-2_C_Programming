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
    int temp=*a;
    *a=*b;
    *b=temp;
}
void partition(int n, int a[n])
{
    int i,k=1;
    for(i=1;i<n;i++)                                                                                      //for all ele<=pivot
    {
        if(a[0]>=a[i])
        {
            swap(&a[k],&a[i]);                                                                            //no problem if i swap a[i] with a[i]
            k++;
        }
    }
    swap(&a[k-1],&a[0]);                                                                                  //swapping pivot with the last ele<=pivot
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
