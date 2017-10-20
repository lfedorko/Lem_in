#ifndef DRAW_H
#include "corewar_vm.h"
#include <ncurses.h>
#define DRAW_H


typedef struct	s_draw
{
	char **heart;
	char **cross;
	WINDOW *win[3];
}				t_draw;

void	init_wind(t_draw *draw);
void	ft_destr_wins(t_draw *draw);
#endif