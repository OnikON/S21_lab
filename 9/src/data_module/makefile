CС=gcc
CFLAGS=-Wall -Werror -Wextra
SRC = data_module_entry.c data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c
SOURCES = data_module_entry.c data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c
OBJ = $(SRC:.c=.o)
NAME = main

all: $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(POSTFIX)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

rebuild: all

.o : .c
	$(CC) $(CFLAGS) -c %< -o $@

clean :
	rm $(OBJ)
	rm $(NAME)