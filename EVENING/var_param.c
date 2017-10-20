/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:35:15 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/18 21:35:17 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int ft_first_param(t_opcode *op_lst, int num)
{
	if (((num & 192) == 192))
		return (2);
	else if ((num & 64) == 64)
		return (1);
	else if ((num & 128) == 128)
		return (help.label_size[op_lst->operation - 1]);
}

int ft_second_param(t_opcode *op_lst, int num)
{
	if (((num & 48) == 48))
		return (2);
	if ((num & 16) == 16)
		return (1);
	else if ((num & 32) == 32)
		return (help.label_size[op_lst->operation - 1]);
}

int ft_third_param(t_opcode *op_lst, int num)
{
	if (((num & 12) == 12))
		return (2);
	if ((num & 4) == 4)
		return (1);
	else if ((num & 8) == 8)
		return (help.label_size[op_lst->operation - 1]);
}

int	ft_var_param(t_opcode *op_lst, int nam_arg)
{
	int rez;

	if (nam_arg == 0)
		rez = ft_first_param(op_lst, op_lst->cod_byte);
	if (nam_arg == 1)
		rez = ft_second_param(op_lst, op_lst->cod_byte);
	if (nam_arg == 2)
		rez = ft_third_param(op_lst, op_lst->cod_byte);
	return (rez);
}