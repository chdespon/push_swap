/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:04:06 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/01 11:48:53 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_instruction_2(t_engine *engine)
{
	if (ft_strcmp(engine->op->data, "ra") == 0)
		rotate(&engine->stack_a, engine->len_stack_a);
	else if (ft_strcmp(engine->op->data, "rb") == 0)
		rotate(&engine->stack_b, engine->len_stack_b);
	else if (ft_strcmp(engine->op->data, "rr") == 0)
		rotate_r(&engine->stack_a, &engine->stack_b, engine->len_stack_a,
			engine->len_stack_b);
	else if (ft_strcmp(engine->op->data, "rra") == 0)
		reverse(&engine->stack_a, engine->len_stack_a);
	else if (ft_strcmp(engine->op->data, "rrb") == 0)
		reverse(&engine->stack_b, engine->len_stack_b);
	else if (ft_strcmp(engine->op->data, "rrr") == 0)
		reverse_r(&engine->stack_a, &engine->stack_b, engine->len_stack_a,
			engine->len_stack_b);
}

void		apply_instruction(t_engine *engine)
{
	if (ft_strcmp(engine->op->data, "pa") == 0)
		push(&engine->stack_a, &engine->stack_b, &engine->len_stack_a,
				&engine->len_stack_b);
	else if (ft_strcmp(engine->op->data, "pb") == 0)
		push(&engine->stack_b, &engine->stack_a, &engine->len_stack_b,
				&engine->len_stack_a);
	else if (ft_strcmp(engine->op->data, "sa") == 0)
		swap(&engine->stack_a, engine->len_stack_a);
	else if (ft_strcmp(engine->op->data, "sb") == 0)
		swap(&engine->stack_b, engine->len_stack_b);
	else if (ft_strcmp(engine->op->data, "ss") == 0)
		swap_s(&engine->stack_a, &engine->stack_b, engine->len_stack_a,
			engine->len_stack_b);
	apply_instruction_2(engine);
}

void		apply_op(t_engine *engine)
{
	t_list	*tmp;

	tmp = engine->op;
	ft_putstr("> init\n");
	print_stacks(engine);
	while (engine->op != NULL)
	{
		if (engine->op != NULL)
		{
			ft_putstr("> ");
			ft_putstr(engine->op->data);
			ft_putstr("\n");
		}
		apply_instruction(engine);
		print_stacks(engine);
		engine->op = engine->op->next;
	}
	engine->op = tmp;
}

void		set_op(char *str, t_engine *engine)
{
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0 ||
			ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 ||
			ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "ra") == 0 ||
			ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0 ||
			ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0 ||
			ft_strcmp(str, "rrr") == 0)
		ft_lst_add_back(&engine->op, ft_lst_create_node(str));
	else if (ft_strcmp(str, "") == 0)
	{
		free(str);
		return ;
	}
	else
	{
		ft_lst_clear(&engine->op, free);
		quit(WRONG_OP, engine);
	}
}
