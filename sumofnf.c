#include<stdio.h>
struct frac
{
	int n;
	int d;
};
typedef struct frac Frac;
struct sum
{
	int sn;
	int sd;
};
typedef struct sum Sum;
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
Sum process(int n,Frac f[n])
{
	int i;
	Sum s;
	s.sn=f[0].n;
	s.sd=f[0].d;
	for(i=1;i<n;i++)
	{
		s.sn=(s.sn*f[i].d)+(s.sd*f[i].n);
		s.sd=s.sd*f[i].d;
	}
	return s;
}
/*
Sum gcd()      //do not pass 'Sum s' as an argument because then it'll be call by reference
{
	Sum p;      //this acts as pass by value and we can store the return value in another variable of the structure
	int t;  //p should'nt have any value?y is it working
	while(p.sd>0)
	{
		t=p.sd;
		p.sd=p.sn%p.sd;
		p.sn=t;
	}
	return p;
}
 */
int gcd(Sum s)
{
	int i,gcd;
	for(i = 1; i <= s.sn && i <= s.sd; i++)
	{
		if(s.sn % i == 0 && s.sd % i == 0)
			gcd = i;
	}
	return gcd;
}
void output(int n, Frac f[n],Sum s,int g)   //,Sum s_gcd
{
	/*
	int sofn=s.sn/s_gcd.sn;
	int sofd=s.sd/s_gcd.sn;   //it has to be s_gcd.sn itself, as we are dividing the numerator and denominator with the gcd which is stored in s_gcd.sn
	 */
	
	int sofn=s.sn/g;
	int sofd=s.sd/g;
	int i;
	printf("The sum of ");
	for(i=0;i<n-1;i++)
		printf("%d/%d + ",f[i].n,f[i].d);
	printf("%d/%d = %d/%d = %d/%d\n",f[i].n,f[i].d,s.sn,s.sd,sofn,sofd);
}
int main()
{
	int n,g;
	n=input();
	Frac f[n];
	Sum s;     //,s_gcd
	frac_input(n,f);
	s=process(n,f);
	g=gcd(s);              //s_gcd=gcd();
	output(n,f,s,g);    //,s_gcd
	return 0;
}