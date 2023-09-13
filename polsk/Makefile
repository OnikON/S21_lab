BUILD = in_p.c struct.c test.c
OBJECT = $(BUILD:.c=.o)

CC = gcc
FLAG =

NAME = main

all: clean_o testik1

rebuild:clean_o all

testik1: $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME) -lm

.o:.c
	$(CC) $(FLAG) -c $< -o $@ -lm

clean_o:
	rm -rf *.o