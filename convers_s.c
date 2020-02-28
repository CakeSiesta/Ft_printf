/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:44:21 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/28 17:23:26 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_s(t_f *f, t_put *put, int len)
{
	init_put(put);
	if (f->precision > 0 && f->precision < len)
		put->precision = f->precision;
	if (put->precision && f->width > put->precision)
		put->width = f->width - put->precision;
	else if (f->width > len)
		put->width = f->width - len;
}

static void		apply_width(t_f *f, t_put *put, char *str)
{
	int x;

	x = 0;
	if (!f->minus && !f->zero)
		while (put->width--)
			ft_write(' ', put);
	if (f->zero)
		while (put->width)
		{
			ft_write('0', put);
			put->width--;
		}
	if (!put->precision)
		while (str[x])
			ft_write(str[x++], put);
	if (put->precision)
		while (str[x] && put->precision--)
			ft_write(str[x++], put);
	if (f->minus)
		while (put->width--)
			ft_write(' ', put);
}

void			convers_s(va_list arg, t_f *f, t_put *put)
{
	char	*str;
	int		len;
	int		x;

	x = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	fill_put_s(f, put, len);
	if (f->precision == 0)
	{
		while (f->width--)
			ft_write(' ', put);
		return ;
	}
	if (put->width || put->precision)
		apply_width(f, put, str);
	else
		while (str[x])
			ft_write(str[x++], put);
}
