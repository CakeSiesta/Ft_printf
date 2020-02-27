/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:44:21 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/27 21:30:50 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_put_s(t_f *f, t_put *put, int len)
{
	init_put(put);
	if (f->precision > 0 && f->precision < len)
		put->precision = f->precision; // nbr de char a imprimer (crop)
	if (f->width > len || f->width > put->precision)
		put->width = f->width - put->precision; // calculer en fct de la prec
}

static void		apply_width(t_f *f, t_put *put, char *str)
{
	int x;

	x = 0;
	if (f->minus)
	{
		while (str[x])
		{
			ft_write(str[x], put);
			x++;
		}
		while (put->width--)
			ft_write(' ', put);
	}
	else
	{
		while (put->width--)
			ft_write(' ', put);
		while (str[x])
		{
			ft_write(str[x], put);
			x++;
		}
	}
}

void			convers_s(va_list arg, t_f *f, t_put *put)
{
	char	*str;
	int		len;
	int		x;

	x = 0;
	str = va_arg(arg, char *);
	len = ft_strlen(str);
	fill_put_s(f, put, len);
	// apply_minus
	if (put->width)
		apply_width(f, put, str);
	else
		while (str[x])
		{
			ft_write(str[x], put);
			x++;
		}
//	free(str); // not mallocated so no need?
}
