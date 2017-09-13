#include "lem_in.h"

//sort
int create_used(int *road, char *used)
{
	int i;

	i = 0;
	while (road[i] != 1)
	{
		if (used[road[i]] == '0')
			i++;
		else
			return 0;
	}
	i = -1;
	while (road[++i] != 1)
		used[road[i]] = '1';
	return (1);
}
//sort
void sort_unique(t_pointer *p, char *used)
{
	t_path *list;
	t_path *tmp;
	t_path *prev; //cтарый

	prev = NULL;
	list = p->path;
	while (list)
	{
		tmp = list->next;
		if (!create_used(list->road, used))
			delete_node(p, list, prev);
		else
			prev = list;
		list = tmp;
	}
}


// sort list
void sort_littlebig(t_pointer *p)
{
	t_path *begin;
	t_path *tmp;
	int *array;
	int tmp_len;

	begin = p->path;
	tmp  = p->path->next;
	while (tmp)
	{
		while (tmp != begin)
		{
			if (tmp->len < begin->len)
			{
				tmp_len = begin->len;
				array = begin->road;
				begin->len = tmp->len;
				begin->road = tmp->road;
				tmp->road = array;
				tmp->len = tmp_len;
			}
			begin = begin->next;
		}
		begin = p->path;
		tmp = tmp->next;
	}
}

//sort
void delete_node(t_pointer *p, t_path *list, t_path *prev)
{
	if (prev == NULL)
		p->path = list->next;
	else
		prev->next = list->next;
	free(list->road);
	free(list);
}
//sort
void sort_roads(t_pointer *p)
{
	t_path *list;
	t_path *tmp;
	t_path *prev; //cтарый
	int i;

	prev = NULL;
	list = p->path;
	while (list) {
		tmp = list->next;
		i = 0;
		while (list->road[i] != 1 && i < p->info->room)
			i++;
		if (list->road[i] != 1)
			delete_node(p, list, prev);
		else
		{
			prev = list;
			list->len = i;
		}
		list = tmp;
	}
}
