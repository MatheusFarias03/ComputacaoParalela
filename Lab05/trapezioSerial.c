#include <stdio.h>
#include <math.h>

double f(double x){
	return exp(x);
}

int main() {
	double a, b;
	int n;

	printf("Enter a, b and n\n");
	scanf("%lf %lf %d", &a, &b, &n);

	double h, approx, x;
        h = (b - a) / n;
	approx = (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++) {
		x = a + i * h;
		approx += f(x);
	}
	approx = h * approx;
	printf("With n = %d trapezoids, our estimate\n", n);
        printf("of the integral from %f to %f = %.14e\n", a, b, approx);

	return 0;
}


