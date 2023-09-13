CС=gcc
CFLAGS=-Wall -Werror -Wextra
SRC = yet_another_decision_module_entry.c decision.c ../data_libs/data_io.c ../data_libs/data_stat.c
OBJ = $(SRC:.c=.o)
NAME = main
POSTFIX = -lm

all: $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(POSTFIX)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(POSTFIX)

rebuild: all

.o : .c
	$(CC) $(CFLAGS) -c %< -o $@ $(POSTFIX)

clean :
	rm $(OBJ)
	rm $(NAME)