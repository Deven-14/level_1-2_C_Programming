#include<stdio.h>
#include<math.h>
float input1()
{
    float x;
    printf("Enter the x-coordinates of a point\n");
    scanf("%f",&x);
    return x;
}
float input2()
{
    float y;
    printf("Enter the y-coordinates of a point\n");
    scanf("%f",&y);
    return y;
}
float process(float x1,float y1,float x2,float y2)
{
    float d;
    d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return d;
}
void output(float x1,float y1,float x2,float y2,float d)
{
    printf("The distance between the 2 points (%f,%f) and (%f,%f) is %f\n",x1,y1,x2,y2,d);
}
int main()
{
    float d,x1,y1,x2,y2;
    x1=input1();
    y1=input2();
    x2=input1();
    y2=input2();
    d=process(x1,y1,x2,y2);
    output(x1,y1,x2,y2,d);
    return 0;
}    