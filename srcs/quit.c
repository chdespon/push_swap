/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:54:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/17 11:34:25 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(int i, t_engine *engine)
{
	if (i == ERROR)
		ft_putstr_fd(2, _RED"Error\n"_WHITE);
	else if (i == OK)
	{
		ft_lst_clear(&engine->stack_a, free);
		ft_lst_clear(&engine->op, free);
		ft_putstr(_GREEN"OK\n"_WHITE);
	}
	else if (i == KO)
	{
		ft_lst_clear(&engine->stack_a, free);
		ft_lst_clear(&engine->op, free);
		ft_putstr(_RED"KO\n"_WHITE);
	}
	free(engine);
	exit(0);
}
