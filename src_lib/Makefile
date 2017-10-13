NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJECTS = ft_printf/to_struct.o\
		ft_printf/ft_printf.o\
		ft_printf/convert_size.o\
		ft_printf/handle_output.o\
		ft_printf/handle_string.o\
		ft_printf/itoa_base.o\
		ft_printf/add_functions1.o\
		ft_printf/add_functions2.o\
		ft_printf/fill_array.o\
		ft_printf/handle_bonus.o\
		ft_printf/handle_widestring.o\
		ft_printf/handle_char.o


LIB = ./libft/

LIB_INC = ./libft/libft.h

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)libft.a
	@ar rc $(NAME) $(OBJECTS) $(LIB)*.o
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I $(LIB) -I $(LIB_INC) -I ft_printf.h

$(LIB)libft.a:
	@make -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
