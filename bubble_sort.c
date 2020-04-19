#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int input_no_of_str()
{
    int a;
    printf("Enter the number of strings:\n");
    scanf("%d",&a);
    return a;
}
void input_ele(int n,char *s[n])
{
	for(int i=0;i<n;i++)
		s[i]=(char *)malloc(50*sizeof(char));
    printf("Enter the strings:\n");
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
}
int cmpstr(const void *x,const void *y)
{
	return strcmp(*(const char **)x,*(const char **)y);
}
void bubblesort(void *base,size_t nmemb,size_t size,int (*compare)(const void*,const void*))
{
	int i,j,x,k;
	char temp;                                                                                       //since we are swapping bit by bit we don't need char* only char is enough
	for(i=0;i<nmemb-1;i++)
	{
		for(j=0;j<nmemb-i-1;j++)
		{
			x=compare((base+(size*j)),(base+(size*(j+1))));                                          //(base+j)and(base+j+1)is wrong as the void pointer won't know after how many bits is the next one
			if(x>0)                                                                                  //i.e if *(base+i) is greater
			{                                                                                        //cannot dereference a void pointer obviously because it won't know how many bits of data to accessed, we have to type cast to dereference
				k=0;
				while(k!=size)                                                                       //swapping each bit untill it the required bit size is reached
				{
					temp=*((char*)base+(size*j)+k);                                                  //*********not*(char*)(base+j+k),but*((char*)base+j+k)
					*((char*)base+(size*j)+k)=*((char*)base+(size*(j+1))+k);
					*((char*)base+(size*(j+1))+k)=temp;
					k++;
				}
			}
		}
	}
}
void output(int n,char *s[n])
{
	printf("The array elements after bubblesort are:\n");
	for(int i=0;i<n;i++)
		puts(s[i]);
	for(int i=0;i<n;i++)
	{
		free(s[i]);
		s[i]=NULL;
	}
}
int main()
{
    int n;
    n=input_no_of_str();
    char *s[n];                                                                                            //s is the name of the pointer as well as the string name, that's y 1st argument in qsort is &s[0] and in puts we no need to use *s[i], just s[i]
    input_ele(n,s);
    bubblesort(s,n,sizeof(char *),cmpstr);                                                                  // sizeof(char *) is same as sizeof(s[0]), and first argument can be &s[0] or s
    output(n,s);
    return 0;
}
