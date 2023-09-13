CС=gcc
CFLAGS=-Wall -Werror -Wextra
SRC = main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
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