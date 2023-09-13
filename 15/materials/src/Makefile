.PHONY: cipher logging_cipher all clean rebuild

CC = gcc
CFLAG = -Wall -Werror -Wextra
SOURCES = logger.c
OBJECTS = $(SOURCES:.c=.o)
NAME = main

WAY = ../build/

all: cipher logging_cipher

rebuild: clean all 

cipher: CIP
	$(CC) cipher.o -o $(WAY)cipher

logging_cipher: LOG $(SOURCES)
	$(CC) cipher.o $(SOURCES) -o $(WAY)logging_cipher

CIP:
	$(CC) -DQ1 -DQ2 -c cipher.c -o cipher.o

LOG:
	$(CC) -DQ1 -DQ2 -DQ5 -c cipher.c -o cipher.o

.o:.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf $(NAME)