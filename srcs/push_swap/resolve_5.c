/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:33:03 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/12 12:49:05 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_first_two(t_engine *engine)
{
	while (engine->len_stack_a > 3)
	{
		if (((t_data_num*)engine->stack_a->data)->index < 2)
		{
			push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
			&engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("pb"));
		}
		else
		{
			rotate(&engine->stack_a, engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
		}
	}
}

static void	push_first(t_engine *engine)
{
	while (engine->len_stack_a > 3)
	{
		if (((t_data_num*)engine->stack_a->data)->index < 1)
		{
			push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
			&engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("pb"));
		}
		else
		{
			rotate(&engine->stack_a, engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
		}
	}
}

void		resolve_5(t_engine *engine)
{
	if (engine->len_stack_a == 5)
		push_first_two(engine);
	else
		push_first(engine);
	resolve_3(engine);
	if (engine->stack_b->next != NULL &&
		((t_data_num*)engine->stack_b->data)->index <
		((t_data_num*)engine->stack_b->next->data)->index)
	{
		rotate(&engine->stack_b, engine->len_stack_b);
		ft_lst_add_back(&engine->op, ft_lst_create_node("rb"));
	}
	while (engine->len_stack_b > 0)
	{
		push(&engine->stack_a, &engine->stack_b, &engine->len_stack_a,
		&engine->len_stack_b);
		ft_lst_add_back(&engine->op, ft_lst_create_node("pa"));
	}
}
