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
void bubblesort(void *base,size_t nmemb,size_t size,int (*compare)(const void*,const void*))
{
	int i,j,x,k;
	char *temp;                                                                                    //making it char because we are swapping it bit wise(void pointer can't be dereferenced)
	temp=(char*)malloc(size);
	for(i=0;i<nmemb-1;i++)
	{
		for(j=0;j<nmemb-i-1;j++)
		{
			x=compare((base+j),(base+j+1));
			if(x>0)                                                                                  //i.e if *(base+i) is greater
			{                                                                                        //cannot dereference a void pointer obviously because it won't know how many bits of data to accessed, we have to type cast to dereference
				k=0;
				while(k!=size)                                                                       //swapping each bit untill it the required bit size is reached
				{
					*temp=*(char*)(base+j+k);
					*(char*)(base+j+k)=*(char*)(base+j+1+k);
					*(char*)(base+j+1+k)=*temp;
					k++;
				}
			}
		}
	}
	free(temp);
	temp=NULL;
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
	bubblesort(a,n,sizeof(a[0]),cmpint);
    output(n,a);
    return 0;
}
