#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);
void error(void);

int main()
{
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    }
    else {
        return 1;
    }

    return 0;
}

void error(void) {
    printf("n/a");
}

int input(int *a, int *n)
{
    char new_len;
    if (scanf("%d%c", n, &new_len) != 2 || new_len != '\n' || *n < 0 || *n > NMAX) {
        error();
        return 0; 
    }
    for(int *p = a; p - a < *n; p++)
    {
        if (scanf("%d%c", p, &new_len) != 2 || (new_len != ' ' && new_len != '\n')) {
            error();
            return 0;
        } 
    }
    return 1;
}

void output(int *a, int n)
{
    for(int *p = a; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", *(a + (n - 1)));
}

void squaring(int *a, int n)
{
    for(int *p = a; p - a < n; p++) { (*p) = (*p) * (*p); }
}
