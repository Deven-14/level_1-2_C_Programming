#include<stdio.h>
#include<math.h>
struct store
{
 float x;
 float y;
};
typedef struct store Store;
Store input()
{
 Store p;
 printf("Enter the coordinates of a point (x,y)\n");
 scanf("%f%f",&p.x,&p.y);
 return p;
}
float process(Store p1,Store p2)
{
 float d;
 d=sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
 return d;
}
void output(Store p1,Store p2,float d)
{
 printf("The distance between the 2 points (%f,%f) and (%f,%f) is %f\n",p1.x,p1.y,p2.x,p2.y,d);
}
int main()
{    
    Store s1,s2;
    float d;
    s1=input();
    s2=input();
    d=process(s1,s2);
    output(s1,s2,d);
    return 0;
}