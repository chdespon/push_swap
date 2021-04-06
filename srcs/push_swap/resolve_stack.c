/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/06 16:46:48 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_num(t_engine *engine)
{
	t_list *tmp_a;

	tmp_a = engine->stack_b;
	while (engine->stack_b != NULL)
	{
		
	}
}

void	resolve_stack(t_engine *engine)
{
	t_list *tmp;
	int index;

	tmp = engine->stack_a;
	while (engine->stack_a != NULL)
	{
		push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
			&engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("pb"));
	}
	index = engine->len_stack_b - 1;
	while (engine->stack_b != NULL)
	{
		find_best_num(engine);
		if (index != ((t_data_num*)engine->stack_b->data)->index)
		{
			rotate(&engine->stack_b, engine->len_stack_b);
			ft_lst_add_back(&engine->op, ft_lst_create_node("rb"));
		}
		else
		{
			push(&engine->stack_a, &engine->stack_b, &engine->len_stack_a,
				&engine->len_stack_b);
			ft_lst_add_back(&engine->op, ft_lst_create_node("pa"));
			index--;
		}
	}
}
