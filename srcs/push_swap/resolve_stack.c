/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/11 14:41:58 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_stack(t_engine *engine)
{
	t_list	*tmp;
	int		pivot_value;
	int		count_keep;
	t_list	*keep;


	tmp = engine->stack_a;
	pivot_value = engine->len_stack_a / 2;

	if (sort_stack_a(engine) == 1)
		return ;
	if (engine->len_stack_a == 2)
	{
		swap(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("sa"));
		return ;
	}
	if (engine->len_stack_a == 3)
	{
		resolve_3(engine);
		return ;
	}
	if (engine->len_stack_a <= 5)
	{
		resolve_5(engine);
		return ;
	}
	while (engine->stack_a != NULL)
	{
		((t_data_num*)engine->stack_a->data)->keep = true;
		engine->stack_a = engine->stack_a->next;
		keep = engine->stack_a;
		count_keep = 1;
		if (((t_data_num*)keep->data)->index <
			((t_data_num*)engine->stack_a->data)->index)
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
