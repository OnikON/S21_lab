#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
    }
    return 0;
}

int input(int *a, int *n) {
    char cheker;
    if (scanf("%d%c", n, &cheker) != 2 || cheker != '\n' || *n > NMAX) {
        printf("n/a");
        return 1;
    }
    for(int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &cheker) != 2 || (cheker != ' ' && cheker != '\n' && cheker != EOF)) {
            printf("n/a");
            return 0;
        }
    }
    return 1;
    
}

void output(int *a, int n) {
    for (int *p = a; p - a < n-1; p++) {
        printf("%d ", *p);
    }
    printf("%d\n", *(a+n-1));
}

int max(int *a, int n) {
    int max_v = *a;
    for(int *p = a; p - a < n; p++) {
        if (*p > max_v) {
            max_v = *p;
        }
    }
    return (max_v);
}
int min(int *a, int n) {
    int min_v = *a;
    for(int *p = a; p - a < n; p++) {
        if (*p < min_v) {
            min_v = *p;
        }
    }
    return (min_v);
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.7lf %.7lf\n", max_v, min_v, mean_v, variance_v);
}

double mean(int *a, int n) {
    double M = 0;
    for (int i = 0; i < n; i++) {
        M += a[i];
    }
    return M / (double)n;
}
double variance(int *a, int n) {
    double M = mean(a, n);
    double M2 = 0;
    for (int i = 0; i < n; i++) {
        M2 += pow(a[i], 2);
    }
    M2 = M2 / (double)n;
    return (M2 - M);
}
