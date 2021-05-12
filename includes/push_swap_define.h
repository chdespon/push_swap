/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:51:30 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/12 14:17:27 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEFINE_H
# define PUSH_SWAP_DEFINE_H

# define _BLUE "\033[1;34m"
# define _WHITE "\033[0;37m"
# define _GREEN "\033[32m"
# define _PURPLE "\033[1;35m"
# define _RED "\033[1;31m"

typedef enum	e_error
{
	ERROR_MALLOC,
	NOT_DIGIT,
	BIGGER_THAN_INT,
	DUPLICATE,
	OK,
	KO,
	WRONG_OP
}				t_error;

typedef struct	s_engine
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op;
	int		len_stack_a;
	int		len_stack_b;
	int		last_node;
	t_bool	verbose;
}				t_engine;

typedef struct	s_data_num
{
	int		index;
	int		value;
}				t_data_num;

#endif
