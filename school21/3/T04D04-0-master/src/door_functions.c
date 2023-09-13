#include <stdio.h>
#include <math.h>

long double Verz(long double x);
long double Bern(long double x);
long double Par(long double x);

void print_graph(long double (*f)(long double));

int main() {
    long double step = 2*M_PI/41;
    for (long double i = -M_PI; i <= M_PI + 0.001; i+=step) {
        printf("%.7Lf |", i);
        printf(" %.7Lf |", Verz(i));
        if ( (pow(1 + 4 * pow(i, 2), 0.5) - pow(i, 2) - 1) > 0 ) {
            printf(" %.7Lf |", Bern(i));
        } else {
            printf(" - |");
        }
        if (i != 0) {
            printf(" %.7Lf", Par(i));
        } else {
            printf(" -");
        }
        printf("\n");
    }
    print_graph(Verz);
    print_graph(Bern);
    print_graph(Par);
    return 0;
}

long double Verz(long double x) {
    return 1/(1 + pow(x, 2));
}

long double Bern(long double x) {
    return pow(pow(1 + 4 * pow(x, 2), 0.5) - pow(x, 2) - 1, 0.5);
}

long double Par(long double x) {
    return 1/pow(x, 2);
}

void print_graph(long double (*f)(long double)) {
    printf("\n-------------------------------\n");
    long double step = 2 * M_PI/41;
    long double max = -INFINITY;
    long double min = INFINITY;
    for (long double i = -M_PI; i <= M_PI + 0.001; i += step) {
        long double y = f(i);
        max = y > max ? y : max;
        min = y < min ? y : min;
    }
    long double norma = (min + max)/21;
    for (int i = 0; i < 21; i++) {
        for (long double x = -M_PI; x <= M_PI + 0.001; x += step) {
            long double y = f(x);
            if (y > (max - (i + 1) * norma) && y <= (max - i * norma))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n-------------------------------");
}