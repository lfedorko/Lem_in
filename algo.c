#include "lem_in.h"


int push_ants(t_pointer *p);

void output_s_e(t_pointer *p, int flag);

void output_middle(t_pointer *p);

void print_array(int *a, int len)
{

	int i;

	i = 0;
	printf("\n");
	while ( i < len)
		printf ("%d ", a[i++]);
	printf("\n");
}

/*check the property road */
int road_check(t_pointer *p, char *roads, int ant)
{
	int i;
	t_path *tmp;

	i = 1;
	p->path->position[0] = ++ant;
	printf("\033[;33mL%d-%s\033[33;0m ", ant, p->info->conn[p->path->road[0]]->name);
	tmp = p->path->next;
	while (i < p->info->p_p[0] && p->info->ants > ant)
	{
		if (roads[i] != 'X' &&  (tmp->len - p->path->len) < p->info->ants - ant)
		{
			ant++;
			tmp->position[0] = ant;
			//output ant
			printf("\033[;33mL%d-%s\033[33;0m ", ant, p->info->conn[tmp->road[0]]->name);
		}
		else
		{
			roads[i] = 'X';
			break;
		}
			tmp = tmp->next;
		i++;
	}
	return (ant);
}

int push_ants(t_pointer *p)
{
	t_path *tmp;
	int i;
	int flag;

	tmp = p->path;
	flag = 0;
	while (tmp)
	{
		i = tmp->len - 1;
		while (i > 0)
		{
			tmp->position[i] = tmp->position[i - 1];
			i--;
		}
		tmp->position[0] = 0;
		i = tmp->len - 1;
		if (tmp->position[i] != 0)
		{
			printf("\033[;36mL%d-%s\033[33;0m  ", tmp->position[i], p->info->conn[tmp->road[i]]->name);
			flag++;
		}
		tmp = tmp->next;
	}
	output_middle(p);
	return (flag);
}

void output_middle(t_pointer *p)
{

	t_path *tmp;
	int i;

	i = 1;
	while (i < p->info->p_p[1])
	{
		tmp = p->path;
		while (tmp)
		{
			if (tmp->len > i)
			{
				if (tmp->position[tmp->len - i - 1] != 0)
					printf ("L%d-%s ", tmp->position[tmp->len - i - 1], p->info->conn[tmp->road[tmp->len - i - 1]]->name);// p->info->conn[tmp->road[tmp->len - i - 1]]);
			}
			tmp = tmp->next;
		}
		i++;
	}

}

void 	move(t_pointer *p)
{
	int  exit_ants;
	char *roads;
	int cur_ants;
	t_path *tmp;

	exit_ants = 0;
	cur_ants = 0;
	roads = ft_strnew(p->info->p_p[0]);
	roads = ft_memset(roads, '0', p->info->p_p[0]);
	cur_ants = road_check(p, roads, cur_ants);
	printf("\n");
	while (exit_ants < p->info->ants)
	{
		exit_ants += push_ants(p);
		//выбираем возможную дорогу road check for other ant for current iteration
		if (p->info->ants - cur_ants > 0)
			cur_ants = road_check(p, roads, cur_ants);
		printf("\n");
	}
	free(roads);
}










































//void 	move(t_pointer *p)
//{
//
//	int  i;
//	char *roads;
//	t_path *tmp;
//
//	i = 0;
//	iterate_paths(p);
//	roads = ft_strnew(p->info->p_p[0]);
//	roads = ft_memset(roads, '0', p->info->p_p[0]);
//	while (i < p->info->ants)
//	{
//
//		//push first ant
//		p->path->position[0] = ++i;
//		//выбираем возможную дорогу road check for other ant for current iteration
//		if (p->path->next != NULL  && p->info->ants - i > 1)
//			i = road_check(p, roads, i);
//
//		//выводим результат
//		output(p);
//		//толкаем предыдущих
//		push_ants(p);
//		//printf("\n");
//	}
//}

















//void output(t_pointer *p)
//{
//	static int exists_ant;
//	t_path *tmp;
//	int i;
//	int *len_i;
//
//	i = 0;
//	while (i < p->info->p_p[1])
//	{
//		tmp = p->path;
//		while (tmp)
//		{
//			if (tmp->len > i)
//			{
//				if (tmp->position[tmp->len - i - 1] != 0)
//					printf ("L%d-%s ", tmp->position[tmp->len - i - 1], p->info->conn[tmp->road[tmp->len - i - 1]]->name);// p->info->conn[tmp->road[tmp->len - i - 1]]);
//			}
//			tmp = tmp->next;
//		}
//		i++;
//	}
//	printf("\n");
//}