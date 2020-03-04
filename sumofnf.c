#include<stdio.h>
struct frac
{
	int n;
	int d;
};
typedef struct frac Frac;
int input()
{
	int n;
	printf("Enter the number of fractions\n");
	scanf("%d",&n);
	return n;
}
void frac_input(int n,Frac p[n])
{
	int i;
	printf("Enter the fractions (n/d):\n");
	for(i=0;i<n;i++)
		scanf("%d/%d",&p[i].n,&p[i].d);
}
Frac process(int n,Frac f[n])
{
	int i;
	Frac s;
	s.n=f[0].n;
	s.d=f[0].d;
	for(i=1;i<n;i++)
	{
		s.n=(s.n*f[i].d)+(s.d*f[i].n);
		s.d=s.d*f[i].d;
	}
	return s;
}
int gcd(Frac s) 
{	    
	int a,b,t;
	a=s.n;
	b=s.d;
	while(b>0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}
void output(int n, Frac f[n],Frac s,int g)
{
	int n1=s.n/g;
	int d1=s.d/g;
	int i;
	printf("The sum of ");
	for(i=0;i<n-1;i++)
		printf("%d/%d + ",f[i].n,f[i].d);
	printf("%d/%d = %d/%d = %d/%d\n",f[i].n,f[i].d,s.n,s.d,n1,d1);
}
int main()
{
	int n,g;
	n=input();
	Frac f[n],s;    
	frac_input(n,f);
	s=process(n,f);
	g=gcd(s);            
	output(n,f,s,g);    
	return 0;
}