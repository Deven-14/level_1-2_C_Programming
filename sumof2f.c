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
    printf("Enter the numerator and denominator of a number (n/d):\n");
    scanf("%d/%d",&p.n,&p.d);
    return p;
}
Frac process(Frac p1,Frac p2)
{
    Frac p3;
    p3.n=(p1.n*p2.d)+(p2.n*p1.d);
    p3.d=p1.d*p2.d;
    return p3;
}
Frac gcd(Frac f)
{
    int t;
    Frac p;
    p.n=f.n;
    p.d=f.d;
    while(p.d>0)
    {
        t=p.d;
        p.d=p.n%p.d;
        p.n=t;
    }
    return p;
}
void output(Frac p1,Frac p2,Frac p3,Frac g)
{   
    int n=p3.n/g.n;
    int d=p3.d/g.n;  // can be g.n or g.d 
    printf("The sum of %d/%d + %d/%d = %d/%d = %d/%d\n",p1.n,p1.d,p2.n,p2.d,p3.n,p3.d,g.n,g.d);
}
int main()
{
    Frac p1,p2,p3,g;
    p1=input();
    p2=input();
    p3=process(p1,p2);
    output(p1,p2,p3);
    g=gcd(p3);
    return 0;
}
