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
	int  *tmp_path;
	int i;
	int start[2];

	i = 0;
	tmp_path = (int *)ft_memalloc(sizeof(int) * p->info->room);
	p->info->used = ft_strnew(p->info->room);
	p->info->used  = memset(p->info->used , '0', p->info->room);
	while (i < p->info->room)
		printf("%d ", tmp_path[i++]);

	dfs(0, 0, tmp_path, p);//дописать массив с путями
	if (p->path == NULL)
		print_error("ERROR: no roads", p);
	printf("ALL ROADS:\n");
	if (p->path == NULL)
		print_error("ERROR: no connected roads", p);
	print_lists(p);
	printf("SORT little big ROADS\n");
	sort_littlebig(p);
	print_lists(p);
	printf("SORT NOT DEPENDED  ROADS\n");
	printf("used = %s\n", p->info->used );
	sort_unique(p, p->info->used );
	print_lists(p);
}
