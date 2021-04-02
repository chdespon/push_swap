/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/02 14:46:08 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_stack(t_engine *engine)
{
	t_list *tmp;

	tmp = engine->stack_a;
	while (engine->stack_a != NULL)
	{
		if (((t_data_num*)engine->stack_a->data)->index <
		((t_data_num*)engine->stack_a->next->data)->index)
			((t_data_num*)engine->stack_a->data)->keep = true;
	}
}
