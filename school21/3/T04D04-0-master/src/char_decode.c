#include <stdio.h>

#define TRUE 1
#define FALSE 0

void error() {
    printf("n/a");
}

short cod() {
    char value_1;
    char valuse_2;
    while(1) {
        if (scanf("%c%c", &value_1, &valuse_2) != 2 || (valuse_2 != ' ' && valuse_2 != '\n')) { 
            error();
            return FALSE;
        }
        if (valuse_2 == ' ') { printf("%X ", value_1); }
        else {
            printf("%X", value_1);
            return TRUE;
        }
    }
}

short de_code() {
    char value_1;
    char valuse_2;
    while(1) {
        if (scanf("%c%c", &value_1, &valuse_2) != 2 || (value_1 < 0x21 && value_1 > 0x7E) || (valuse_2 != ' ' && valuse_2 != '\n')) { 
            error();
            return FALSE;
        }
        if (valuse_2 == ' ') { printf("%c ", value_1); }
        else {
            printf("%c", value_1);
            return TRUE;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error();
        return 1;
    }
    //кодирование
    if (*argv[1] == '0') {
        return cod();
    }
    //декодирование
    if (*argv[1] == '1') {
        return de_code();
    }
    else { return 1; }
}