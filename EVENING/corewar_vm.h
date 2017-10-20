/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:34:06 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/07 18:34:08 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_COREWAR_VM_H
# define COREWAR_VM_COREWAR_VM_H
# include "libft/libft.h"
# include "op.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "draw.h"
# define DUMP	"-dump"
# define NUM	"-n"
# define MANY_CHAMP "Too many champions"
# define NOT_CHAMP	"Not enough champions"
# define USAGE		"Usage"
# define NUM_WRONG "incorrect use of the flag"
# define BONUS	"-v"
# define EXTENSION "Invalid file extension"
# define SMALL	" is too small to be a champion"
# define HEADER " has an invalid header"
# define DIFF_SIZE " has a code size that differ from what its header says"
# define LARGE_CODE " has too large a code"
# define CANT_READ "Can't read source file"
# define BAD_NUM_OF_PL "Bad number of player"
# define MULTIPLE_USE "Multiple use argument"

typedef struct s_opcode
{
	unsigned int	row_size;
	int				operation;
	int				cod_byte;
	int				num_param;
	int				param[3];
	int				param_size[3];
	int 			type_param[3];
}				t_opcode;

typedef struct	s_process
{
	int					validation_flag;
	int 				operation;
	int 				op_cycle;
	int					reg[REG_NUMBER];
	int					pc;//каретка процесу
	int					carry;
	int					live_flag;
	t_opcode			*opcode;
	struct s_process	*prev;
	struct s_process	*next;
}				t_process;

typedef struct	s_players
{
	header_t			*header;//збережено імя гравця і комент
	unsigned char 		*opcode;
	int					pl_num;// номер гравця
	int					live_flag;
	long int			last_live;// необхідно для візуалізаціі
	struct s_players	*next;
}				t_players;

typedef struct	s_mstruc
{
	int				bonus_flag;//якщо не 0 запускаємо dspefkspfws.
	long int		dump_flag;
	unsigned char	memory[MEM_SIZE];//память
	int				num_of_players; //кількість гравців
	int 			player_num[MAX_PLAYERS];
	t_players		*players;
	t_players		mas_player[MAX_PLAYERS]; //масив гравців заповнений по (номер гравця - 1)
	t_process		*process;
	int				winner;// mas_player[winner].header->prog_name  mas_player[winner].header->comment mas_player[winner].pl_num необхідні для виводу інформації про переможця
	unsigned int	total_process; // загальна кількість процесів необхідна для візуалізації
	unsigned int	cycle_to_die;// виводитться в візуалізаціїї
	long int		total_cycle;// номер ітерації циклу (для візуалізації)
	unsigned int	live_current_per;
	unsigned int	live_last_per;
}				t_mstruc;

typedef struct		s_op
{
	char			*comand_name;
	int				num_arguments;
	char			arguments_types[3];
	int				opcode;
	int				cycles;
	char			*description;
	char			arguments_byte;
	char			index_size;
}					t_op;

typedef struct                 s_helper
{
	int                     comands[16];
	int                     label_size[16];
	int 					coding_byte[16];
	int 					var_arg[16][3];
	int 					arg_size[16][3];
}                            t_helper;

typedef void (*op_type)(t_mstruc *ms, t_process *pr, t_opcode *arg);
op_type *operator;

t_helper help;
t_op    op_tab[17];
//typedef void (*op_type)(t_mstruc *ms, t_process *pr, t_opcode *arg);
//op_type *operator;

void	ft_dell_mas(char **mas);
void	*ft_lst_end(void *lst, int flag);
int 	ft_lst_len(void *lst, int flag, int len);

/*
** initialization.c
*/
t_opcode	*ft_init_opcode(void);
t_process *ft_init_process(void);
header_t	*ft_init_header(void);
t_mstruc *ft_init_mstruct(void);
t_players *ft_init_players(void);

int ft_uint(int ind, char *str);
short ft_ushort(int ind, char *str);

void	ft_error_vm(char *error_mes, t_mstruc *inst, char **params, int i);
char	*ft_realloc(char *ptr, int size, char *buf);

/*
** validation_cor.c
*/
char *ft_validation_cor(int fd, t_players *player);
char *ft_prog_name(int fd, char *prog_name);
char *ft_prog_comment(int fd, char *comment);
unsigned char *ft_read_op(int fd, int size);

/*
** validation_argc.c
*/
void	ft_validation_arg(char **params, t_mstruc *inst, int i);
char	*ft_create_new_player(int i, char **params, t_mstruc *inst);
int 	ft_file_extension(char *str);
char	*ft_num_player(int *ind, char **params, t_mstruc *inst, int i);
char	*ft_dump_num(int *ind, char **params, t_mstruc *inst);

/*
** validation_argc_2.c
*/
char	*ft_move_to_mas(t_mstruc *inst);
void	ft_copy_player(t_players *des, t_players *src);
int 	ft_check_repeat_num(t_mstruc *inst);
void	ft_give_num(t_players *ptr, int i, int j, t_mstruc *inst);
int 	ft_give_num_help(t_mstruc *inst);
/*
** core_war.c
*/
void	ft_core_war(t_mstruc *inst, int live_flag);
void	ft_create_process(t_mstruc *inst);
void	ft_check_flags(t_mstruc *inst);
void	ft_choose_one(t_mstruc *inst);

/*
** valid_opcode.c
*/
int ft_opcode(int pc, t_mstruc *inst, t_process *process);
int ft_validate_coding_byte(t_process *process);
void ft_fill_param_size(t_opcode *op_lst);
int	ft_fill_param(t_opcode *op_lst, t_mstruc *inst, int *ind, t_process *pr);

/*
** type_param.c
*/
int ft_type_param(t_opcode *op_lst, int nam_arg, unsigned char *test_byte);
int ft_type_param_3(t_opcode *op_lst, unsigned char *test_byte);
int ft_type_param_2(t_opcode *op_lst, unsigned char *test_byte);
int ft_type_param_1(t_opcode *op_lst, unsigned char *test_byte);

/*
** var_param.c
*/
int	ft_var_param(t_opcode *op_lst, int nam_arg);
int ft_third_param(t_opcode *op_lst, int num);
int ft_second_param(t_opcode *op_lst, int num);
int ft_first_param(t_opcode *op_lst, int num);

/*
** write_rez.c
*/
void	ft_write_contestants(t_mstruc *inst, int i);

/*
** askochen
*/
int			get_pc(int pc);
t_process	*copy_process(t_process *rhs);
void 		new_process(t_process *rpr, t_mstruc *ms, int pc);
void 		delete_process(t_process *pr, t_mstruc *ms);
void		value_to_memory(t_mstruc *ms, int pos, int val);

void 		live_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		ld_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		st_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		add_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		sub_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		and_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		or_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		xor_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		zjmp_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		ldi_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		sti_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		fork_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		lld_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		lldi_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		lfork_com(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		aff_com(t_mstruc *ms, t_process *pr, t_opcode *arg);

//void 		init_operators();
void 		ft_comands(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		ft_execution_of_comands(t_mstruc *ms, t_process *pr, t_opcode *arg);
void 		ft_execution_of_comands1(t_mstruc *ms, t_process *pr, t_opcode *arg);


void		show_players(t_mstruc *inst, t_draw *draw);
void		output_core(t_mstruc *inst, t_draw *draw);
void 		show_process(t_mstruc *inst, t_draw *draw);
#endif //COREWAR_VM_COREWAR_VM_H
