/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:29:50 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/18 21:29:51 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int ft_type_param_1(t_opcode *op_lst, unsigned char *test_byte)
{
	if ((op_lst->cod_byte & 192) == 192)
	{
		*test_byte += 192;
		return (T_IND);
	}
	if ((op_lst->cod_byte & 64) == 64)
	{
		*test_byte += 64;
		return (T_REG);
	}
	else if ((op_lst->cod_byte & 128) == 128)
	{
		*test_byte += 128;
		return (T_DIR);
	}
	else
		return (0);
}

int ft_type_param_2(t_opcode *op_lst, unsigned char *test_byte)
{
	if ((op_lst->cod_byte & 48) == 48)
	{
		*test_byte += 48;
		return (T_IND);
	}
	else if ((op_lst->cod_byte & 16) == 16)
	{
		*test_byte += 16;
		return (T_REG);
	}
	else if ((op_lst->cod_byte & 32) == 32)
	{
		*test_byte += 32;
		return (T_DIR);
	}
	else
		return (0);
}

int ft_type_param_3(t_opcode *op_lst, unsigned char *test_byte)
{
	if ((op_lst->cod_byte & 12) == 12)
	{
		*test_byte += 12;
		return (T_IND);
	}
	else if ((op_lst->cod_byte & 4) == 4)
	{
		*test_byte += 4;
		return (T_REG);
	}
	else if ((op_lst->cod_byte & 8) == 8)
	{
		*test_byte += 8;
		return (T_DIR);
	}
	else
		return (0);
}

int ft_type_param(t_opcode *op_lst, int nam_arg, unsigned char *test_byte)
{
	if (nam_arg == 0)
		return (ft_type_param_1(op_lst, test_byte));
	else if (nam_arg == 1)
		return (ft_type_param_2(op_lst, test_byte));
	else if (nam_arg == 2)
		return (ft_type_param_3(op_lst, test_byte));
}