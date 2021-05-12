/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/12 16:05:43 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_100(t_engine *engine)
{
	t_list	*tmp;
	int		hold_first;
	int		hold_second;
	int		i;

	tmp = engine->stack_a;
	i = 0;
	while (engine->stack_a != NULL)
	{
		if (((t_data_num*)engine->stack_a->data)->index <= 19)
		{
			hold_first = i;
			break ;
		}
		engine->stack_a = engine->stack_a->next;
		i++;
	}
	while (engine->stack_a != NULL)
	{
		if (((t_data_num*)engine->stack_a->data)->index < 19)
			hold_second = i;
		engine->stack_a = engine->stack_a->next;
		i++;
	}
	engine->stack_a = tmp;
	if (engine->len_stack_a - hold_second < hold_first)
	{
		while (hold_second < engine->len_stack_a)
		{
			reverse(&engine->stack_a, engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("rra"));
			hold_second++;
		}
	}
	else
		while (hold_first > 0)
		{
			rotate(&engine->stack_a, engine->len_stack_a);
			ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
			hold_first--;
		}
	push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
		&engine->len_stack_a);
	ft_lst_add_back(&engine->op, ft_lst_create_node("pb"));
}

void	resolve_stack(t_engine *engine)
{
	if (sort_stack_a(engine) == 1)
		return ;
	else if (engine->len_stack_a == 2)
	{
		swap(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("sa"));
	}
	else if (engine->len_stack_a == 3)
		resolve_3(engine);
	else if (engine->len_stack_a <= 5)
		resolve_5(engine);
	else if (engine->len_stack_a <= 100)
		resolve_100(engine);
}
