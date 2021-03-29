/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/29 15:08:18 by chdespon         ###   ########.fr       */
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

void	apply_op(t_list *op, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = op;
	while (op != NULL)
	{
		apply_instruction(op->data, stack_a, stack_b);
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
	while (ret >= 1)
	{
		ft_putstr("Enter an operation... \"CTRL d\" to exit\n");
		ret = get_next_line(STDIN_FILENO, &line);
		set_op(line, op);
	}
}

int		is_sort(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp;

	tmp = stack_a;
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (ft_atoi((char*)stack_a->data) > ft_atoi((char*)stack_a->next->data))
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
	apply_op(op, &stack_a, &stack_b);
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
