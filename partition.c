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
    int i=0,j=n-1,m=0,p=a[0];
    while(i!=j)
    {
        while(j>i)
        {
            if(a[j]<=p)  // j should be above i while finding, because we are putting i=0...order of finding j and i matters....
            {
                a[i]=a[j];
                m=j;
                j=i;
            }
            j--;
        }
        j=m;
        while(i<j)
        {
            if(a[i]>p)
            {
                a[j]=a[i];
                m=i;
                i=j;
            }
            i++;
        }
        i=m;
    }
    a[j]=p;
}
void output(int n, int a[n])
{
    printf("The array elements after partition with constraint 3 are:\n");
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
