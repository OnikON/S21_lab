CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCE_Q1 = dmanager_module.c
OBJECTS_Q1 = $(SOURCE_Q1:.c=.o)

SOURCE_Q2 = list.c list_test.c
OBJECTS_Q2 = $(SOURCE_Q2:.c=.o)

EXECUTABLE = main

TASK_WAY = ../build/Quest_

all: door_struct

door_struct: $(OBJECTS_Q1)
	$(CC) $(OBJECTS_Q1) -o $(TASK_WAY)1
	rm -rf $(OBJECTS_Q1)

list_test: $(OBJECTS_Q2)
	$(CC) $(OBJECTS_Q2) -o $(TASK_WAY)2
	rm -rf $(OBJECTS_Q2)

rebuild: clean all

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf $(TASK_WAY)*