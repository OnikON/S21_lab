#include "in_p.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

int do_struct_polsk(LIST** string, POLSK** Pstring) {
    int back = 0;

    LIST* tmpL = (*string);
    tmpL = tmpL->r;

    POLSK* tmpP;
    POLSK* point = *Pstring;

    while (tmpL != NULL) {
        int flag = 1;
        if (tmpL->value == 'x' || tmpL->value == 'X') {
            (tmpP) = polsk_init('X', 777);
            (point)->r = (tmpP);
            (tmpP)->l = (point);
            point = (point)->r;
        } else {
            //если это число
            if (tmpL->flag == 1 || tmpL->flag == 0) {
                //если это не конец числа
                if (tmpL->flag == 0) {
                    //собираем число
                    double num = 0;
                    //если в начале стоит точка
                    if (tmpL->value == '.') {
                        flag = -1;
                    }
                    //если в начале стоит число
                    else {
                        num = (tmpL->value - '0');
                    }
                    //прыгаем на некст элемент списка
                    tmpL = tmpL->r;
                    //делать пока не встретим элемент яв. концом числа
                    while (tmpL->flag != 1) {
                        //если это целая часть
                        if (flag == 1) {
                            //если эт точка меняем флаг операции
                            if (tmpL->value == '.') {
                                flag = -1;
                            }
                            //если это цифра, то всё ок
                            else {
                                num = (num * 10) + (tmpL->value - '0');
                            }
                            //
                        }
                        if (flag != 1) {
                            if (tmpL->value == '.') {
                                printf("bad input");
                                back = 0;
                            } else {
                                num = num + ((tmpL->value - '0') * pow(10, flag));
                                flag--;
                            }
                        }
                        tmpL = tmpL->r;
                    }
                    if (flag == 1) {
                        num = (num * 10) + (tmpL->value - '0');
                    } else {
                        num = num + ((tmpL->value - '0') * pow(10, flag));
                    }

                    // TRUE
                    (tmpP) = polsk_init('$', num);
                    (point)->r = (tmpP);
                    (tmpP)->l = (point);
                    point = (point)->r;
                } else {
                    double num = (tmpL->value - '0');
                    (tmpP) = polsk_init('$', num);
                    (point)->r = (tmpP);
                    (tmpP)->l = (point);
                    point = (point)->r;
                }
            } else {
                printf("YES");
                (tmpP) = polsk_init(tmpL->value, 777);
                (point)->r = (tmpP);
                (tmpP)->l = (point);
                point = (point)->r;
            }
        }
        tmpL = tmpL->r;
    }
    return back;
}

double do_math(POLSK** string, double X) {
    X = (X * 4 * M_PI)/79;
    POLSK* tmp = (*string)->r;
    double* nums = malloc(2*sizeof(double));
    double answer = 0;
    while(tmp != NULL) {
        //идём до первого знака
        while (tmp->sign == '$') {
            tmp = tmp->r;
        }
        printf ("t->sign=%c\n", tmp->sign);
        switch (tmp->sign) {
            case '+':
                tmp = giv_nums(&tmp, &nums, X);
                tmp->value = nums[0] + nums[1];
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case '-':
                tmp = giv_nums(&tmp, &nums, X);
                tmp->value = nums[0] - nums[1];
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case '*':
                tmp = giv_nums(&tmp, &nums, X);
                tmp->value = nums[0] * nums[1];
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case '/':
                tmp = giv_nums(&tmp, &nums, X);
                tmp->value = nums[0] / nums[1];
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case 's':
                tmp = giv_num(&tmp, &nums, X);
                tmp->value = sin(nums[0]);
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case 'S':
                tmp = giv_num(&tmp, &nums, X);
                tmp->value = sqrt(nums[0]);
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case 'c':
                tmp = giv_num(&tmp, &nums, X);
                tmp->value = cos(nums[0]);
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case 'C':
                tmp = giv_num(&tmp, &nums, X);
                tmp->value = pow(1.0/tan(nums[0]), 2);
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case 't':
                tmp = giv_num(&tmp, &nums, X);
                tmp->value = tan(nums[0]);
                tmp->sign = '$';
                answer = tmp->value;
                break;
            case 'l':
                tmp = giv_num(&tmp, &nums, X);
                tmp->value = log(nums[0]);
                tmp->sign = '$';
                answer = tmp->value;
                break;
        }
        POLSK* tmp_p = *string;
         while (tmp_p != NULL) {
            printf("c = %c ", tmp_p->sign);
            printf("d = %lf\n", tmp_p->value);

            tmp_p = tmp_p->r;
        }
        printf("-------------------------------------------------------\n");
        tmp = tmp->r;
    }
    free(nums);
    return answer;
}

