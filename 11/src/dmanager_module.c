#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

#define DEVELOP 0

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void all_door_status(struct door*, int doors);
void output(struct door* doors);

int main()
{
    struct door doors[DOORS_COUNT];
    
    initialize_doors(doors);
    #if DEVELOP == 1
    output(doors);
    printf("___________________________________\n");
    #endif
    sort_doors(doors);
    #if DEVELOP == 1
    output(doors);
    printf("___________________________________\n");
    #endif
    all_door_status(doors, 0);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors)
{
    srand(time(0)); 
    
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id >= doors[j + 1].id) {
                int value = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = value;
                value = doors[j].status;
                doors[j].status = doors[j + 1].status;
                doors[j + 1].status = value;
            }
        }
    }
}

void all_door_status(struct door* doors, int status) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = status;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, ", doors[i].id);
        if (i != DOORS_COUNT - 1) {
            printf("%d\n", doors[i].status);
        }
        else {
            printf("%d", doors[i].status);
        }
    }
}