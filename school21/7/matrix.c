#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
/* DEWELOP == 1 - режим разработчика 
   нужно для проверки работотспособности участков кода
   выводит дополнительную информацию в консоль
   для компиляции кода в стандартном режиме - DEWELOP != 1*/
#define DEWELOP 1

short InputStart(int *n);

int main(void) {
    int flag;
    int **mas;
    int string, column;
    if (InputStart(&flag) && (flag > 0 && flag < 5)){
        #if DEWELOP == 1
        printf("flag = %d\n", flag);
        #endif
        switch (flag) {
            case 1:

        }
        return 0;
    }
    printf("n/a");
    return 1;
}

short DynamicInput_1(int ***mas, int *string, int *column) {
    char buf;
    if (scanf("%d %d%c", string, column, &buf) !=3 || buf != '\n') {
        return 0;
    }
    if (string <= 0 || column <= 0){
        return 0;
    }
    
}

short InputStart(int *n) {
    char buf;
    if (scanf("%d%c", n, &buf) !=2 || buf != '\n') {
        return 0;
    }
    return 1;
}