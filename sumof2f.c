#include<stdio.h>

struct fraction
{
    int n;
    int d;
};
typedef struct fraction Fraction;

Fraction input_ith_fraction(int i)
{
    Fraction f;
    printf("Enter fraction %d (n / d): ", i);
    scanf("%d %d", &f.n, &f.d);
    return f;
}

int gcd(int a, int b)
{
    int temp;
    while(b > 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction reduce(Fraction f)
{
    int g = gcd(f.n, f.d); //because gcd is the greatest common divisor of 2 numbers and so don't pass a structure,instead pass the values of that structure
    f.n = f.n / g;
    f.d = f.d / g;
    return f;
}

Fraction sum_of_2_fractions(Fraction f1, Fraction f2)
{
    Fraction f_sum;
    f_sum.n = f1.n * f2.d + f2.n * f1.d;
    f_sum.d = f1.d * f2.d;
    f_sum = reduce(f_sum);
    return f_sum;
}

void print_sum(Fraction f1, Fraction f2, Fraction f_sum)
{
    printf("%d/%d + %d/%d = %d/%d\n", f1.n, f1.d, f2.n, f2.d, f_sum.n, f_sum.d);
}

int main()
{
    Fraction f1, f2, f_sum;
    f1 = input_ith_fraction(1);
    f2 = input_ith_fraction(2);
    f_sum = sum_of_2_fractions(f1, f2);
    print_sum(f1, f2, f_sum);
    return 0;
}