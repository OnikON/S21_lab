#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "door_struct.h"
#include "list.h"

void check_add_door (void);

int main(void) {
    check_add_door();
    return 0;
}

void check_add_door (void) {
    DOOR dor0 = {0, 0};
    NODE *head = init(&dor0);

    DOOR dor1 = {1, 1};
    DOOR dor2 = {2, 1};
    DOOR dor3 = {3, 1};
    DOOR dor4 = {4, 0};
    DOOR dor5 = {5, 0};
    //test 1
    printf ("test - add_door\n");
    NODE *tmp = add_door(head, &dor1);
    printf("%d, %d\n", tmp->door->id, tmp->door->status);
    if (tmp->door->id == dor1.id && tmp->door->status == dor1.status) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    tmp = add_door(head, &dor2);
    printf("%d, %d\n", tmp->door->id, tmp->door->status);
    if (tmp->door->id == dor2.id && tmp->door->status == dor2.status) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    tmp = add_door(head, &dor3);
    printf("%d, %d\n", tmp->door->id, tmp->door->status);
    if (tmp->door->id == dor3.id && tmp->door->status == dor3.status) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    tmp = add_door(head, &dor4);
    printf("%d, %d\n", tmp->door->id, tmp->door->status);
    if (tmp->door->id == dor4.id && tmp->door->status == dor4.status) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    tmp = add_door(head, &dor5);
    printf("%d, %d\n", tmp->door->id, tmp->door->status);
    if (tmp->door->id == dor5.id && tmp->door->status == dor5.status) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }
    printf ("test - remove_door\n");
    tmp = head->next;
    head = remove_door(head->next, head);
    if (tmp != head->next) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    tmp = head->next;
    head = remove_door(head->next, head);
    if (tmp != head->next) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    tmp = head->next;
    head = remove_door(head->next, head);
    if (tmp != head->next) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAIL\n");
    }

    destroy(head);
}