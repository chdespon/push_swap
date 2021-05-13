/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:16:35 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/13 14:42:38 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_hold(t_engine *engine, int limit_cunk, int *hold_first,
															int *hold_second)
{
	t_list	*tmp;
	int		i;

	tmp = engine->stack_a;
	i = 0;
	while (engine->stack_a != NULL)
	{
		if (((t_data_num*)engine->stack_a->data)->index <= limit_cunk)
		{
			*hold_first = i;
			break ;
		}
		engine->stack_a = engine->stack_a->next;
		i++;
	}
	while (engine->stack_a != NULL)
	{
		if (((t_data_num*)engine->stack_a->data)->index <= limit_cunk)
			*hold_second = i;
		engine->stack_a = engine->stack_a->next;
		i++;
	}
	engine->stack_a = tmp;
}

void	set_chunk(t_engine *engine, int len_stack_a, int limit_chunk)
{
	int	hold_first;
	int	hold_second;
	int	i;

	i = 0;
	while (i < len_stack_a && i < 20)
	{
		set_hold(engine, limit_chunk, &hold_first, &hold_second);
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
		i++;
	}
}

void	push_chunk_to_a(t_engine *engine)
{
	t_list *tmp;
	int		i;
	while (engine->len_stack_b > 0)
	{
		i = 0;
		tmp = engine->stack_b;
		while (engine->stack_b != NULL)
		{
			if (((t_data_num*)engine->stack_b->data)->index ==
				engine->len_stack_b - 1)
				break ;
			engine->stack_b = engine->stack_b->next;
			i++;
		}
		engine->stack_b = tmp;
		if (i < engine->len_stack_b / 2)
		{
			while (i > 0)
			{
				rotate(&engine->stack_b, engine->len_stack_b);
				ft_lst_add_back(&engine->op, ft_lst_create_node("rb"));
				i--;
			}
			push(&engine->stack_a, &engine->stack_b, &engine->len_stack_a,
				&engine->len_stack_b);
			ft_lst_add_back(&engine->op, ft_lst_create_node("pa"));
		}
		else
		{
			while (i != engine->len_stack_b)
			{
				reverse(&engine->stack_b, engine->len_stack_b);
				ft_lst_add_back(&engine->op, ft_lst_create_node("rrb"));
				i++;
			}
			push(&engine->stack_a, &engine->stack_b, &engine->len_stack_a,
				&engine->len_stack_b);
			ft_lst_add_back(&engine->op, ft_lst_create_node("pa"));
		}
	}
}