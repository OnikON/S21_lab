#include <stdio.h>
#include <stdlib.h>

#include "data_io.h"

void input(double **data, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        printf("n/a");
        exit(1);
    }
    *data = malloc(*n * sizeof(double));
    for (int i = 0; i < *n; i++) {
        if (scanf("%lf", &(*data)[i]) != 1) {
            free(data);
            printf("n/a");
            exit(1);
        }
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%.2lf ", data[i]);
    }
    printf("%.2lf", data[n - 1]);
}