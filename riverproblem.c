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
struct Store
{
	int a;
};
typedef struct Store STORE;
void firstpairs(Ivalues a[4],int i,Pairs a1[6])
{
	a1[0].a=a[i].a;
	a1[0].a=a[i].b;
	a1[1].a=a[i].a;
	a1[1].a=a[i].c;
	a1[2].a=a[i].a;
	a1[2].a=a[i].d;
	a1[3].a=a[i].b;
	a1[3].a=a[i].c;
	a1[4].a=a[i].b;
	a1[4].a=a[i].d;
	a1[5].a=a[i].a;
	a1[5].a=a[i].b;
}
void thirdpairs(Ivalues a[4],int l,Pairs a3[3])
{
	a3[0].a=a[l].a;
	a3[0].b=a[l].c;
	a3[1].a=a[l].a;
	a3[1].b=a[l].d;
	a3[2].a=a[l].c;
	a3[2].b=a[l].d;
}
int input1()
{
    int n;
    scanf("%d",&n);
    return n;
}
Ivalues input2()
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
STORE store(int sum,int i,int n)
{
	STORE a[n];
	a[i]=sum;
	return a;
}
int check_smallest(STORE a[n],int n)
{
	int i,s,t;
	for(i=0;i<n;i++)
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
int process(int n,Ivalues a[n],Pairs a1[6],Pairs a3[3],Bridge b,STORE a[n])
{
    int i,j,k,l,sum,s;
    for(i=0;i<n;i++)
    {
        a[i]=input2();
        firstpairs(a,i);
        for(j=0;j<6;j++)
        {
			b.b1=a1[j].b;
			b.b2=a1[j].a;    // because the larger time taking 
			for(k=0;k<6;k++)
			{
				thirdpairs(a,k);
				for(l=0;l<3;l++)
				{
					b.b3=a3[l].b;
					b.b4=a3[l].a;
					b.b5=a[i].d;
					sum=add(b);
					store(sum,i,n);
				}
			}
		}
	}
	s=check_smallest(a,n);	
	return s;	
}
void output(int s)
{
	printf("%d",s);
}
int main()
{
    int n;
    n=input1();
    Ivalues i[n];
    Pairs a1[6],a3[3];
    Bridge b;
    STORE a[n];
    process(n,i,a1,a3,b,a);
    output(s);
    return 0;
}