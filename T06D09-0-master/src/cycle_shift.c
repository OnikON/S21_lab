#include <stdio.h>

#define NMAX 10

short Input(int *mas,int *num,int *mov);
short OutputAndMov(int *mas,int num, int mov);

int main(void) {
    int num, mov, mas[NMAX];
    if(Input(mas, &num, &mov)) {
        mov = mov % num;
        //scanf("%d%d", &num, &mov);
        //mov = (mov >= 0) ? mov % num : (mov % num);
        //printf("%d\n", mov);
        OutputAndMov(mas, num, mov);
    }
}

short Input(int *mas, int *num, int *mov) {
    char buf;
    if (scanf("%d%c", num, &buf) !=2 || buf != '\n' || (*num < 0) || (*num > NMAX)) {
        return 0;
    }

    for (int *p = mas; p - mas < *num; p++) {
        if (scanf("%d%c", p, &buf) !=2 || (buf != '\n' && buf != ' ')) {
        return 0;
        }
    }

    if (scanf("%d%c", mov, &buf) !=2 || buf != '\n' && buf != EOF || (*num < 0) || (*num > NMAX)) {
        return 0;
    }

    return 1;
}

short OutputAndMov(int *mas, int num, int mov) {
    for (int i = 0; i < num-1; i++) {
        if (mov < 0) {
            printf("%d ", mas[num + mov]);
            mov++;
            continue;
        }
        if (mov < num && mov >= 0) {
            printf("%d ", mas[mov]);
            mov++;
        }
        else {
            mov -= num;
            printf("%d ", mas[mov]);
        }  
    }
    printf("%d", mas[mov]);
}