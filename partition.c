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
    int i=1,j=n-1,p=a[0];
    int *p_k=&a[0],*p_l=&a[0];
    while(i<=j)                                      //i<=j constraint 2, i<n constraint 1
    {
        if(a[i]>p)
        {
            while(j>i)
            {
                if(a[j]<=p)
                {
                    *p_k=a[j];                     //a[k] became *p_k and as k holds the specific value of i, same *p_k holds the address of a[i]
                    p_l=p_k=&a[i];
                    a[j]=a[i];
                    j--;
                    break;
                }
                j--;
            }
        }
        else
            p_l=&a[i];
        i++;
    }
    *p_k=*p_l;
    *p_l=p;
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
