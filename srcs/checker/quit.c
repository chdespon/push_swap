/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:54:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/30 16:10:38 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(int i, t_engine *engine)
{
	if (i == ERROR_Malloc)
	{
		ft_putstr(_RED"Error\n"_WHITE);
		exit(0);
	}
	else if (i == NOT_DIGIT)
		ft_putstr(_RED"Error\nSome arguments are not integers\n"_WHITE);
	else if (i == BIGGER_THAN_INT)
		ft_putstr(_RED"Error\nSome arguments are bigger than an integer\n"
			_WHITE);
	else if (i == DUPLICATE)
		ft_putstr(_RED"Error\nThere are duplicates\n"_WHITE);
	else if (i == OK)
	{
		ft_lst_clear(&engine->stack_a, NULL);
		ft_lst_clear(&engine->op, free);
		ft_putstr(_GREEN"OK\n"_WHITE);
	}
	else if (i == KO)
	{
		ft_lst_clear(&engine->stack_a, NULL);
		ft_lst_clear(&engine->op, free);
		ft_putstr(_RED"KO\n"_WHITE);
	}
	else if (i == WRONG_OP)
		ft_putstr(_RED"Error\nWrong operation\n"_WHITE);
	exit(0);
}
