#include<stdio.h>
#include<stdlib.h>
int input_no_of_str()
{
    int a;
    printf("Enter the number of strings:\n");
    scanf("%d",&a);
    return a;
}
void input_ele(int n,char s[n][50])
{
    printf("Enter the strings:\n");
    for(int i=0;i<n;i++)
        scanf("%s[^\n]",s[i]);
}
int cmpstr(const void *x,const void *y)
{
	int s_x=0,s_y=0,i=0;
	while(*((char *)x+i)!='\0')
	{
		s_x+=(int)*((char *)x+i);
		i++;
	}
	i=0;
	while(*((char *)y+i)!='\0')
	{
		s_y+=(int)*((char *)y+i);
		i++;
	}
    if(s_x==s_y)
        return *(char *)x-*(char *)y;//for cases like cg,gc, the output should be cg,gc and not gc,cg, so....
    else
	    return s_x-s_y;
}
void output(int n,char s[n][50])
{
    printf("The array elements after qsort are:\n");
    for(int i=0;i<n;i++)
        puts(s[i]);
}
int main()
{
    int n;
    n=input_no_of_str();
    char s[n][50]; 
    input_ele(n,s);
    qsort(s,n,sizeof(s[0]),cmpstr);                                                    //it should be sizeof(s[0]) itself not sizeof(char)
    output(n,s);   
    return 0;
}
