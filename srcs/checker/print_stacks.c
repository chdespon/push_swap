/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:40:04 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/01 15:23:44 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack_b(t_engine *engine)
{
	int spaces;

	if (engine->stack_b != NULL)
	{
		spaces = 13 - ft_nbrlen(((t_data_num*)engine->stack_a->data)->value);
		while (spaces > 0)
		{
			ft_putchar(' ');
			spaces--;
		}
		ft_putnbr(((t_data_num*)engine->stack_b->data)->value);
		engine->stack_b = engine->stack_b->next;
	}
	else
		ft_putstr("             ");
}

static void	print_stack_a(t_engine *engine)
{
	int spaces;

	if (engine->stack_a != NULL)
	{
		spaces = 13 - ft_nbrlen(((t_data_num*)engine->stack_a->data)->value);
		while (spaces > 0)
		{
			ft_putchar(' ');
			spaces--;
		}
		ft_putnbr(((t_data_num*)engine->stack_a->data)->value);
		engine->stack_a = engine->stack_a->next;
	}
	else
		ft_putstr("             ");
}

void		print_stacks(t_engine *engine)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		i;

	tmp_a = engine->stack_a;
	tmp_b = engine->stack_b;
	i = 0;
	ft_putstr("+------A------+------B------+\n");
	while (i < engine->len_stack_a || i < engine->len_stack_b)
	{
		ft_putchar('|');
		print_stack_a(engine);
		ft_putchar('|');
		print_stack_b(engine);
		ft_putchar('|');
		ft_putchar('\n');
		i++;
	}
	ft_putstr("+-------------+-------------+\n");
	engine->stack_a = tmp_a;
	engine->stack_b = tmp_b;
}
