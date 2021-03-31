/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:08:24 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/31 10:08:35 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_engine *engine)
{
	t_list *tmp;

	tmp = engine->stack_a;
	while (engine->stack_a != NULL && engine->stack_a->next != NULL)
	{
		if (ft_atoi((char*)engine->stack_a->data) >
			ft_atoi((char*)engine->stack_a->next->data))
			return (0);
		engine->stack_a = engine->stack_a->next;
	}
	engine->stack_a = tmp;
	if (engine->stack_b != NULL)
		return (0);
	return(1);
}
