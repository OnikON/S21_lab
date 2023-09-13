#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


short Input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main()
{
    int **matrix, **result;
    int n,m;
    
    Input(matrix, &n, &m);
    
    sort_vertical(matrix, n, m, result);
    output(result);
    
    sort_horizontal(matrix, n, m, result);
    output(result);
}

short Input(int ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || n <= 0) {
        return 0;
    }

    (*matrix) = mallock((*n) * sizeof(int*));
    for (int i = 0; i < *n; i++) {
        matrix[i] = mallock((*m) * sizeof(int));
    }

    char buf;
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (scanf("%d%c", matrix[i][j], &buf) != 1 || (buf != '\n' && buf != ' ' && buf != EOF)) {
                return 0;
            }
        }
    }

    return 1;
}