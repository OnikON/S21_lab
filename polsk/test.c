#include <stdio.h>
#include <stdlib.h>

#include "in_p.h"
#include "struct.h"

#define DEVELOP 0

int main(void) {
    LIST* list = list_init();
#if DEVELOP == 1

    LIST* head = list;
    printf("value head = %c\n", head->value);
    list->value = 'f';
    printf("value head = %c\n", head->value);

    LIST* tmp = list_add_R(&list, '5', -1, 0);

    printf("value tmp = %c\n", tmp->value);
    printf("value head->r = %c\n", head->r->value);

    tmp = list_add_L(&tmp, '3', -1, 0);
    printf("value tmp = %c\n", tmp->value);
    printf("value head->r = %c\n", head->r->value);
#endif
    /*указатели на начало и конец спписка
    УКАЗАТЕЛЬ на начало в коде не меняется*/
    //нулевой элемент списка нужен чтоб понимать что это конец
    //считвем строку

    if (do_p(&list, stdin)) {
        LIST* tmpl = list;
        /*
        printf ("\nvalue main = %c ", tmpl->value);
        for (int i = 0; i < 6; i++) {
            printf ("\nvalue main = %c ", tmpl->value);
            tmpl = tmpl->r;
        }*/
        printf("\n");
        while (tmpl != NULL) {
            if (tmpl->flag == 1) {
                if (tmpl->sign == -1) {
                    printf("%c(*-1) ", tmpl->value);
                } else {
                    printf("%c(%d) ", tmpl->value, tmpl->flag);
                }
            } else {
                printf("%c(%d)", tmpl->value, tmpl->flag);
            }
            tmpl = tmpl->r;
        }
        printf("\nend\n");
        printf("\n\n");
        //@ - начало
        POLSK* polsk = polsk_init('@', 777);

        do_struct_polsk(&list, &polsk);

        POLSK* tmp_p = polsk;
        //вывод всего что лежит в польском списке
        while (tmp_p != NULL) {
            printf("c = %c ", tmp_p->sign);
            printf("d = %lf\n", tmp_p->value);

            tmp_p = tmp_p->r;
        }

        printf("   |\n");
        POLSK* B = polsk_cp(&polsk);
        printf("   |\n");

        printf("ansver = %lf ", do_math(&B, 12));

        list_destroy(&list);
        polsk_destroy(&polsk);

        return 0;
    } else {
        return 1;
    }
}