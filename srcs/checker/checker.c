/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/30 16:23:47 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instruction(char *str, t_list **stack_a, t_list ** stack_b)
{
	if (ft_strcmp(str, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		swap_s(stack_a, stack_b);
	else if (ft_strcmp(str, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		rotate_r(stack_a, stack_b);
	else if (ft_strcmp(str, "rra") == 0)
		reverse(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		reverse_r(stack_a, stack_b);
}

void	apply_op(t_engine *engine)
{
	t_list	*tmp;

	tmp = engine->op;
	while (engine->op != NULL)
	{
		apply_instruction(engine->op->data, &engine->stack_a, &engine->stack_b);
		engine->op = engine->op->next;
	}
	engine->op = tmp;
}

void	set_op(char *str, t_engine *engine)
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

void	read_output(t_engine *engine)
{
	char *line;
	int ret;

	ret = 1;
	while (ret >= 1)
	{
		ft_putstr("Enter an operation... \"CTRL d\" to exit\n");
		ret = get_next_line(STDIN_FILENO, &line);
		set_op(line, engine);
	}
}

int		is_sort(t_engine *engine)
{
	t_list *tmp;

	tmp = engine->stack_a;
	while (engine->stack_a != NULL && engine->stack_a->next != NULL)
	{
		if (ft_atoi((char*)engine->stack_a->data) >
			ft_atoi((char*)engine->stack_a->next->data))
			return (0);
		engine->stack_a = engine->stack_a->next;
	}
	engine->stack_a = tmp;
	if (engine->stack_b != NULL)
		return (0);
	return(1);
}


int		main(int ac, char **av)
{
	t_engine *engine;

	if (ac == 1)
		return (0);
	engine = malloc_engine();
	if (engine == NULL)
		quit(ERROR_Malloc, engine);
	parse_arg(av, engine);
	read_output(engine);
	set_stack_a(engine, av);
	apply_op(engine);
	if (is_sort(engine))
		quit(OK, engine);
	else
		quit(KO, engine);
	return (0);
}
