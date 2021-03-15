/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/15 15:09:45 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**read_outpout()
{
	char *buff;
	int ret;
	void **opp;

	ret = 3;
	buff = ft_strnew(5);
	opp = ft_tab_new(0);
	while (ret > 2)
	{
		ret = read(STDIN_FILENO, buff, 4);
		if (ret > 2)
			ft_add_to_tab(ft_strdup(buff), &opp);
	}
	return (opp);
}

int		is_sort(char **stack_a, char **stack_b, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(stack_a[i], stack_a[i + 1]) > 1)
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
	stack_b = ft_tab_new(len);
	read_outpout();
	if (is_sort(stack_a, (char**)stack_b, len))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_free_tab(stack_b);
	return (0);
}