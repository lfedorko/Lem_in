//
// Created by Lizavieta Fedorko on 8/10/17.
//


#include "lem_in.h"


void one_move(t_pointer *p)
{
	int i;

	i = 1;
	while(i <= p->info->ants)
		printf("\033[;33mL%d-%s\033[33;0m ",i++, p->info->conn[1]->name);

}
void init_info(t_info *info, t_pointer *p)
{
	info->ants = 0;
	info->s_e[0] = 0;
	info->s_e[1] = 0;
	info->size = 0;
	info->room = 0;
	info->file = NULL;
	info->file = NULL;
	p->info = info;
	p->room = NULL;
	p->line = NULL;
	p->path = NULL;
	p->info->p_p[0] = 0;
	p->info->p_p[1] = 0;
}