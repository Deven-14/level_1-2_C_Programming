#include<stdio.h>
#include<math.h>

struct point
{
    float x;
    float y;
};
typedef struct point Point;

Point input_point(char* ordinal_num)
{
    Point p;
    printf("Enter the coordinates of %s point (x, y): ", ordinal_num);
    scanf("%f %f", &p.x, &p.y);
    return p;
}

float calculate_distance(Point p1, Point p2)
{
    float distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

void print_distance(Point p1, Point p2, float distance)
{
    printf("The distance between the 2 points (%f, %f) and (%f, %f) is %f\n", p1.x, p1.y, p2.x, p2.y, distance);
}

int main()
{    
    Point p1, p2;
    float distance;
    p1 = input_point("1st");
    p2 = input_point("2nd");
    distance = calculate_distance(p1, p2);
    print_distance(p1, p2, distance);
    return 0;
}