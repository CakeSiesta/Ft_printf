/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:48:06 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/04 14:30:36 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_c(t_f *f, t_put *put)
{
	init_put(put);
	if (f->width > 1)
		put->width = f->width - 1;
}

void			convers_c(va_list arg, t_f *f, t_put *put, int i)
{
	char c;

	fill_put_c(f, put);
//	printf("put width %d\n", put->width);
//	printf("f zero %d\n", f->zero);
//	printf("f precision %d\n", f->precision);
	if (i)
		c = '%';
	if (i && f->zero && !f->minus)
	{
		while (put->width > 0)
		{
			ft_write('0', put);
			put->width--;
		}
		ft_write(c, put);
		return ;
	}
	if (!i)
		c = va_arg(arg, int);
	if (put->width)
	{
		if (f->minus)
		{
			ft_write(c, put);
			while (put->width--)
				ft_write(' ', put);
		}
		if (!f->minus)
		{
			while (put->width--)
				ft_write(' ', put);
			ft_write(c, put);
		}
	}
	if (!put->width)
		ft_write(c, put);
}
