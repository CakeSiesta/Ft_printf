/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:48:06 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/28 09:04:49 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_c(t_f *f, t_put *put)
{
	if (f->width > 1)
		put->width = f->width - 1;
}

void			convers_c(va_list arg, t_f *f, t_put *put)
{
	char c;

	c = va_arg(arg, int);
	fill_put_c(f, put);
	if (put->width)
		while (put->width--)
			ft_write(' ', put);
	ft_write(c, put);
}
