/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/25 14:11:19 by chdespon         ###   ########.fr       */
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

void	check_op(char *str, t_list **op)
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

	ft_putstr("Enter an operation... \"CRTL d\" to exit\n");
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		check_op(line, op);
		ft_putstr("Enter an operation... \"CTRL d\" to exit\n");
	}
}

int		is_sort(char **stack_a, char **stack_b, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (ft_atoi(stack_a[i]) > ft_atoi(stack_a[i + 1]))
			return (0);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (ft_strcmp(stack_b[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		len;
	// t_list	stack_a;
	// t_list	stack_b;
	t_list	*op;

	op = NULL;
	if (ac == 1)
		return (0);
	len = ft_tab_len((void**)av);
	parse_arg(av, len);
	read_output(&op);
	apply_op(op);
	// if (is_sort(stack_a, stack_b, len))
	// 	quit(OK);
	// else
	// 	quit(KO);
	ft_lst_clear(&op, free);
	return (0);
}
