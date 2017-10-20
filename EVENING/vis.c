#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "corewar_vm.h"
#include "draw.h"

void		output_core(t_mstruc *inst, t_draw *draw)
{
	int x;
	int y;
	int k;

	k = 0;
	y = 2;
	wattron(draw->win[0], COLOR_PAIR(5)); 
	for (int j = 0; j < 64; j++)
	{ 
		x = 2;  
		for (int i = 0; i < 64; i++)
		{
			//if (k == 3023)
				//wprintw(draw->win[1],"%d %d k = %d " ,y, x, k);
			mvwprintw(draw->win[0],y, x,"%.2x", inst->memory[k]);
			k++;
			x += 3;
		}
		y++;
	}

	mvwprintw(draw->win[1], 8, 12, "%d", inst->total_cycle);    //отображает циклы в стате
	mvwprintw(draw->win[1], 10, 16, "%d", inst->total_process); //отображает процессы
		show_process(inst, draw);	
}

void show_process(t_mstruc *inst, t_draw *draw)
{
	t_process *tmp;
	int y;
	int x;
	int i = 0;

	tmp = inst->process;
	 while (tmp)
	 {
	 	y = tmp->pc / 64;
	 	x = (tmp->pc - y * 64) * 3; 
		y += 2;
		x += 2;
		mvwprintw(draw->win[1], 55 + i, 3,"[k = %d] " ,tmp->pc);
		wattron(draw->win[0], COLOR_PAIR(6)); 
		mvwprintw(draw->win[0],y, x,"%.2x", inst->memory[tmp->pc]);
		wattroff(draw->win[0], COLOR_PAIR(6)); 
		tmp = tmp->next;
		i++;
	 }
}


void show_players(t_mstruc *inst, t_draw *draw)
{
	int	h;
	int	w;
	int	i;
	t_players *tmp;

	h = 12;
	w = 5;
	i = 0;
	tmp = inst->players;
	wmove(draw->win[1], h, w);
	while (i < inst->num_of_players)
	{
		wprintw(draw->win[1],"Player -%d :",tmp->pl_num);
		wattron(draw->win[1], COLOR_PAIR(tmp->pl_num)); 
		wprintw(draw->win[1]," %s", tmp->header->prog_name);
		wattroff(draw->win[1], COLOR_PAIR(tmp->pl_num)); 
		wmove(draw->win[1], ++h, w);
		wprintw(draw->win[1],"	Last live :			%d",tmp->last_live);
		wmove(draw->win[1], ++h, w);
		wprintw(draw->win[1],"	Lives in current period : 	%d",tmp->live_flag);
		h += 2;
		wmove(draw->win[1], h, w);
		tmp	= tmp->next;
		i++;
	}
}

void create_labels(t_draw *draw) 
{
	int  h;
	int  w;

	getyx(draw->win[1], h, w);
	h += 5;
	w += 5;
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	wattron(draw->win[1], COLOR_PAIR(5)); 
	wmove(draw->win[1], h, w);
	wprintw(draw->win[1],"Cycles/second limit:");
	wmove(draw->win[1], h + 3, w);
	wprintw(draw->win[1],"CYCLE: 0");
	wmove(draw->win[1], h + 5, w);
	wprintw(draw->win[1],"Processes: 0");
}

void	ft_destr_wins(t_draw *draw)
{
	delwin(draw->win[0]);
	delwin(draw->win[1]);
	endwin();
}

void	init_colors()
{ 
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_WHITE);
}

void	init_wind(t_draw *draw)
{
	initscr();
	start_color();
	init_colors();
	draw->win[0] = newwin(68, 195, 0, 0);   //главное окно с памятью
	draw->win[1] = newwin(68, 70, 0, 195); //окно с статой
	// draw->win[2] = newwin(12,64, 196, 55); // liza 
	wattron(draw->win[0], COLOR_PAIR(6)); 
	wborder(draw->win[0], ' ', ' ',' ' ,' ', ' ',' ',' ',' ');
	wattron(draw->win[1], COLOR_PAIR(6)); 
	wborder(draw->win[1], ' ', ' ',' ' ,' ', ' ',' ',' ',' ');
	//box(draw->win[2], 0, 0);
	create_labels(draw);
}
