#include "lem_in.h"

void add_vertex(int i, int *p, int len)
{
	int j;

	j = 0;
	while (p[j] != 0 && j < len)
		j++;
	p[j] = i;
	printf("vertex\n");
	i = 0;
	while (i < len)
		printf("%d ", p[i++]);
	printf("\n");
}
// вертекс- что добавить
// массив с предыдущей дорогой


int *new_path(t_pointer *p, int vertex, int *cur_road, int cur)
{
	t_path *new;
	t_path *tmp;
	int i;

	i = 0;
	tmp = p->path;
	printf("cur road  ");
	while (i < p->info->room)
		printf("%d ", cur_road[i++]);
	printf("\n");
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
	i = 0;
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

	path = (t_path *)malloc(sizeof(t_path));
	path->road = (int *)ft_memalloc(sizeof(int) * p->info->room);
	used = ft_strnew(p->info->room);
	p->path = path;
	path->next = NULL;
	used = memset(used, '0', p->info->room);
	dfs(0, 1, used, p, path->road);//дописать массив с путями

	while (path != NULL)
	{
		i = -1;
		while (++i < p->info->room)
			printf("%d", path->road[i]);
		printf("\n");
		path = path->next;
	}

}
