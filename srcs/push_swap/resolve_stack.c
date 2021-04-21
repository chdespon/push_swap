/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/21 16:08:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_best_start(t_list *stack_a, t_list *keep, int count_keep)
{
	while (stack_a != NULL)
	{
		if (((t_data_num*)keep->data)->index ==
			((t_data_num*)stack_a->data)->index - 1)
		{
			((t_data_num*)stack_a->data)->keep = true;
			keep = stack_a;
			count_keep++;
		}
		stack_a = stack_a->next;
	}
}

void	resolve_stack(t_engine *engine)
{
	t_list	*tmp;
	int		pivot_value;
	int		count_keep;
	t_list	*keep;

	tmp = engine->stack_a;
	pivot_value = engine->len_stack_a / 2;
	count_keep = 1;
	((t_data_num*)engine->stack_a->data)->keep = true;
	keep = engine->stack_a;
	engine->stack_a = engine->stack_a->next;
	while (engine->stack_a != NULL)
	{
		if (((t_data_num*)keep->data)->index ==
			((t_data_num*)engine->stack_a->data)->index - 1)
		{
			((t_data_num*)engine->stack_a->data)->keep = true;
			keep = engine->stack_a;
			count_keep++;
		}
		engine->stack_a = engine->stack_a->next;
	}
	engine->stack_a = tmp;
	count_keep = engine->len_stack_a - count_keep;
	while (count_keep > 0)
	{
		if ((((t_data_num*)engine->stack_a->data)->keep) == false)
		{
			push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
			&engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("pb"));
			count_keep--;
		}
		else
		{
			rotate(&engine->stack_a, engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
		}
	}
}
