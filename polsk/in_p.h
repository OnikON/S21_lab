#ifndef IN_P_H
#define IN_P_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "in_p.h"
#include "struct.h"

POLSK* giv_num(POLSK** string, double** mas, double X);
double do_math(POLSK** string, double X);
int do_struct_polsk(LIST** string, POLSK** Pstring);
POLSK* giv_nums(POLSK** string, double** mas, double X);

int do_p(LIST** string, FILE* IN);
int logick(char ch);
LIST* stack_logic(STACK** stack, LIST** list, int prioritet);
char check_func(FILE* IN, char ch);
int checker_func(char ch);

void stack_print(STACK* tmp);

#endif