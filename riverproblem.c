#include<stdio.h>
struct hobbit_pairs
{
	int a;
	int b;
};
typedef struct hobbit_pairs Pairs;
void firstpairs(int n,int hobbit[4],int i,Pairs p1[6])
{
	p1[0].a=hobbit[1];
	p1[0].b=hobbit[2];
	p1[1].a=hobbit[1];
	p1[1].b=hobbit[3];
	p1[2].a=hobbit[1];
	p1[2].b=hobbit[4];
	p1[3].a=hobbit[2];
	p1[3].b=hobbit[3];
	p1[4].a=hobbit[2];
	p1[4].b=hobbit[4];
	p1[5].a=hobbit[3];
	p1[5].b=hobbit[4];
}
void thirdpairs(int n,int hobbit[4],int i,int j,Pairs p3[3])
{
	if(j==0)
	{
		p3[0].a=hobbit[1];
		p3[0].b=hobbit[3];
		p3[1].a=hobbit[1];
		p3[1].b=hobbit[4];
		p3[2].a=hobbit[3];
		p3[2].b=hobbit[4];
	}
	else if(j==1||j==3)
	{
		p3[0].a=hobbit[1];
		p3[0].b=hobbit[2];
		p3[1].a=hobbit[1];
		p3[1].b=hobbit[4];
		p3[2].a=hobbit[2];
		p3[2].b=hobbit[4];
	}
	else
	{
		p3[0].a=hobbit[1];
		p3[0].b=hobbit[2];
		p3[1].a=hobbit[1];
		p3[1].b=hobbit[3];
		p3[2].a=hobbit[2];
		p3[2].b=hobbit[3];
	}
}
int input_numofloops()
{
	int n;
	scanf("%d",&n);
	return n;
}
void input_values(int hobbit[4])
{
	scanf("%d%d%d%d",&hobbit[1],&hobbit[2],&hobbit[3],&hobbit[4]);
}
Pairs fifthpair(int n, int i,int j,int k,int bridge_crossing[5], int hobbit[4],Pairs p5)
{
	p5.b=bridge_crossing[4];
	if(j==0)
	{
		if(k==0)
			p5.a=hobbit[4];
		else if(k==1)
			p5.a=hobbit[3];
		else
			p5.a=hobbit[1];
	}
	else if(j==1 || j==3)
	{
		if(k==0)
			p5.a=hobbit[4];
		else if(k==1)
			p5.a=hobbit[2];
		else
			p5.a=hobbit[1];
	}
	else
	{
		if(k==0)
			p5.a=hobbit[3];
		else if(k==1)
			p5.a=hobbit[2];
		else
			p5.a=hobbit[1];
	}
	return p5;
}
int shortest_time_func(int i,int l,int n,int hobbit[4],Pairs p1[6],Pairs p3[3],Pairs p5,int bridge_crossing[5])
{
	int j,k,sum,shortest_time,timevalues_eachloop[100];
	firstpairs(n,hobbit,i,p1);
	for(j=0;j<6;j++)
	{
		bridge_crossing[1]=p1[j].b;
		bridge_crossing[2]=p1[j].a;   // because the shortest time taking one comes back
		thirdpairs(n,hobbit,i,j,p3);
		for(k=0;k<3;k++)
		{
			bridge_crossing[3]=p3[k].b;
			bridge_crossing[4]=(p3[k].b<=p3[k].a)?((p3[k].b<=bridge_crossing[1])?p3[k].b:bridge_crossing[1]):((p3[k].a<=bridge_crossing[1])?p3[k].a:bridge_crossing[1]); //because we have to check the smallest one of the 3 who have reached the other side and not b1,b2,b2,coz b2 not necessarily go in the third pair
			p5=fifthpair(n,i,j,k,bridge_crossing,hobbit,p5);
			if(p5.a>p5.b)
				bridge_crossing[5]=p5.a;
			else
				bridge_crossing[5]=p5.b;
			sum=bridge_crossing[1]+bridge_crossing[2]+bridge_crossing[3]+bridge_crossing[4]+bridge_crossing[5];
			timevalues_eachloop[l]=sum;
			l++;
		}
	}
	shortest_time=timevalues_eachloop[0];
	for(i=0;i<l;i++)
	{
		if(timevalues_eachloop[i]<shortest_time)
			shortest_time=timevalues_eachloop[i];
	}
	return shortest_time;
}
void shortest_time_eachloop_func(int n,int hobbit[4],Pairs p1[6],Pairs p3[3],Pairs p5,int bridge_crossing[5],int shortesttime_eachloop[n])
{
	int i,l=0,shortest_time;
	for(i=0;i<n;i++)
	{
		input_values(hobbit); //" wrong because input function should not be called by processing functions"
		shortest_time=shortest_time_func(i,l,n,hobbit,p1,p3,p5,bridge_crossing);
		shortesttime_eachloop[i]=shortest_time;
		l=0; // it's needed because in the next input the loop should start again
	}
}
void output(int n,int shortesttime_eachloop[n])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",shortesttime_eachloop[i]);
}
int main()
{
	int n;
	n=input_numofloops();
	int shortest_time_eachloop[n];
	int hobbit[6];
	int bridge_crossing[5];
	Pairs p1[6],p3[3],p5;
	shortest_time_eachloop_func(n,hobbit,p1,p3,p5,bridge_crossing,shortest_time_eachloop);
	output(n,shortest_time_eachloop);
	return 0;
}
