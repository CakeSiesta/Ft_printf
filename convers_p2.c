/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:28:07 by mkravetz          #+#    #+#             */
/*   Updated: 2020/03/05 21:31:47 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function is here to handle such thing : ("%*.p", -42, NULL).
*/

void	wtf_case(t_f *f, t_put *put)
{
	if (put->width)
		put->width++;
	if (f->minus)
	{
		ft_write('0', put);
		ft_write('x', put);
		while (put->width--)
			ft_write(' ', put);
	}
	if (!f->minus)
	{
		while (put->width--)
			ft_write(' ', put);
		ft_write('0', put);
		ft_write('x', put);
	}
}
