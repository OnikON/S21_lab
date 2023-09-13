#include <stdio.h>
#include <math.h>

#define NMAX 30

short Input (int *n, int *mas);
short MetodNikiti (void);
short SerchNum(int n, int *mas);
double Mean(int n, int *mas);
double Variance(int n, int *mas);
short ChekEven(int value);
short ChekMorMean(int value, double M);
short Check3Sigm(int value, double Sigm3, double M);

int main(void) {
    int n, data[NMAX];

    if (Input(&n, data)){
        SerchNum(n, data);
        return 0;
    }
    printf("n/a");
    return 1;
}

short MetodNikiti (void) {
    return getc(stdin) == '\n' ? 1 : 0;
}

short Input (int *n, int *mas) {
    char buf;
    if (scanf("%d%c", n, &buf) !=2 || buf != '\n' || (*n < 0) || (*n > NMAX)) {
        return 0;
    }

    for (int *p = mas; p - mas < *n; p++) {
        if (scanf("%d%c", p, &buf) !=2 || (buf != '\n' && buf != ' ' && buf != EOF)) {
        return 0;
        }
    }
    return 1;
}

double Mean(int n, int *mas) {
    double M = 0;
    for (int i = 0; i < n; i++) {
        M += mas[i];
    }
    return M / (double)n;
}

double Variance(int n, int *mas) {
    double M = Mean(n, mas);
    double M2 = 0;
    for (int i = 0; i < n; i++) {
        M2 += pow(mas[i], 2);
    }
    M2 = M2 / (double)n;
    return (M2 - (double)M);
}

short ChekEven(int value) {
    return (value % 2 == 0) ? 1 : 0;
}

short ChekMorMean(int value, double M) {
    return (value >= M) ? 1 : 0;
}

short Check3Sigm(int value, double Sigm3, double M) {
    return (value < M+  Sigm3 && value >= M - Sigm3) ? 1 : 0;
}

short SerchNum(int n, int *mas) {
    double M,D;
    M = Mean(n, mas);
    D = Variance(n, mas);
    for (int *p = mas; p - mas < n; p++) {
        if (ChekEven(*p) && ChekMorMean(*p, M) && Check3Sigm(*p, 3*sqrt(D), M) && *p != 0) {
            printf("%d", *p);
            return 1;
        }
    }
    printf("0");
    return 0;
}
