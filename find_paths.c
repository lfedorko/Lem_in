#include "lem_in.h"

void dfs(int start, int end, char *used,t_pointer *p, int j)
{
	int i;

	i = 0;
	if (start == end)
		return ;
	used[start] = '1';
	while (i < p->info->room)
	{
		if (p->info->map[start][i] == 'X' &&  used[i] == '0')
		{
			j++;
			dfs(i, end, used, p, j);
			printf("глубина = %d  резалт = %d\n", j, i);
		}
			i++;
	}
	used[start] = '0';
}

void find_paths(t_pointer *p)
{
	char *used;


	used = ft_strnew(p->info->room);
	used = memset(used, '0', p->info->room);
	dfs(0, 1, used, p, 0);//дописать массив с путями



}
