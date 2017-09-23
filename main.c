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
//	free(p->info->used);
	/* add room  and path free linked list */
	free(p);
	exit(0);
}

int main()
{
	t_info *info;
	t_pointer *p;
	t_room	*rooms;

	p = (t_pointer *)malloc(sizeof(t_pointer));
	info = (t_info *)malloc(sizeof(t_info));
	init_info(info, p);
	number_of_ants(info, p, 0);
	handle_rooms(rooms, info, p);
	find_paths(p);
	p->path->len == 1 ? one_move(p) : move(p);
	free(info);

	return (0);
}
