/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:29:37 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/12 13:50:18 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_4(t_engine *engine)
{
	if (((t_data_num*)engine->stack_a->data)->index <
			((t_data_num*)engine->stack_a->next->data)->index &&
			((t_data_num*)engine->stack_a->data)->index <
			((t_data_num*)engine->stack_a->next->next->data)->index)
	{
		swap(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("sa"));
		rotate(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
	}
	else
	{
		reverse(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("rra"));
	}
}

static void	case_3(t_engine *engine)
{
	if (((t_data_num*)engine->stack_a->data)->index >
		((t_data_num*)engine->stack_a->next->data)->index &&
		((t_data_num*)engine->stack_a->data)->index >
		((t_data_num*)engine->stack_a->next->next->data)->index)
	{
		rotate(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("ra"));
	}
	else
		case_4(engine);
}

static void	case_2(t_engine *engine)
{
	if (((t_data_num*)engine->stack_a->data)->index >
			((t_data_num*)engine->stack_a->next->data)->index &&
			((t_data_num*)engine->stack_a->next->data)->index >
			((t_data_num*)engine->stack_a->next->next->data)->index)
	{
		swap(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("sa"));
		reverse(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("rra"));
	}
	else
		case_3(engine);
}

void		resolve_3(t_engine *engine)
{
	if (sort_stack_a(engine) == 1)
		return ;
	if (((t_data_num*)engine->stack_a->data)->index >
		((t_data_num*)engine->stack_a->next->data)->index &&
		((t_data_num*)engine->stack_a->data)->index <
		((t_data_num*)engine->stack_a->next->next->data)->index)
	{
		swap(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("sa"));
	}
	else
		case_2(engine);
}
