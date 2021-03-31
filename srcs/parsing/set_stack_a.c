/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:40 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/31 11:40:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_a(t_engine *engine, char **list)
{
	int i;

	i = 1;
	while (i < engine->len_stack_a + 1)
	{
		ft_lst_add_back(&engine->stack_a, ft_lst_create_node(list[i]));
		i++;
	}
}
