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
void output(Frac p1,Frac p2,Frac p3)
{
    printf("The sum of %d/%d + %d/%d = %d/%d\n",p1.n,p1.d,p2.n,p2.d,p3.n,p3.d);
}
int main()
{
    Frac p1,p2,p3;
    p1=input();
    p2=input();
    p3=process(p1,p2);
    output(p1,p2,p3);
    return 0;
}
