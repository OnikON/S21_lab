#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

//проверяет является ли введённое число целым
short check_on_int(double value) {
    return (int) value == value ? TRUE : FALSE;
}

void error(){
    printf("n/a\n");
}
//возведение (a) в степень (b)
/*double _pow(double a, double b) {
    return exp(b * log(a));
}*/
//поиск y

double serch_y (double x) {
    double y = 0;
    y = 0.007 * x*x*x*x;
    y += ((((22.8 * pow(x, 1/3)) - 1000) * x) + 3) / ((x * x) / 2);
    y -= x * pow((10 + x), 2/x);
    y -= 1.01;
    return (y);
}
int main(void) {
    double x;
    if (scanf("%lf", &x) != 1) {
        error();
        return 1;
    }
    //выводы
    printf("%.1lf", serch_y(x));
    return(x);
}
