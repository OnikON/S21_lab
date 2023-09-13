#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

#define NODE struct node

//инициализация структуры односвязного списка на базе переданной struct door
struct node {
  struct door* door;
  struct node* next;
};
//иницилизация
struct node* init(struct door* door);
//вставка нового узла
struct node* add_door(struct node* elem, struct door* door);
//поиск узла по id
struct node* find_door(int door_id, struct node* root);
//удаление элемента
struct node* remove_door(struct node* elem, struct node* root);
//освобождене памяти
void destroy(struct node* root);

#endif