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
Frac reduce(Frac s)
{
	int g;
	Frac a;
	g=gcd(s);
	a.n=s.n/g;
	a.d=s.d/g;
	return a;
}
Frac process(int n,Frac f[n])
{
	int i;
	Frac s,sf;
	s.n=f[0].n;
	s.d=f[0].d;
	for(i=1;i<n;i++)
	{
		s.n=(s.n*f[i].d)+(s.d*f[i].n);
		s.d=s.d*f[i].d;
	}
	sf=reduce(s);
	return sf;
}
void output(int n, Frac f[n],Frac sf)
{
	int i;
	printf("The sum of ");
	for(i=0;i<n-1;i++)
		printf("%d/%d + ",f[i].n,f[i].d);
	printf("%d/%d = %d/%d\n",f[i].n,f[i].d,sf.n,sf.d);
}
int main()
{
	int n;
	n=input();
	Frac f[n],sf; 
	frac_input(n,f);
	sf=process(n,f);
	output(n,f,sf);    
	return 0;
}