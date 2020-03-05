#include<stdio.h>
struct frac
{
    int n;
    int d;
};
typedef struct frac Frac;
Frac input()
{
    Frac p;
    printf("Enter a fraction (n/d):\n");
    scanf("%d/%d",&p.n,&p.d);
    return p;
}
int gcd(int a,int b)
{
    int t;
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
    Frac f;
    g=gcd(s.n,s.d); //because gcd is the greatest common divisor of 2 numbers and so don't pass a structure,instead pass the values of that structure
    f.n=s.n/g;
    f.d=s.d/g;
    return f;
}
Frac process(Frac p1,Frac p2)
{
    Frac p3,f;
    p3.n=(p1.n*p2.d)+(p2.n*p1.d);
    p3.d=p1.d*p2.d;
    f=reduce(p3);
    return f;
}
void output(Frac p1,Frac p2,Frac f)
{
    printf("The sum of %d/%d + %d/%d = %d/%d\n",p1.n,p1.d,p2.n,p2.d,f.n,f.d);
}
int main()
{
    Frac p1,p2,f;
    p1=input();
    p2=input();
    f=process(p1,p2);
    output(p1,p2,f);
    return 0;
}