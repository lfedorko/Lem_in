#include "lem_in.h"

void connect_room(t_pointer *p);

void create_ant_positon(t_pointer *p);

void print_lists(t_pointer *p)
{
	t_path *tmp;
	int i;

	tmp = p->path;
	while (tmp != NULL)
	{
		i = -1;
		while (++i < p->info->room && tmp->road[i] != 0)
			printf("%d ", tmp->road[i]);
		printf("\n");
		tmp = tmp->next;
	}
}

void connect_room(t_pointer *p)
{
	int i;
	t_room *tmp;

	i = 0;
	tmp = p->room;
	p->info->conn = (t_room **)malloc(sizeof(t_room *) * p->info->room + 1);
	p->info->conn[p->info->room] = NULL;
	while (tmp && i < p->info->room)
	{
		p->info->conn[i] = tmp;
		i++;
		tmp = tmp->next;
	}
}
void create_ant_positon(t_pointer *p)
{
	t_path *tmp;

	tmp = p->path;
	while (tmp)
	{
		tmp->position = (int *)ft_memalloc(sizeof(int) * tmp->len);
		if (p->info->p_p[1] < tmp->len)
			p->info->p_p[1] = tmp->len;
		p->info->p_p[0]++;
		tmp = tmp->next;
	}
	printf("proper ways = %d longest way %d\n",p->info->p_p[0], p->info->p_p[1]);
}

//dfs
void find_paths(t_pointer *p)
{
	int  *tmp_path;
	int i;

	i = 0;
	tmp_path = (int *)ft_memalloc(sizeof(int) * p->info->room);
	p->info->used = ft_strnew(p->info->room);
	p->info->used  = memset(p->info->used , '0', p->info->room);
	while (i < p->info->room)
		printf("%d ", tmp_path[i++]);

	dfs(0, 0, tmp_path, p);//дописать массив с путями
	if (p->path == NULL)
		print_error("ERROR: no roads", p);
//------------------------------------------------
	printf("\nALL ROADS:\n");
	print_lists(p);
	printf("SORT little big ROADS\n");
	sort_littlebig(p);
	print_lists(p);
	printf("SORT NOT DEPENDED  ROADS\n");
	printf("used = %s\n", p->info->used );
	sort_unique(p, p->info->used);
	print_lists(p);
//-------------------------------------------------
	connect_room(p);
	create_ant_positon(p);
}