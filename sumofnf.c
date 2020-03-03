#include<stdio.h>
struct frac
{
    int n;
    int d;
};
typedef struct frac Frac;
struct sum
{
    int sn;
    int sd;
};
typedef struct sum Sum;
int input()
{
    int n;
    printf("Enter the number of fractions\n");
    scanf("%d",&n);
    return n;
}
void frac_input(int n,Frac p[n])
{
    int i;
    printf("Enter the fractions (n/d):\n");
    for(i=0;i<n;i++)
        scanf("%d/%d",&p[i].n,&p[i].d);
}
Sum process(int n,Frac f[n])
{
    int i;
    Sum s;
    s.sn=f[0].n;
    s.sd=f[0].d;
    for(i=1;i<n;i++)
    {
        s.sn=(s.sn*f[i].d)+(s.sd*f[i].n);
        s.sd=s.sd*f[i].d;
    }
    return s;
}
void output(int n, Frac f[n],Sum s)
{
    int i;
    printf("The sum of ");
    for(i=0;i<n-1;i++)
        printf("%d/%d + ",f[i].n,f[i].d);
    printf("%d/%d = %d/%d\n",f[i].n,f[i].d,s.sn,s.sd);
}
int main()
{
    int n;
    n=input();
    Frac f[n];
    Sum s;
    frac_input(n,f);
    s=process(n,f);
    output(n,f,s);
    return 0;
}