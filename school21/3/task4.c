#include <stdio.h>

#define TRUE 1
#define FALSE 0

//проверяет является ли введённое число целым
short check_on_int(float value) {
    return (int) value == value ? TRUE : FALSE;
}

void error(){
    printf("n/a\n");
}

//поиск максимума
short serch_max(int value1, int value2) {
    if (value1 == value2) {
        error();
        return 1;
    }
    value1 > value2 ? printf("%d\n", value1) : printf("%d\n", value2);
    return 0;
}

int main(void) {
    float num_1, num_2;
    if (scanf("%f %f", &num_1, &num_2) != 2) {
        error();
        return 1;
    }
    //проверка на целостность чисел
    if (!check_on_int(num_1) || !check_on_int(num_2)) {
        error();
        return 1;
    }
    //прееформатирование
    int Num_1, Num_2;
    Num_1 = num_1;
    Num_2 = num_2;
    //выводы
    return(serch_max(Num_1, Num_2));
}
