NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

SRC = main.c handle_ants.c init.c get_next_line.c \
	handle_rooms.c \
	handle_path.c \
	find_paths.c \
	dfs.c \
	sort_list_of_paths.c \
	algo.c

OBJECTS = $(SRC:.c=.o)

LIB = ./src_lib/

PRINTF_INC = ./src_lib/ft_printf/ft_printf.h

all: $(LIB)libftprintf.a $(NAME)

$(NAME):  $(OBJECTS)
	@gcc $(OBJECTS) $(LIB)libftprintf.a -o $(NAME)
	@echo "\033[34mLem in ready!\033[0m"

%.o: %.c
	@gcc -c $< -o $@

$(LIB)libftprintf.a:
	@make -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all