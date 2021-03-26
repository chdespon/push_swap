/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/26 14:02:25 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instruction(char *str)
{
	if (ft_strcmp(str, "pa") == 0)
		return ;
		// push_a();
	else if (ft_strcmp(str, "pb") == 0)
		return ;
		// push_b();
	else if (ft_strcmp(str, "sa") == 0)
		return ;
		// swap_a();
	else if (ft_strcmp(str, "sb") == 0)
		return ;
		// swap_b();
	else if (ft_strcmp(str, "ss") == 0)
		return ;
		// swap_s();
	else if (ft_strcmp(str, "ra") == 0)
		return ;
		// rotate_a();
	else if (ft_strcmp(str, "rb") == 0)
		return ;
		// rotate_b();
	else if (ft_strcmp(str, "rr") == 0)
		return ;
		// rotate_r();
	else if (ft_strcmp(str, "rra") == 0)
		return ;
		// reverse_a();
	else if (ft_strcmp(str, "rrb") == 0)
		return ;
		// reverse_b();
	else if (ft_strcmp(str, "rrr") == 0)
		return ;
		// reverse_r();
}

void	apply_op(t_list *op)
{
	t_list	*tmp;

	tmp = op;
	while (op != NULL)
	{
		apply_instruction(op->data);
		op = op->next;
	}
	op = tmp;
}

void	set_op(char *str, t_list **op)
{
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0 ||
			ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 ||
			ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "ra") == 0 ||
			ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0 ||
			ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0 ||
			ft_strcmp(str, "rrr") == 0)
		ft_lst_add_back(op, ft_lst_create_node(str));
	else if (ft_strcmp(str, "") == 0)
	{
		free(str);
		return ;
	}
	else
	{
		ft_lst_clear(op, free);
		quit(WRONG_OP);
	}
}

void	read_output(t_list	**op)
{
	char *line;
	int ret;

	ret = 1;
	ft_putstr("Enter an operation... \"CRTL d\" to exit\n");
	while (ret >= 1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		set_op(line, op);
		ft_putstr("Enter an operation... \"CTRL d\" to exit\n");
	}
}

int		is_sort(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp;

	tmp = stack_a;
	while (stack_a != NULL)
	{
		if (ft_atoi((char*)stack_a->data) > ft_atoi((char*)stack_a->data))
			return (0);
		stack_a = stack_a->next;
	}
	if (stack_b != NULL)
		return (0);
	return(1);
}

void	set_stack_a(t_list **stack_a, char **list)
{
	int i;
	int len;

	len = ft_tab_len((void**)list);
	i = 1;
	while (i < len)
	{
		ft_lst_add_back(stack_a, ft_lst_create_node(list[i]));
		i++;
	}
}

int		main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op;

	op = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	parse_arg(av);
	read_output(&op);
	set_stack_a(&stack_a, av);
	apply_op(op);
	if (is_sort(stack_a, stack_b))
	{
		ft_lst_clear(&stack_a, NULL);
		ft_lst_clear(&op, free);
		quit(OK);
	}
	else
	{
		ft_lst_clear(&stack_a, NULL);
		ft_lst_clear(&op, free);
		quit(KO);
	}
	return (0);
}
