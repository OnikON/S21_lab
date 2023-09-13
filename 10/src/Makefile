CC =gcc
CFLAGS = -Wall -Werror -Wextra -c
SOURCES = s21_string_test.c s21_string.c
OBJECTS = $(SOURCES:.c=.o)
NAME = main

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

rebuild: clean all

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(NAME)
	-rm $(QUESTS)