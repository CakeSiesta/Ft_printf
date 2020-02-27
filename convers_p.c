/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:33:28 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/27 19:43:09 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_p(t_f *f, t_put *put)
{
	if (f->precision != -1 && f->precision > put->len - 2)
		put->precision = f->precision - put->len + 2;
	if (f->width > put->len && f->width > f->precision)
		put->width = f->width - put->len - f->precision + 2;
}

static void		apply_minus(t_f *f, t_put *put, unsigned long long int nb)
{
	ft_write('0', put);
	ft_write('x', put);
	while (put->precision-- > -1)
		ft_write('0', put);
	ft_hexa_min(nb, put, 0);
	while (put->width-- > 0)
		ft_write(' ', put);
}


static void		apply_width(t_f *f, t_put *put, unsigned long long int nb)
{
	if (put->width > 0)
	{
		while (put->width > 0)
		{
			ft_write(' ', put);
			put->width--;
		}
	}
	ft_write('0', put);
	ft_write('x', put);
	if (put->precision > 0)
	{
		while (put->precision)
		{
			ft_write('0', put);
			put->precision--;
		}
	}
	ft_hexa_min(nb, put, 0);
}

void	convers_p(va_list arg, t_f *f, t_put *put)
{
	unsigned long long 	nb;

	nb = va_arg(arg, unsigned long long int);
	put->len = ft_lenght_hex(nb) + 2;
	init_put(put);
	fill_put_p(f, put);
	if (nb == 0 && !f->width && f->precision == -1 && nb != 0x0)
		ft_hexa_min(nb, put, 0);
	if (f->minus && put->width)
		apply_minus(f, put, nb);
	if (!f->minus && put->width)
		apply_width(f, put, nb);
}
