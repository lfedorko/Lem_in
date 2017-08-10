NAME = lem_in

CFLAGS = -Wall -Wextra -Werror

SRC = main.c validation.c

OBJECTS = $(SRC:.c=.o)

LIB = ./libft/

LIB_INC = ./libft/libft.h

all: $(LIB)libft.a $(NAME)

$(NAME):  $(OBJECTS)
	@gcc $(OBJECTS) $(LIB)libft.a -o $(NAME)
	@echo "\033[34mLem in ready!\033[0m"

%.o: %.c
	@gcc -c $< $(CFLAGS) -o $@

$(LIB)libft.a:
	@make -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all