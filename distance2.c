#include<stdio.h>
#include<math.h>

float input_x_coordinate_of_ith_point(int i)
{
    float x;
    printf("Enter the x-coordinates of a point %d: ", i);
    scanf("%f", &x);
    return x;
}

float input_y_coordinate_of_ith_point(int i)
{
    float y;
    printf("Enter the y-coordinates of a point %d: ", i);
    scanf("%f", &y);
    return y;
}

float calculate_distance(float x1, float y1, float x2, float y2)
{
    float distance;
    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

void print_distance(float x1, float y1, float x2, float y2, float distance)
{
    printf("The distance between the 2 points (%f, %f) and (%f, %f) is %f\n", x1, y1, x2, y2, distance);
}

int main()
{
    float x1, x2, y1, y2, distance;
    x1 = input_x_coordinate_of_ith_point(1);
    y1 = input_y_coordinate_of_ith_point(1);
    x2 = input_x_coordinate_of_ith_point(2);
    y2 = input_y_coordinate_of_ith_point(2);

    distance = calculate_distance(x1, y1, x2, y2);

    print_distance(x1, y1, x2, y2, distance);
    return 0;
}    