#include "lem_in.h"

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

//dfs
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
