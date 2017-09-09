#include <stdio.h>
#include "lem_in.h"

void print_error(char *string, t_pointer *p)
{
	int i;

	i = 0;
	write(1, string, ft_strlen(string));
	if (p->line != NULL)
		free(p->line);
	while (i < p->info->size)
		free(p->info->file[i++]);
	free(p->info);
	/* add room  free linked list */
	free(p);
	exit(0);
}


int main()
{
	// init structure
	t_info *info;
	//t_room *room;
	t_pointer *p;
	p = (t_pointer *)malloc(sizeof(t_pointer));
	info = (t_info *)malloc(sizeof(t_info));
	p->info = info;
	init_info(info, p);
	validation(info, p);
	find_paths(p);
	free(info);

	return (0);
}
