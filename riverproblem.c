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
void firstpairs(Ivalues a[4],int j,Pairs p1[6])
{
	p1[0].a=a[j].a;
	p1[0].b=a[j].b;
	p1[1].a=a[j].a;
	p1[1].b=a[j].c;
	p1[2].a=a[j].a;
	p1[2].b=a[j].d;
	p1[3].a=a[j].b;
	p1[3].b=a[j].c;
	p1[4].a=a[j].b;
	p1[4].b=a[j].d;
	p1[5].a=a[j].c;
	p1[5].b=a[j].d;
}
void thirdpairs(Ivalues a[4],int l,Pairs p3[3])
{
	p3[0].a=a[l].a;
	p3[0].b=a[l].c;
	p3[1].a=a[l].a;
	p3[1].b=a[l].d;
	p3[2].a=a[l].c;
	p3[2].b=a[l].d;
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
int add(Bridge b)
{
	int sum=b.b1+b.b2+b.b3+b.b4+b.b4+b.b5;
	return sum;
}
void store(int a[100],int sum,int m)    // didn't understand y int n has to be put
{
	a[m]=sum;
}
int check_smallest(int m,int a[100])  //y is it necessary to put int n before int a[n]
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
int process(int n,Ivalues a[n],Pairs p1[6],Pairs p3[3],Bridge b)
{
    int i,j,k,l,m=0,sum,shortest,d[100];
    for(i=0;i<n;i++)
    {
        a[i]=input_values();
        for(j=0;j<6;j++)
        {
            firstpairs(a,j,p1);
			b.b1=p1[j].b;
			b.b2=p1[j].a;    // because the larger time taking
            for(l=0;l<3;l++)
            {
                thirdpairs(a,k,p3);
                b.b3=p3[l].b;
                b.b4=p3[l].a;
                b.b5=a[i].d;
                sum=add(b);
                store(d,sum,m);
                m++;
            }
		}
	}
	shortest=check_smallest(m,d);
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