#ifndef STRUCT_H
#define STRUCT_H

#define LIST struct list
#define POLSK struct polsk

LIST {
    LIST* r;
    LIST* l;
    char value;
    short flag;
    short sign;
};

POLSK {
    POLSK* r;
    POLSK* l;
    char sign;
    double value;
};

POLSK* polsk_init(char sign, double value);

LIST* list_init();
// if r = NULL
LIST* list_add_R(LIST** list, char value, short sign, short flag);
// if l = NULL
LIST* list_add_L(LIST** list, char value, short sign, short flag);

#define STACK struct stack

STACK {
    char value;
    STACK* last;
};

STACK* stack_init(char value);
STACK* stack_push(char value, STACK* stack);
char stack_pop(STACK** stack);
POLSK* polsk_cp(POLSK** M);

void polsk_destroy(POLSK** point);
void list_destroy(LIST** list);
void stack_destroy(STACK** stack);

#endif