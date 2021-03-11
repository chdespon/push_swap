/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_abs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:00:01 by ldutriez          #+#    #+#             */
/*   Updated: 2019/12/03 17:18:42 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_i_abs(int p_value)
{
	if (p_value == 0)
		return (0);
	if (p_value < 0)
		p_value *= -1;
	return (p_value);
}
