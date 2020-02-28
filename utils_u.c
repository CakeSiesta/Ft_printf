/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:26:03 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/28 11:02:58 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_write_unum(unsigned int num, t_put *put)
{
	if (num >= 10)
	{
		ft_write_num((num / 10), put);
		put->pos++;
	}
	ft_write((num % 10) + '0', put);
}

unsigned int	ft_strlen_uint(unsigned int num)
{
	unsigned int x;

	x = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}
