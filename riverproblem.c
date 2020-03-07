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
int add(int a,int b,int c,int d,int e)
{
	int sum=a+b+c+d+e;
	return sum;
}
void store(int a[100],int sum,int m)    // didn't understand y int n has to be put
{
	a[m]=sum;
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
int find_t5(int n, int i, Bridge b, Ivalues a[n])
{
  if(a[i].a!=b.b1 && a[i].a!=b.b2 && a[i].a!=b.b3 && a[i].a!=b.b4)
  b.b5=a[i].a;
  else if(a[i].b!=b.b1 && a[i].b!=b.b2 && a[i].b!=b.b3 && a[i].b!=b.b4)
  b.b5=a[i].b;
  else if(a[i].c!=b.b1 && a[i].c!=b.b2 && a[i].c!=b.b3 && a[i].c!=b.b4)
  b.b5=a[i].c;
  else
  b.b5=a[i].d;
  return b.b5;
}
int process(int n,Ivalues a[n],Pairs p1[6],Pairs p3[3],Bridge b)
{
    int i,j,l,e,m=0,sum,shortest,d[100];
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
                b.b4=p3[l].a;
                b.b5=find_t5(n,i,b,a);
                sum=add(b.b1,b.b2,b.b3,b.b4,b.b5);
                store(d,sum,m);
                m++;
            }
        }
   	}
	shortest=check_shortest(m,d);
	return shortest;
}
void output(int s)
{
	printf("%d",s);
}
int main()
{
    int n,s;
    n=input();
    Ivalues i[n];
    Pairs p1[6],p3[3];
    Bridge b;
    s=process(n,i,p1,p3,b);
    output(s);
    return 0;
}
