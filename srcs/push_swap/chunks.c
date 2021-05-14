/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:16:35 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/14 11:21:37 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_hold(t_engine *engine, int limit_cunk, int *hold_first,
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

static void	reverse_chunk(t_engine *engine, int hold_second)
{
	while (hold_second < engine->len_stack_a)
	{
		reverse(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("rra"));
		hold_second++;
	}
}

static void	rotate_chunk(t_engine *engine, int hold_first)
{
	while (hold_first > 0)
	{
		rotate(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
		hold_first--;
	}
}

void		set_chunk(t_engine *engine, int len_stack_a, int limit_chunk,
																int chunk_size)
{
	int	hold_first;
	int	hold_second;
	int	i;

	i = 0;
	while (i < len_stack_a && i < chunk_size)
	{
		set_hold(engine, limit_chunk, &hold_first, &hold_second);
		if (engine->len_stack_a - hold_second < hold_first)
			reverse_chunk(engine, hold_second);
		else
			rotate_chunk(engine, hold_first);
		push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
			&engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("pb"));
		i++;
	}
}
