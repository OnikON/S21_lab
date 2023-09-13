#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define W 25
#define H 80

void GameMenu(int *key, int flag);
void Print_menu(char *c, int Delay);
void Game(int num_picture);
void Input(int ***masN, int ***masO, FILE *IN);
void PrintFrame(int **MasN, int **MasO, int Delay);
void Logick(int **MasN, int **MasO);
short LifeCount(int **mas, int a, int b);
void Output(int **mas);
void MasCP(int **masN, int **masO);

int main(void) {
    int num_picture;
    GameMenu(&num_picture, 0);
    system("clear");
    Game(num_picture);
}

void GameMenu(int *num_picture, int flag) {
    char *str_0 = "введите одну из следующих комманд";
    char *str_1 = "1 - начать игру с файлом 1";
    char *str_2 = "2 - начать игру с файлом 2";
    char *str_3 = "3 - начать игру с файлом 3";
    char *str_4 = "4 - начать игру с файлом 4";
    char *str_5 = "5 - начать игру с файлом 5";
    char *str_6 = "6 - ввести в ручную";

    system("clear");
    if (flag == 1) {
        printf("Вы ввели не верное число\n");
    }
    printf("loading...\n");
    int Delay = 7000;
    Print_menu(str_0, 5555);
    Print_menu(str_1, Delay);
    Print_menu(str_2, Delay);
    Print_menu(str_3, Delay);
    Print_menu(str_4, Delay);
    Print_menu(str_5, Delay);
    Print_menu(str_6, Delay);
    //ЗАДЕРЖКА
    char buff;
    scanf("%d%c", num_picture, &buff);
    if (buff != '\n') {
        scanf("%*s");
    }
    if (*num_picture < 1 || *num_picture > 6) {
        GameMenu(num_picture, 1);
    }
}
//задержка в микросекундах
void Print_menu(char *c, int Delay) {
    for (size_t i = 0; i < strlen(c); i++) {
        printf("%c", c[i]);
        fflush(stdout);
        usleep(Delay);
    }
    printf("\n");
}

void Game(int num_picture) {
    char *str_1 = "preset/";
    char *str_3 = ".txt";
    char *buff;
    buff = calloc((strlen(str_1) + 1 + strlen(str_3)), sizeof(char));
    strcat(buff, str_1);
    *(buff + strlen(str_1)) = num_picture + 48;
    strcat(buff + strlen(str_1) + 1, str_3);
    FILE *IN = (num_picture != 6) ? fopen(buff, "r") : stdin;
    free(buff);
    int **masN, **masO;
    Input(&masN, &masO, IN);
    char c;
    int count = 0;
    int Delay = 1000000;
    do {
        c = 'r';
        printf("\n%d", count++);
        PrintFrame(masN, masO, Delay);
        fd_set rfds;
        struct timeval tv;
        int retval;
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        tv.tv_sec = 0;
        tv.tv_usec = 1;
        retval = select(1, &rfds, NULL, NULL, &tv);
        if (retval) {
            c = getc(stdin);
            if (c == '=' || c == '+') {
                Delay = (Delay / 2 != 0) ? (Delay / 2) : 10;
            }
            if (c == '-' || c == '_') {
                Delay = (Delay * 2 < INT_MAX - 1) ? (Delay * 2) : INT_MAX - 1;
            }
        }
    } while (c != 'q' && c != 'Q');
    free(masN);
    free(masO);
    fclose(IN);
}

void Input(int ***masN, int ***masO, FILE *IN) {
    *masN = malloc(W * sizeof(int *));
    *masO = malloc(W * sizeof(int *));
    for (int i = 0; i < W; i++) {
        (*masN)[i] = malloc(H * sizeof(int));
        (*masO)[i] = malloc(H * sizeof(int));
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            char buff;
            fscanf(IN, "%c", &buff);
            while (buff == '\n' || buff == '\r' || buff == ' ') {
                fscanf(IN, "%c", &buff);
            }
            if (buff != '1' && buff != '0') {
                printf("ошибка в файле!!!\n");
                exit(1);
            }
            (*masN)[i][j] = buff;
            (*masO)[i][j] = buff;
        }
    }
}

void PrintFrame(int **MasN, int **MasO, int Delay) {
    usleep(Delay);
    system("clear");
    Logick(MasN, MasO);
    Output(MasN);
    MasCP(MasN, MasO);
}

void Logick(int **MasN, int **MasO) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (MasO[i][j] == '1') {
                int count = LifeCount(MasO, i, j) - 1;
                if (count != 2 && count != 3) {
                    MasN[i][j] = 48;
                }
            }
            if (MasO[i][j] == '0') {
                int count = LifeCount(MasO, i, j);
                if (count == 3) {
                    MasN[i][j] = 49;
                }
            }
        }
    }
}

short LifeCount(int **mas, int a, int b) {
    short count = 0;

    for (int i = a - 1; i <= a + 1; i++) {
        for (int j = b - 1; j <= b + 1; j++) {
            if (i >= 0 && i < W && j >= 0 && j < H && mas[i][j] == 49) {
                count++;
            } else {
                int Si = i;
                int Sj = j;
                if (i < 0) {
                    i = W - 1;
                }
                if (i == W) {
                    i = 0;
                }
                if (j < 0) {
                    j = H - 1;
                }
                if (j == H) {
                    j = 0;
                }
                if (mas[i][j] == 49) {
                    count++;
                }
                i = Si;
                j = Sj;
            }
        }
    }
    return count;
}

void Output(int **mas) {
    printf("\n\n");
    for (int i = 0; i < W; i++) {
        printf("\n");
        for (int j = 0; j < H; j++) {
            char buff;
            buff = (char)mas[i][j];
            if (buff == '0') {
                printf("-");
            } else {
                printf("*");
            }
        }
    }
    printf(
        "\n 'q' - выход из файла; '-' - уменьшить скорость; '+' - увеличить скорость.\n для активации "
        "комманды нажмите Enter");
}

void MasCP(int **masN, int **masO) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            masO[i][j] = masN[i][j];
        }
    }
}
