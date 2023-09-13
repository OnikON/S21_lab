#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"
#include "list.h"

struct node* init(struct door* door) {
    NODE* tmp = NULL;
    if(door != NULL) {
        tmp = malloc(sizeof(NODE));
        tmp->door = door;
        tmp->next = NULL;
    }
    return tmp;
}

struct node* add_door(struct node* elem, struct door* door) {
    NODE* tmp = NULL;
    if (elem != NULL && door != NULL) {
        tmp = init(door);
        tmp->next = elem->next;
        elem->next = tmp;
    }
    return tmp;
}

struct node* find_door(int door_id, struct node* root) {
    NODE *tmp = root;
    if (root != NULL) {
        while(tmp != NULL && tmp->door->id != door_id) {
            tmp = tmp->next;
        }
    }
    return tmp;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem != NULL && root != NULL) {
        NODE *befor = root;
        NODE *delet = root;
        while (delet != elem && delet != NULL) {
            befor = delet;
            delet = delet->next;
        }
        if (delet == elem && delet != root) {
            befor->next = delet->next;
            free(delet);
        }
        if (delet == elem && delet == root) {
            root = root->next;
            free(befor);
        }
    }
    return root;
}

void destroy(struct node* root) {
    if (root != NULL) {
        NODE *tmp = root;
        while (root != NULL) {
            root = root->next;
            free(tmp);
            tmp = root;
        }
    }
}