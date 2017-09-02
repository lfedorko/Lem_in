//
// Created by Lizavieta Fedorko on 8/10/17.
//


#include "lem_in.h"

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

}