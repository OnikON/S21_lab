#include <stdio.h>
void plus(int* a, int b) {
    *a += *a;
    b += b;
}
int main(void) {
    int a = 2;
    int b = 4;

    plus(&a, b);

    printf("%d,%d\n", a, b);
}