#include<stdio.h>
struct input_values
{
    int a;
    int b;
    int c;
    int d;
};
typedef struct input_values Ivalues;
struct pairs
{
    int a;
    int b;
};
typedef struct pairs Pairs;
struct bridge_crossing
{
    int b1;
    int b2;
    int b3;
    int b4;
    int b5;
};
typedef struct bridge_crossing Bridge;
void firstpairs(int n,Ivalues a[n],int i,Pairs p1[6])
{
	p1[0].a=a[i].a;
	p1[0].b=a[i].b;
	p1[1].a=a[i].a;
	p1[1].b=a[i].c;
	p1[2].a=a[i].a;
	p1[2].b=a[i].d;
	p1[3].a=a[i].b;
	p1[3].b=a[i].c;
	p1[4].a=a[i].b;
	p1[4].b=a[i].d;
	p1[5].a=a[i].c;
	p1[5].b=a[i].d;
}
void thirdpairs(int n,Ivalues a[n],int i,int j,Pairs p3[3])
{
    if(j==0)
    {
	p3[0].a=a[i].a;
	p3[0].b=a[i].c;
	p3[1].a=a[i].a;
	p3[1].b=a[i].d;
	p3[2].a=a[i].c;
	p3[2].b=a[i].d;
    }
    else if(j==1||j==3)
    {
	p3[0].a=a[i].a;
	p3[0].b=a[i].b;
	p3[1].a=a[i].a;
	p3[1].b=a[i].d;
	p3[2].a=a[i].b;
	p3[2].b=a[i].d;
    }
    else
    {
	p3[0].a=a[i].a;
	p3[0].b=a[i].b;
	p3[1].a=a[i].a;
	p3[1].b=a[i].c;
	p3[2].a=a[i].b;
	p3[2].b=a[i].c;
    }
}
int input()
{
    int n;
    scanf("%d",&n);
    return n;
}
Ivalues input_values()
{
    Ivalues i;
    scanf("%d%d%d%d",&i.a,&i.b,&i.c,&i.d);
    return i;
}
int check_shortest(int m,int a[100])  //y is it necessary to put int n before int a[n]
{
	int i,s,t;
	for(i=0;i<m;i++)
	{
		if(a[i]<a[i+1])
		{
			s=a[i];
			t=a[i+1];
			a[i+1]=a[i];
			a[i]=t;
		}
		else
		s=a[i+1];
	}
	return s;
}
int find_t5(int n, int i,int l,int j, Bridge b, Ivalues a[n])
{
    int rem;
    if(j==0)
    {
        if(l==0)
            rem=a[i].d;
        else if(l==1)
            rem=a[i].c;
        else
            rem=a[i].a;
    }
    else if(j==1 || j==3)
    {
        if(l==0)
            rem=a[i].d;
        else if(l==1)
            rem=a[i].b;
        else
            rem=a[i].a;
    }
    else
    {
        if(l==0)
            rem=a[i].c;
        else if(l==1)
            rem=a[i].b;
        else
            rem=a[i].a;
    }
    if(rem>b.b4)
        b.b5=rem;
    else
        b.b5=b.b4;
    return b.b5;
  /*  int c;
  if(a[i].a!=b.b1 && a[i].a!=p3[l].a && a[i].a!=p3[l].b )
  c=a[i].a;
  else if(a[i].b!=b.b1 && a[i].b!=p3[l].a && a[i].b!=p3[l].b )
  c=a[i].b;
  else if(a[i].c!=b.b1 && a[i].c!=p3[l].a && a[i].c!=p3[l].b )
  c=a[i].c;
  else
  c=a[i].d;
  if(c>b.b4)
    b.b5=c;
  else
    b.b5=b.b4;
  return b.b5;*/
}
void process(int n,Ivalues a[n],Pairs p1[6],Pairs p3[3],Bridge b,int e[n])
{
    int i,j,l,m=0,sum,shortest,d[100];
    for(i=0;i<n;i++)
    {
        a[i]=input_values();
        for(j=0;j<6;j++)
        {
            firstpairs(n,a,i,p1);
            b.b1=p1[j].b;
            b.b2=p1[j].a;    // because the larger time taking
            for(l=0;l<3;l++)
            {
                thirdpairs(n,a,i,j,p3);
                b.b3=p3[l].b;
                b.b4=(p3[l].b<=p3[l].a)?((p3[l].b<=b.b1)?p3[l].b:b.b1):((p3[l].a<=b.b1)?p3[l].a:b.b1); //because we have to check the smallest one of the 3 who have reached the other side and not b1,b2,b2,coz b2 not necessarily go in the third pair
                b.b5=find_t5(n,i,l,j,b,a);
                sum=b.b1+b.b2+b.b3+b.b4+b.b5;
                a[m]=sum;
                m++;
            }
        }
        shortest=check_shortest(m,d);
        e[i]=shortest;
        m=0; // it's needed because in the next input the loop should start again
        printf("%d\n",e[i]);
   	}
}
void output(int n,int e[n])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d,",e[i]);
}
int main()
{
    int n;
    n=input();
    int e[n];
    Ivalues i[n];
    Pairs p1[6],p3[3];
    Bridge b;
    process(n,i,p1,p3,b,e);
    output(n,e);
    return 0;
}
