/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:53:37 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 18:18:49 by jherrald         ###   ########.fr       */
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
	printf("coucou la mif \n");
	if (put->neg)
		ft_write('-', put);
	while(put->width--)
		ft_write('0', put);
	ft_write_num(nb, put);	
}

void	apply_minus(t_f *f, t_put *put, int nb)
{
	if (put->neg)
		ft_write('-', put);
	if (f->precision > 0)
		while (put->precision--)
			ft_write('0', put);
	ft_write_num(nb, put);
	while (put->width--)
		ft_write(' ', put);

}

void	apply_width(t_f *f, t_put *put, int nb)
{
	

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
	if (f->zero && put->width)
		apply_zero(f, put, nb);
	else if (f->minus && f->width)
		apply_minus(f, put, nb);
	else if (put->neg)
	{
		ft_write('-', put);
		ft_write_num(nb, put);
	}
	else if (!put->neg)
		ft_write_num(nb, put);
}

