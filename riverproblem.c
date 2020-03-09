#include<stdio.h>
struct hobbits
{
	int hob1;
	int hob2;
	int hob3;
	int hob4;
};
typedef struct hobbits Hobbits;
struct hobbit_pairs
{
	int a;
	int b;
};
typedef struct hobbit_pairs Pairs;
struct bridge_crossing
{
	int time1;
	int time2;
	int time3;
	int time4;
	int time5;
};
typedef struct bridge_crossing Bridge;
void firstpairs(int n,Hobbits h[n],int i,Pairs p1[6])
{
	p1[0].a=h[i].hob1;
	p1[0].b=h[i].hob2;
	p1[1].a=h[i].hob1;
	p1[1].b=h[i].hob3;
	p1[2].a=h[i].hob1;
	p1[2].b=h[i].hob4;
	p1[3].a=h[i].hob2;
	p1[3].b=h[i].hob3;
	p1[4].a=h[i].hob2;
	p1[4].b=h[i].hob4;
	p1[5].a=h[i].hob3;
	p1[5].b=h[i].hob4;
}
void thirdpairs(int n,Hobbits h[n],int i,int j,Pairs p3[3])
{
	if(j==0)
	{
		p3[0].a=h[i].hob1;
		p3[0].b=h[i].hob3;
		p3[1].a=h[i].hob1;
		p3[1].b=h[i].hob4;
		p3[2].a=h[i].hob3;
		p3[2].b=h[i].hob4;
	}
	else if(j==1||j==3)
	{
		p3[0].a=h[i].hob1;
		p3[0].b=h[i].hob2;
		p3[1].a=h[i].hob1;
		p3[1].b=h[i].hob4;
		p3[2].a=h[i].hob2;
		p3[2].b=h[i].hob4;
	}
	else
	{
		p3[0].a=h[i].hob1;
		p3[0].b=h[i].hob2;
		p3[1].a=h[i].hob1;
		p3[1].b=h[i].hob3;
		p3[2].a=h[i].hob2;
		p3[2].b=h[i].hob3;
	}
}
int input_numofloops()
{
	int n;
	scanf("%d",&n);
	return n;
}
Hobbits input_values()
{
	Hobbits h;
	scanf("%d%d%d%d",&h.hob1,&h.hob2,&h.hob3,&h.hob4);
	return h;
}
int time_5thcrossing(int n, int i,int j,int k, Bridge b, Hobbits h[n],Pairs p5)
{
	p5.b=b.time4;
	if(j==0)
	{
		if(k==0)
			p5.a=h[i].hob4;
		else if(k==1)
			p5.a=h[i].hob3;
		else
			p5.a=h[i].hob1;
	}
	else if(j==1 || j==3)
	{
		if(k==0)
			p5.a=h[i].hob4;
		else if(k==1)
			p5.a=h[i].hob2;
		else
			p5.a=h[i].hob1;
	}
	else
	{
		if(k==0)
			p5.a=h[i].hob3;
		else if(k==1)
			p5.a=h[i].hob2;
		else
			p5.a=h[i].hob1;
	}
	if(p5.a>p5.b)
		b.time5=p5.a;
	else
		b.time5=p5.b;
	return b.time5;
}
int shortest_time(int i,int l,int n,Hobbits h[n],Pairs p1[6],Pairs p3[3],Pairs p5,Bridge b)
{
	int j,k,sum,smallest_time,timevalues_eachloop[100];
	h[i]=input_values();
	firstpairs(n,h,i,p1);
	for(j=0;j<6;j++)
	{
		b.time1=p1[j].b;
		b.time2=p1[j].a;   // because the shortest time taking one comes back
		thirdpairs(n,h,i,j,p3);
		for(k=0;k<3;k++)
		{
			b.time3=p3[k].b;
			b.time4=(p3[k].b<=p3[k].a)?((p3[k].b<=b.time1)?p3[k].b:b.time1):((p3[k].a<=b.time1)?p3[k].a:b.time1); //because we have to check the smallest one of the 3 who have reached the other side and not b1,b2,b2,coz b2 not necessarily go in the third pair
			b.time5=time_5thcrossing(n,i,j,k,b,h,p5);
			sum=b.time1+b.time2+b.time3+b.time4+b.time5;
			timevalues_eachloop[l]=sum;
			l++;
		}
	}
	smallest_time=timevalues_eachloop[0];          
	for(i=0;i<l;i++)
	{
		if(timevalues_eachloop[i]<smallest_time)
			smallest_time=timevalues_eachloop[i];
	}
	return smallest_time;
}
void shortest_time_eachloop(int n,Hobbits h[n],Pairs p1[6],Pairs p3[3],Pairs p5,Bridge b,int output_eachloop[n])
{
	int i,l=0,smallest_time;
	for(i=0;i<n;i++)
	{
		h[i]=input_values();
		smallest_time=shortest_time(i,l,n,h,p1,p3,p5,b);
		output_eachloop[i]=smallest_time;
		l=0; // it's needed because in the next input the loop should start again
	}	
}
void output(int n,int output_eachloop[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",output_eachloop[i]);
}
int main()
{
	int n;
	n=input_numofloops();
	int output_eachloop[n];
	Hobbits h[n];
	Pairs p1[6],p3[3],p5;
	Bridge b;
	shortest_time_eachloop(n,h,p1,p3,p5,b,output_eachloop);
	output(n,output_eachloop);
	return 0;
}
