#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askochen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/26 16:38:20 by askochen          #+#    #+#              #
#    Updated: 2017/07/05 20:07:10 by askochen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

CC = gcc

LIBFT = libft/libft.a

SRC = operators/01_live.c operators/02_ld.c \
operators/03_st.c operators/04_add.c operators/05_sub.c \
operators/06_and.c operators/07_or.c operators/08_xor.c \
operators/09_zjmp.c operators/10_ldi.c operators/11_sti.c \
operators/12_fork.c operators/13_lld.c operators/14_lldi.c \
operators/15_lfork.c operators/16_aff.c \
process_tools.c op.c exec_of_comands.c vm_main.c core_war.c \
decoding.c initialization.c list.c type_param.c valid_opcode.c \
validation_argc.c validation_argc_2.c validation_cor.c \
var_param.c write_rez.c vis.c

OBJ = $(SRC:.c=.o)

HEADERS = libft/libft.h corewar_vm.h libft/get_next_line.h op.h

FLAGS = -Wall -lncurses

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libft/

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

clean: libft_clean 
	rm -f $(OBJ) corewar.h.gch *~

fclean: clean libft_fclean 
	rm -f $(NAME)

re: fclean all
