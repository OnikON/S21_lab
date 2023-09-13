#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void error() {
    printf("n/a\n");
}
//проверка того что целое
short check_on_int(float value) {
    return (int) value == value ? TRUE : FALSE;
}
//деление, если есть остаток возвращает с отрицанием.
int div_n(int a, int b) {
    int count = 0;
    while (a > 0) {
        a -= b;
        count++;
    }
    return (a==0) ? (count) : (-count); 
}
//проверка того что число простое
short check_on_simple(int x) {
    int value;
    for(int i = 2; i < x; i++) {
        value = div_n(x, i);
        if (value >= 0) { return FALSE; }
    }
    return TRUE;
}

int main(void) {
    double f_value; 
    if (scanf("%lf", &f_value) != 1 || !check_on_int(f_value)) {
        error();
        return 1;
    }
    int value = abs((float)f_value);
    int save_value = value;
    for (int i = 2; i < save_value; i++) {
        value = save_value / i;
        value = div_n(save_value, i);
        if (value > 0 && check_on_simple(value)){
            printf("%d\n", value);
            return 0;
        }
    }
    if (check_on_simple(save_value)){
            printf("%d\n", save_value);
            return 0;
        }
    error();
    return 1;
}
