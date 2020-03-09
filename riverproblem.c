#include<stdio.h>
struct hobbits
{
    int h1;
    int h2;
    int h3;
    int h4;
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
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;
};
typedef struct bridge_crossing Bridge;
void firstpairs(int n,Hobbits h[n],int i,Pairs p1[6])
{
    p1[0].a=h[i].h1;
    p1[0].b=h[i].h2;
    p1[1].a=h[i].h1;
    p1[1].b=h[i].h3;
    p1[2].a=h[i].h1;
    p1[2].b=h[i].h4;
    p1[3].a=h[i].h2;
    p1[3].b=h[i].h3;
    p1[4].a=h[i].h2;
    p1[4].b=h[i].h4;
    p1[5].a=h[i].h3;
    p1[5].b=h[i].h4;
}
void thirdpairs(int n,Hobbits h[n],int i,int j,Pairs p3[3])
{
    if(j==0)
    {
        p3[0].a=h[i].h1;
        p3[0].b=h[i].h3;
        p3[1].a=h[i].h1;
        p3[1].b=h[i].h4;
        p3[2].a=h[i].h3;
        p3[2].b=h[i].h4;
    }
    else if(j==1||j==3)
    {
        p3[0].a=h[i].h1;
        p3[0].b=h[i].h2;
        p3[1].a=h[i].h1;
        p3[1].b=h[i].h4;
        p3[2].a=h[i].h2;
        p3[2].b=h[i].h4;
    }
    else
    {
        p3[0].a=h[i].h1;
        p3[0].b=h[i].h2;
        p3[1].a=h[i].h1;
        p3[1].b=h[i].h3;
        p3[2].a=h[i].h2;
        p3[2].b=h[i].h3;
    }
}
int input_loops()
{
    int n;
    scanf("%d",&n);
    return n;
}
Hobbits input_values()
{
    Hobbits h;
    scanf("%d%d%d%d",&h.h1,&h.h2,&h.h3,&h.h4);
    return h;
}
int time_5thcrossing(int n, int i,int j,int k, Bridge b, Hobbits h[n],Pairs p5)
{
	p5.b=b.t4;
    if(j==0)
    {
        if(k==0)
            p5.a=h[i].h4;
        else if(k==1)
            p5.a=h[i].h3;
        else
            p5.a=h[i].h1;
    }
    else if(j==1 || j==3)
    {
        if(k==0)
            p5.a=h[i].h4;
        else if(k==1)
            p5.a=h[i].h2;
        else
            p5.a=h[i].h1;
    }
    else
    {
        if(k==0)
            p5.a=h[i].h3;
        else if(k==1)
            p5.a=h[i].h2;
        else
            p5.a=h[i].h1;
    }
    if(p5.a>p5.b)
        b.t5=p5.a;
    else
        b.t5=p5.b;
    return b.t5;
}
int check_shortest_time(int m,int timevalues_eachloop[100])  //y is it necessary to put int n before int a[n]
{
    int i,shortest_time;
    shortest_time=timevalues_eachloop[0];          
    for(i=0;i<m;i++)
    {
        if(timevalues_eachloop[i]<shortest_time)
        shortest_time=timevalues_eachloop[i];
    }
    return shortest_time;
}
void process(int n,Hobbits h[n],Pairs p1[6],Pairs p3[3],Pairs p5,Bridge b,int output_eachloop[n])
{
    int i,j,k,l=0,sum,shortest_time,timevalues_eachloop[100];
    for(i=0;i<n;i++)
    {
        h[i]=input_values();
        firstpairs(n,h,i,p1);
        for(j=0;j<6;j++)
        {
            b.t1=p1[j].b;
            b.t2=p1[j].a;   // because the larger time taking
            thirdpairs(n,h,i,j,p3);
            for(k=0;k<3;k++)
            {
                b.t3=p3[k].b;
                b.t4=(p3[k].b<=p3[k].a)?((p3[k].b<=b.t1)?p3[k].b:b.t1):((p3[k].a<=b.t1)?p3[k].a:b.t1); //because we have to check the smallest one of the 3 who have reached the other side and not b1,b2,b2,coz b2 not necessarily go in the third pair
                b.t5=time_5thcrossing(n,i,j,k,b,h,p5);
                sum=b.t1+b.t2+b.t3+b.t4+b.t5;
                timevalues_eachloop[l]=sum;
                l++;
            }
        }
        shortest_time=check_shortest_time(l,timevalues_eachloop);
        output_eachloop[i]=shortest_time;
        l=0; // it's needed because in the next input the loop should start again
    }
}
void output(int n,int all_outputs[n])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",all_outputs[i]);
}
int main()
{
    int n;
    n=input_loops();
    int output_eachloop[n];
    Hobbits h[n];
    Pairs p1[6],p3[3],p5;
    Bridge b;
    process(n,h,p1,p3,p5,b,output_eachloop);
    output(n,output_eachloop);
    return 0;
}
