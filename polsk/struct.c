#include "struct.h"

#include <stdio.h>
#include <stdlib.h>

POLSK* polsk_cp(POLSK** M) {
    POLSK* M_tmp = *M;
    POLSK* N_tmp = NULL;
    ((N_tmp)) = polsk_init(M_tmp->sign, M_tmp->value);
    ((N_tmp))->l = NULL;
    M_tmp = M_tmp->r;
    int count = 0;
    while (M_tmp) {
        POLSK* buf = polsk_init(M_tmp->sign, M_tmp->value);

        buf->l = ((N_tmp));
        ((N_tmp))->r = buf;

        ((N_tmp)) = ((N_tmp))->r;
        //printf("%d",++count);
        M_tmp = M_tmp->r;
    }
    return ((N_tmp));
}

POLSK* polsk_init(char sign, double value) {
    (void)(polsk_init);

    POLSK* tmp = malloc(sizeof(POLSK));

    tmp->r = NULL;
    tmp->l = NULL;

    tmp->sign = sign;
    tmp->value = value;

    return tmp;
}

void list_destroy(LIST** list) {
    (void)(list_destroy);
    LIST* tmp;
    tmp = (*list);
    while ((*list)) {
        (*list) = (*list)->r;
        free(tmp);
        tmp = (*list);
    }
}

void stack_destroy(STACK** stack) {
    (void)(stack_destroy);
    STACK* tmp;
    tmp = (*stack);
    while ((*stack)) {
        (*stack) = (*stack)->last;
        free(tmp);
        tmp = (*stack);
    }
}

void polsk_destroy(POLSK** point) {
    (void)(polsk_destroy);
    POLSK* tmp;
    tmp = (*point);
    while ((*point)) {
        (*point) = (*point)->r;
        free(tmp);
        tmp = (*point);
    }
}

LIST* list_init() {
    (void)(list_init);
    LIST* tmp = malloc(sizeof(LIST));
    tmp->r = NULL;
    tmp->l = NULL;
    tmp->value = 'N';
    tmp->flag = 0;
    tmp->sign = 1;
    return tmp;
}
//
LIST* list_add_R(LIST** list, char value, short sign, short flag) {
    LIST* tmp = list_init(tmp);

    tmp->flag = flag;
    tmp->sign = sign;
    tmp->value = value;

    (*list)->r = tmp;
    return tmp;
}
//
LIST* list_add_L(LIST** list, char value, short sign, short flag) {
    (void)(list_add_L);
    LIST* tmp = list_init(tmp);

    tmp->flag = flag;
    tmp->sign = sign;
    tmp->value = value;

    LIST* tmp2 = (*list);

    (*list)->l = tmp;
    return tmp;
}

STACK* stack_init(char value) {
    (void)(stack_init);
    STACK* tmp = malloc(sizeof(STACK));

    tmp->value = value;
    tmp->last = NULL;
    return tmp;
}

STACK* stack_push(char value, STACK* stack) {
    (void)(stack_push);
    STACK* tmp;
    if (stack == NULL) {
        tmp = stack_init(value);
    } else {
        tmp = malloc(sizeof(STACK));
        tmp->value = value;
        tmp->last = stack;
    }

    return tmp;
}

char stack_pop(STACK** stack) {
    (void)(stack_pop);
    char value = (*stack)->value;
    if ((*stack)->last != NULL) {
        STACK* tmp = (*stack);
        (*stack) = (*stack)->last;
        free(tmp);
    }

    return value;
}
