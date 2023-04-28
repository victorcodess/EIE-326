#include <stdio.h>
#include <math.h>

double taylor_series(double x, double a, int N) {
    double sum = 0.0, term = 1.0;
    double c[N+1];
    int i, j;
    
    // calculate derivatives of f(x) up to order N at the point a
    c[0] = f(a);
    for (i = 1; i <= N; i++) {
        double h = pow(2.0, -i) * a; // h = a/(2^i)
        double df = (f(a+h) - f(a-h))/(2.0*h); // derivative using central difference formula
        c[i] = df;
    }
    
    // calculate each term of the Taylor series and add it to the sum
    for (i = 0; i <= N; i++) {
        sum += term;
        term *= (x-a)/(i+1);
        for (j = i; j >= 1; j--) {
            term *= (x-a)/j;
            term *= c[j-1];
        }
    }
    
    return sum;
}

double f(double x) {
    // define the function f(x) that you want to expand as a Taylor series
    return sin(x);
}

int main() {
    double x = 1.0, a = 0.0;
    int N = 5;
    double result = taylor_series(x, a, N);
    
    printf("The value of sin(%lf) using a Taylor series of order %d centered at %lf is: %lf\n", x, N, a, result);
    
    return 0;
}
