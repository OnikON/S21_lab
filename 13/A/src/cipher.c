#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>

#include "logger.h"

int Quest1(char* f_way);
int Quest2(FILE* F);
int GiveMod(void);
void GiveString(char** f_way);

int main(void) {
    //mod program
    int Mod = 777;
    //file way
    char* f_way = NULL;
    //saved copy file way
    char* cp_way = NULL;
    //char string
    char* buff_string = NULL;
    #ifdef Q5
    FILE* Log = NULL;
    Log = log_init("log.txt");
    #endif
    //main cicle
    while (Mod != -1) {
        Mod = GiveMod();
        printf("MainMod = %d\n", Mod);
        switch (Mod) {
            #ifdef Q1
            case 1:
                GiveString(&f_way);
                if (!Quest1(f_way)) {
                    #ifdef Q5
                        logcat(Log, "Quest1 complete\n\0", debug);
                    #endif
                }
                else {
                    #ifdef Q5
                        logcat(Log, "Quest1 no complete\n\0", error);
                    #endif
                }
                if (cp_way != NULL) {
                    free(cp_way);
                    cp_way = NULL;
                }
                cp_way = malloc((strlen(f_way)+1) * sizeof(char));
                cp_way = strcpy(cp_way, f_way);
                free(f_way);
                f_way = NULL;
            break;
            #endif
            #ifdef Q2
            case 2:
                if (cp_way != NULL) {
                    FILE *F = fopen(cp_way, "a");
                    Quest2(F);
                    fclose(F);
                    Quest1(cp_way);
                    #ifdef Q5
                        logcat(Log, "Quest2 redy\n\0", debug);
                    #endif
                }
                else {
                    printf("n/a\n");
                    #ifdef Q5
                        logcat(Log, "Quest2 no way to file\n\0", error);
                    #endif
                    
                }
            break;
            #endif
            case -1:
            break;
            default:
                printf("n/a\n");
                #ifdef Q5
                    logcat(Log, "Unknow command.\n\0", warning);    
                #endif
        }
    }
    #ifdef Q5
    fclose(Log);
    //log_close(Log);
    #endif
    
    return 0;
}

int Quest1(char* f_way){
    FILE* F = NULL;
    char ch;
    int flag = 1;
    F = fopen(f_way, "r");
    int count = 0;
    if (F) {
        while (!feof(F) && !ferror(F)) {
            ch = getc(F);
            if (ch != EOF) {
                putchar(ch);
                count++;
            }
        }
        if (count != 0) {
            putchar('\n');
        }
        
    }
    else {
        printf("n/a\n");
        flag = 0;
    }
    if (count == 0 && flag == 1) {
        printf("n/a\n");
        flag = 0;
    }
    fclose(F);
    return flag;
}
//scan 1 num if in string mor -> bad input
int GiveMod(void) {
    int Mod = 777;
    scanf("%d", &Mod);
    if (getc(stdin) != '\n') {
        scanf("%*s");
        Mod = 777;
    }
    printf("Mod = %d\n", Mod);
    return Mod;
}

void GiveString(char** f_way) {
    char buff;
    buff = getc(stdin);
    int count = 1;
    while (buff != '\n') {
        (*f_way) = realloc((*f_way) ,(count+1) * sizeof(char));
        (*f_way)[count - 1] = buff;
        buff = getc(stdin);
        count++;
    }
}

int Quest2(FILE* F) {
    char buff;
    do {
        buff = getc(stdin);
        fputc(buff, F);
    }while (buff != '\n');
}

char* Save_F(FILE* F, char *mass) {
    mass = malloc(sizeof(char));
    char ch;
    int count = 0;
    int flag = 1;
    if (F) {
        while (!feof(F) && !ferror(F)) {
            ch = getc(F);
            count++;
            mass = realloc(mass, (count + 1) * sizeof(char));
            mass[count - 1] = ch;
        }
    }
    return mass;
}
/*
void Quest3(char* str) {

    DIR *dir;
    struct dirent *dp;

    if ((dir = opendir ("ForTest")) == NULL) {
        perror ("n/a");
    }

    FILE* F;
    while ((dp = readdir (dir)) != NULL) {
        (strstr(".c", dp) != NULL) {
            F = fopen()
        }
        else {

        }
    }

}

int if_Up_R(char ch) {
    int result = 0;
    // Если символ больше либо равна 'А' и меньше либо равна 'Я', то вернуть 1(true)
    if (ch >= 'А' && ch <= 'Я')
        result = 1;

    return result;
}

int if_Up_U(char ch) {
    int result = 0;
    // Если символ больше либо равна 'А' и меньше либо равна 'Я', то вернуть 1(true)
    if (ch >= 'A' && ch <= 'Z')
        result = 1;

    return result;
}

int if_Low_R(char ch) {
    int result = 0;
    // Если символ больше либо равен 'а' и меньше либо равна 'я', то вернуть 1(true)
    if (ch >= 'а' && ch <= 'я')
        result = 1;

    return result;
}

int if_Low_U(char ch) {
    int result = 0;
    // Если символ больше либо равен 'а' и меньше либо равна 'я', то вернуть 1(true)
    if (ch >= 'a' && ch <= 'z')
        result = 1;
    return result;
}

int if_Num(char ch) {
    int result = 0;
    if (ch >= '0' && ch <= '9')
        result = 1;
    return result;
}
*/

