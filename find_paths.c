#include "lem_in.h"

void sort_roads(t_pointer *p)
{
	t_path *list;
	t_path *tmp;
	t_path *prev; //cтарый
	int i;

	prev = NULL;
	list = p->path;
	while (list)
	{
		tmp = list->next;
		i = 0;
		while (list->road[i] != 1 && i < p->info->room)
			i++;
		if (list->road[i] != 1)
		{
			if (prev == NULL)
				p->path = tmp;
		  	else
				prev->next = tmp;
			free(list->road);
			free(list);
		}
		else
		{
			prev = list;
			list->len = i;
		}
			list = tmp;
	}
}

void add_vertex(int i, int *p, int len)
{
	int j;

	j = 0;
	while (p[j] != 0 && j < len)
		j++;
	p[j] = i;
}
// вертекс- что добавить
// массив с предыдущей дорогой


int *new_path(t_pointer *p, int vertex, int *cur_road, int cur)
{
	t_path *new;
	t_path *tmp;
	int i;

	tmp = p->path;
	i = 0;
	new = (t_path *)malloc(sizeof(t_path));
	new->road = (int *)ft_memalloc(sizeof(int) * p->info->room);
	new->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;  // новый узел с дорогой
	if (cur == 0)
	{
		new->road[0] = vertex;
		return (new->road);
	}
	while (cur_road[i] != cur && i < p->info->room) //problem
	{
		new->road[i] = cur_road[i];
		i++;
	}
	new->road[i] = cur_road[i];
	new->road[i + 1] = vertex;
	return(new->road);
}


void dfs(int start, int end, char *used, t_pointer *p, int *j)
{
	int i;
	int path;

	path = 0;
	if (start == end)
		return ;
	used[start] = '1';
	i = 0;
	while (i < p->info->room)
	{
			if (p->info->map[start][i] == 'X'  &&  used[i] == '0')
			{
				if (path == 0)
					add_vertex(i, j, p->info->room);
				else
					j = new_path(p, i,  j, start);
				dfs(i, end, used, p, j);
				path++;
			}
			i++;
	}
	used[start] = '0';
}
//used malloc -free !!!
void find_paths(t_pointer *p)
{
	char *used;
	t_path *path;
	int i = 0;
	t_path *tmp;

	path = (t_path *)malloc(sizeof(t_path));
	path->road = (int *)ft_memalloc(sizeof(int) * p->info->room);
	used = ft_strnew(p->info->room);
	p->path = path;
	path->next = NULL;
	used = memset(used, '0', p->info->room);
	dfs(0, 1, used, p, path->road);//дописать массив с путями

	printf("ALL ROADS:\n");
	tmp = path;
	while (tmp != NULL)
	{
		i = -1;
		while (++i < p->info->room && tmp->road[i] != 0)
			printf("%d", tmp->road[i]);
		printf("   len = %d  cur = %p next = %p\n", tmp->len, &tmp, &tmp->next);
		tmp = tmp->next;
	}
	printf("SORT ROADS\n");
	sort_roads(p);
	tmp = p->path;
	while (tmp != NULL)
	{
		i = -1;
		while (++i < p->info->room && tmp->road[i] != 0)
			printf("%d", tmp->road[i]);
		printf("   len = %d  cur = %p next = %p\n", tmp->len, &tmp, &tmp->next);
		tmp = tmp->next;
	}
}