/*
double do_math(POLSK** string, double X) {
    POLSK* tmp = (*string)->r;
    double* nums = malloc(2 * sizeof(double));
    double ansver = 0;
    while (tmp != NULL) {
        //идём до первого знака иксы проходим
        while (tmp->sign == '$' || tmp->sign == 'X') {
            tmp = tmp->r;
        }
        // printf ("t->sign=%c\n", tmp->sign);
        switch (tmp->sign) {
            case '+':
                tmp = giv_nums(&tmp, &nums, X);
                tmp->value = nums[0] + nums[1];
                tmp->sign = '$';
                ansver = tmp->value;
                break;
            case 'X':

                break;
        }
        tmp = tmp->r;
    }
    free(nums);
    return ansver;
}*/

POLSK* giv_num(POLSK** string, double** mas, double X) {
    POLSK* tmp = (*string);
    POLSK* tmpL = (*string);
    tmpL = tmpL->l;
    tmpL = tmpL->l;

    if (tmp->l->sign == 'X') {
        (*mas)[0] = X;
        printf("227 = %lf\n", (*mas)[0]);
    } else {
        (*mas)[0] = tmp->l->value;
        printf("227 = %lf\n", (*mas)[0]);
    }

    free(tmp->l);

    tmpL->r = tmp;
    tmp->l = tmpL;
    // printf("FFF");
    return tmp;
}

POLSK* giv_nums(POLSK** string, double** mas, double X) {
    POLSK* tmp = (*string);
    POLSK* tmpL = (*string);
    tmpL = tmpL->l;
    tmpL = tmpL->l;
    tmpL = tmpL->l;

    if (tmp->l->sign == 'X') {
        (*mas)[0] = X;
        printf("0 = %lf\n", (*mas)[0]);
    } else {
        (*mas)[0] = tmp->l->value;
        printf("0 = %lf\n", (*mas)[0]);
    }

    if (tmp->l->l->sign == 'X') {
        (*mas)[1] = X;
        printf("0 = %lf\n", (*mas)[1]);
    } else {
        (*mas)[1] = tmp->l->l->value;
        printf("0 = %lf\n", (*mas)[1]);
    }

    free(tmp->l->l);
    free(tmp->l);

    tmpL->r = tmp;
    tmp->l = tmpL;
    // printf("FFF");
    return tmp;
}

int do_p(LIST** string, FILE* IN) {
    int f_return = 1;

    int index = 0;

    char c = getc(IN);
    int prioretet = logick(c);

    if (prioretet == 666) {
        printf("bad input\n");
        f_return = 0;
        c = 'q';
    }

    LIST* tmp = (*string);

    STACK* stack = stack_init('N');

    int sign = 1;

    while (c != 'q' && c != '\b' && c != EOF && c != '\n' && c != '\0') {
        // printf("4 = %c | %d\n", c,c);
        // printf("\nprior = %d\n", prioretet);
        if (prioretet == 69) {
            c = check_func(stdin, c);
            if (c == 'q') {
                prioretet = 666;
            } else {
                prioretet = 1;
            }
        }
        if (prioretet != 666) {
            //если число
            if (prioretet == 0) {
                tmp = list_add_R(&tmp, c, sign, 0);
                if (index > 0) {
                    index = 0;
                }
                sign = 1;
            } else {
                //если это первое вхождение после числа
                if (index == 0) {
                    tmp->flag = 1;
                }

                if (index > 0 && c == '-') {
                    sign = -1;
                } else {
                    if (c != '(') {
                        tmp = stack_logic(&stack, &tmp, prioretet);
                    }

                    // printf("ch1 = %c\n", (tmp)->value);
                    //если дошли до скобки товсё хоршош, надо схлопнуть.
                    if (stack->value == '(' && c == ')') {
                        stack_pop(&stack);
                        //если там стоит функция то её надо вытащить
                        if (checker_func(stack->value)) {
                            printf("YRA ");
                            tmp = list_add_R(&tmp, stack_pop(&stack), 0, 333);
                        }
                    }
                    if (c != ')') {
                        // if (!(checker_func(stack->value)))
                        // printf("YES\n");
                        stack = stack_push(c, stack);
                    }

                    // printf("c=%c\n", c);
                    // printf("pr=%d", prioretet);
                    // stack_print(stack);
                }
                index++;
            }
        }

        c = getc(IN);
        prioretet = logick(c);

        if (prioretet == 666 && c != '\b' && c != EOF && c != '\n' && c != '\0') {
            printf("bad input\n");
            f_return = 0;
            c = 'q';
        }
    }
    //tmp->flag = 1;

    while (stack->last != NULL) {
        char ch = stack_pop(&stack);
        (tmp) = list_add_R(&tmp, ch, 0, 222);
    }
    stack_destroy(&stack);

    // printf ("value=%c ", tmp->value);
    return f_return;
}

