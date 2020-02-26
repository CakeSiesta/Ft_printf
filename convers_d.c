/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:53:37 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 16:48:42 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_put(t_f *f, t_put *put)
{
	if (f->precision != -1 && f->precision > put->len)
	{
		put->precision = f->precision - put->len;
	}
	if (f->width > f->precision && f->width > put->len)
	{
		put->width = f->width - put->precision - put->neg - put->len;
	}
}

void	apply_zero(t_f *f, t_put *put, int nb)
{
	if (put->neg)
		ft_write('-', put);
	while(put->width--)
	{
		ft_write('0', put);
	}

}


void	convers_d(va_list arg, t_f *f, t_put *put)
{
	int		nb;

	nb = va_arg(arg, int);
	put->len = ft_strlen_int(nb);
	init_put(put);
	if (nb < 0)
	{
		nb = -nb;
		put->neg = 1;
	}
	fill_put(f, put); // fill put/pad structure	
	if (f->zero && f->width)
		apply_zero(f, put, nb);
}

