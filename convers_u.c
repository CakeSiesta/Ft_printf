/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:06:59 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 22:33:57 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_zero(t_f *f, t_put *put, unsigned int nb)
{
	while (put->width--)
		ft_write('0', put);
	ft_write_unum(nb, put);
}

static void	apply_minus(t_f *f, t_put *put, unsigned int nb)
{
	if (f->precision > 0)
		while (put->precision--)
			ft_write('0', put);
	ft_write_unum(nb, put);
	while (put->width--)
		ft_write(' ', put);
}

static void	apply_width(t_f *f, t_put *put, unsigned int nb)
{
	while (put->width--)
		ft_write(' ', put);
	while (put->precision--)
		ft_write('0', put);
	ft_write_unum(nb, put);
}

static void	apply_precision(t_f *f, t_put *put, unsigned int nb)
{
	while (put->precision--)
		ft_write('0', put);
	ft_write_unum(nb, put);
}

static void	apply_precision_param_zero(t_f *f, t_put *put, unsigned int nb)
{
	if (f->precision == 0 && nb == 0)
	{
		put->width = f->width;
		while (put->width--)
			ft_write(' ', put);
	}
	if (!put->precision && !put->width && !f->zero && !f->minus)
		ft_write_unum(nb, put);
}

void		convers_u(va_list arg, t_f *f, t_put *put)
{
	unsigned int		nb;

	nb = va_arg(arg, unsigned int);
	put->len = ft_strlen_uint(nb);
	init_put(put);
	fill_put(f, put);
	if ((f->precision == 0 && nb == 0) || (!put->precision && !put->width
		&& !f->zero && !f->minus))
	{
		apply_precision_param_zero(f, put, nb);
		return ;
	}
	if (f->zero && f->width && !f->minus)
		apply_zero(f, put, nb);
	else if (f->minus && f->width && !f->zero)
		apply_minus(f, put, nb);
	else if (!f->minus && !f->zero && put->width)
		apply_width(f, put, nb);
	if (put->precision && !put->width && !f->zero && !f->minus)
		apply_precision(f, put, nb);
}
