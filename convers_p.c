/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:33:28 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 21:32:23 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_p(t_f *f, t_put *put, unsigned long long int nb)
{
	init_put(put);
	if (f->precision != -1 && f->precision > (int)put->len - 2)
		put->precision = f->precision - put->len + 2;
	if ((size_t)f->width > put->len && f->width > f->precision)
	{
		put->width = f->width - put->len - f->precision + 2;
		if (f->precision == -1)
			put->width = put->width - 3;
		if (f->precision == 0)
			put->width = put->width - 2;
	}
	if (nb == 0 && f->width)
		put->width = f->width - 3;
}

static void		apply_minus(t_put *put, unsigned long long int nb)
{
	ft_write('0', put);
	ft_write('x', put);
	while (put->precision-- > 0)
		ft_write('0', put);
	ft_hexa_min(nb, put, 0);
	while (put->width-- > 0)
		ft_write(' ', put);
}

static void		apply_width(t_put *put, unsigned long long int nb)
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

static void		apply_precision(t_put *put, unsigned long long int nb)
{
	ft_write('0', put);
	ft_write('x', put);
	while (put->precision--)
		ft_write('0', put);
	ft_hexa_min(nb, put, 0);
}

void			convers_p(va_list arg, t_f *f, t_put *put)
{
	unsigned long long	nb;

	nb = va_arg(arg, unsigned long long int);
	put->len = ft_lenght_hex(nb) + 2;
	fill_put_p(f, put, nb);
	if (f->precision == 0 && nb == 0 && f->width)
	{
		wtf_case(f, put);
		return ;
	}
	if (f->minus && (put->width || f->precision))
		apply_minus(put, nb);
	else if (!f->minus && put->width)
		apply_width(put, nb);
	else if (put->precision && !put->width)
		apply_precision(put, nb);
	else
	{
		ft_write('0', put);
		ft_write('x', put);
		if (f->precision != 0)
			ft_hexa_min(nb, put, 0);
	}
}
