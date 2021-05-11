/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:07:57 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/11 12:09:21 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack_a(t_engine *engine)
{
	t_list *tmp;

	tmp = engine->stack_a;
	while (engine->stack_a != NULL && engine->stack_a->next != NULL)
	{
		if (((t_data_num*)engine->stack_a->data)->value >
			((t_data_num*)engine->stack_a->next->data)->value)
		{
			engine->stack_a = tmp;
			return (0);
		}
		engine->stack_a = engine->stack_a->next;
	}
	engine->stack_a = tmp;
	return (1);
}