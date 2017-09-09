#include "lem_in.h"

void sort_unique(t_pointer *p, char *used);

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


void delete_node(t_pointer *p, t_path *list, t_path *prev)
{
		if (prev == NULL)
			p->path = list->next;
		else
			prev->next = list->next;
		free(list->road);
		free(list);
}

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

void add_vertex(int i, int *p, int len)
{
	int j;

	j = 0;
	while (p[j] != 0 && j < len)
		j++;
	p[j] = i;
}

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
	int k;

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
	if (path->road[0] == 0)
		print_error("ERROR: no roads", p);
	printf("ALL ROADS:\n");
	print_lists(p);
	printf("SORT ROADS\n");
	sort_roads(p);
	if (p->path == NULL)
		print_error("ERROR: no connected roads", p);
	print_lists(p);
	printf("SORT little big ROADS\n");
	sort_littlebig(p);
	print_lists(p);
	printf("SORT NOT DEPENDED  ROADS\n");
	printf("used = %s\n", used);
	sort_unique(p, used);
	print_lists(p);
}


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
