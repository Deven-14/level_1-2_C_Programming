#include<stdio.h>

struct fraction
{
    int n;
    int d;
};
typedef struct fraction Fraction;

int input_no_of_fractions()
{
	int n;
	printf("Enter the number of fractions: ");
	scanf("%d", &n);
	return n;
}

Fraction input_ith_fraction(int i)
{
    Fraction f;
    printf("Enter fraction %d (n / d): ", i);
    scanf("%d %d", &f.n, &f.d);
    return f;
}

void input_n_fractions(int n, Fraction f[n])
{
	printf("Enter the fractions:\n\n");
	for(int i = 0; i < n; ++i)
		f[i] = input_ith_fraction(i+1);
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

Fraction sum_of_n_fractions(int n, Fraction f[])
{
	Fraction f_sum = {f[0].n, f[0].d};

	for(int i = 1; i < n; ++i)
	{
		f_sum.n = (f_sum.n * f[i].d) + (f_sum.d * f[i].n);
		f_sum.d = f_sum.d * f[i].d;
	}

	f_sum = reduce(f_sum);
	return f_sum;
}

void print_sum(int n, Fraction f[], Fraction f_sum)
{
	for(int i = 0; i < n-1; ++i)
		printf("%d/%d + ", f[i].n, f[i].d);
	printf("%d/%d = %d/%d\n", f[n-1].n, f[n-1].d, f_sum.n, f_sum.d);
}

int main()
{
	int n = input_no_of_fractions();
	Fraction f[n], f_sum;
	input_n_fractions(n, f);
	f_sum = sum_of_n_fractions(n, f);
	print_sum(n, f, f_sum);
	return 0;
}