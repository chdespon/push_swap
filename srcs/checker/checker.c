/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/24 15:57:44 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_op(char *str)
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
	else if (ft_strcmp(str, "") == 0)
		return ;
	else
		quit(WRONG_OP);
}

void	read_output(void)
{
	char *line;

	ft_putstr("Enter an operation... \"CRTL d\" to exit\n");
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		check_op(line);
		ft_putstr("Enter an operation... \"CTRL d\" to exit\n");
		free(line);
	}
	free(line);
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
	char	**stack_a;
	void	**stack_b;
	int		len;

	if (ac != 2)
		return (0);
	stack_a = ft_split(av[1], ' ');
	len = ft_tab_len((void**)stack_a);
	parse_arg(stack_a, len, av[1]);
	stack_b = ft_tab_new(len);
	read_output();
	if (is_sort(stack_a, (char**)stack_b, len))
		quit(OK);
	else
		quit(KO);
	return (0);
}
