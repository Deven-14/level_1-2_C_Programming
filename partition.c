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
    int i=1,j=n-1,k=0,p=a[0];
    while(i<n)
    {
        if(a[i]<=p)
        {
            a[k]=a[i];
            k++;
        }
        else
        {
            while(j>i)
            {
                if(a[j]<=p)
                {
                    a[k]=a[j];
                    k++;
                    a[j]=a[i];
                    j--;
                    break;
                }
                j--;
            }
        }
        i++;
    }
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