int logick(char ch) {
    short flag;

    flag = 666;

    if (ch == 's' || ch == 'c' || ch == 't' || ch == 'l') {
        flag = 69;
    }

    if (ch == 'N') {
        flag = 999;
    }

    if (ch == ')' || ch == '(') {
        flag = 4;
    }

    if (ch == '+' || ch == '-') {
        flag = 3;
    }

    if (ch == '*' || ch == '/') {
        flag = 2;
    }

    if (ch == '^') {
        flag = 1;
    }

    if (ch >= '0' && ch <= '9' || ch == '.' || ch == 'X' || ch == 'x') {
        flag = 0;
    }
    return flag;
}

LIST* stack_logic(STACK** stack, LIST** list, int prioritet) {
    STACK* tmpS = (*stack);
    LIST* tmpL = (*list);

    while (logick((*stack)->value) < prioritet && (*stack)->value != '(') {
        // printf("f\n");
        //ТУТ
        char ch = stack_pop(stack);
        // printf("ch = %c\n", ch);
        (*list) = list_add_R(list, ch, 0, 222);
    }
    // printf("ch = %c\n", (*list)->value);
    // printf("do\n");
    return *list;
}

char check_func(FILE* IN, char ch) {
    switch (ch) {
        char mass[3];
        case 's':
            mass[0] = getc(IN);
            mass[1] = getc(IN);
            if (strcmp(mass, "in") == 0) {
                ch = 's';
                printf("s\n");
            } else {
                mass[2] = getc(IN);
                if (strcmp(mass, "qrt") == 0) {
                    ch = 'S';
                    printf("s\n");
                } else {
                    ch = 'q';
                }
            }
            break;
        case 'c':
            mass[0] = getc(IN);
            mass[1] = getc(IN);
            if (strcmp(mass, "os") == 0) {
                ch = 'c';
                printf("c\n");
            } else {
                if (strcmp(mass, "tg") == 0) {
                    ch = 'C';
                    printf("c\n");
                } else {
                    ch = 'q';
                }
            }
            break;
        case 't':
            mass[0] = getc(IN);
            mass[1] = getc(IN);
            if (strcmp(mass, "an") == 0) {
                ch = 't';
                printf("t\n");
            } else {
                ch = 'q';
            }
            break;
        case 'l':
            mass[0] = getc(IN);
            if (mass[0] == 'n') {
                ch = 'l';
                printf("l\n");
            } else {
                ch = 'q';
            }
            break;
    }
    return ch;
}

int checker_func(char ch) {
    int flag = 0;
    if (ch == 'c' || ch == 'C' || ch == 's' || ch == 'S' || ch == 't' || ch == 'l') {
        flag = 1;
    }
    return flag;
}

void stack_print(STACK* tmp) {
    printf("\nstack:\n");
    while (tmp != 0) {
        printf("%c ", tmp->value);
        tmp = tmp->last;
    }
    printf("\n");
}
