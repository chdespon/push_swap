/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:40 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/12 14:17:46 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_index(t_engine *engine)
{
	t_list	*tmp_i;
	t_list	*tmp_j;
	int		index;

	tmp_i = engine->stack_a;
	while (tmp_i != NULL)
	{
		tmp_j = engine->stack_a;
		index = 0;
		while (tmp_j != NULL)
		{
			if (((t_data_num*)tmp_i->data)->value >
				((t_data_num*)tmp_j->data)->value)
				index++;
			tmp_j = tmp_j->next;
		}
		((t_data_num*)tmp_i->data)->index = index;
		tmp_i = tmp_i->next;
	}
}

void	set_stack_a(t_engine *engine, char **list)
{
	int			i;
	t_data_num	**data_num;

	data_num = (t_data_num**)malloc(sizeof(t_data_num*) * engine->len_stack_a);
	if (data_num == NULL)
		quit(ERROR_MALLOC, engine);
	i = 0;
	while (i < engine->len_stack_a)
	{
		data_num[i] = (t_data_num*)malloc(sizeof(t_data_num));
		if (data_num[i] == NULL)
		{
			while (i >= 0)
			{
				free(data_num[i]);
				i--;
			}
			quit(ERROR_MALLOC, engine);
		}
		data_num[i]->value = ft_atoi(list[i]);
		ft_lst_add_back(&engine->stack_a, ft_lst_create_node(data_num[i]));
		i++;
	}
	free(data_num);
}
