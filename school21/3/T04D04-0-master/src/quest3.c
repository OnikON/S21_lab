#include <stdio.h>

#define TRUE 1
#define FALSE 0

void error() {
    printf("n/a");
}
short check_on_int(float value) {
    return (int) value == value ? TRUE : FALSE;
}

long long int fib_f(int count) {
    if (count == 1 || count == 2) { return 1; }
    return (fib_f(count - 2) + fib_f(count - 1));
}

int main(void) {
    double f_value; 
    if (scanf("%lf", &f_value) != 1 || !check_on_int(f_value) || f_value <= 0) {
        error();
        return 1;
    }
    int value = (float)f_value;

    printf("%lld", fib_f(value));
}