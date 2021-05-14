/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:01:48 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/14 11:15:44 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_push(t_engine *engine, int i)
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

static void	reverse_push(t_engine *engine, int i)
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

void		push_chunk_to_a(t_engine *engine)
{
	t_list	*tmp;
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
			rotate_push(engine, i);
		else
			reverse_push(engine, i);
	}
}
