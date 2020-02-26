/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:53:37 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:11 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_put(t_f *f, t_put *put, size_t len)
{
//	init_put(put);
	if (f->precision != -1 && f->precision > len)
	{
		put->precision = f->precision - len;
	}
	if (f->width > f->precision && f->width > len)
	{
		put->width = f->width - put->precision - put->neg - len;
	}
	printf("put width is :%d\n", put->width);
	printf("put precision is :%d\n", put->precision);
}

void	apply_zero(t_f *f, t_put *put, int nb, size_t len)
{
	printf("put widthhhh is %d\n", put->width);
	while(put->width--)
	{
		ft_write('0', put);
	}

}


void	convers_d(va_list arg, t_f *f, t_put *put)
{
	int		nb;
	size_t	len;

	printf("in convers d\n");
	nb = va_arg(arg, int);
	len = ft_strlen_int(nb);
	init_put(put);
	if (nb < 0)
		put->neg = 1;
	printf("f->width %d\n", f->width);
	printf("f->zero %d\n", f->zero);
	fill_put(f, put, len); // fill put/pad structure	
	if (f->zero && f->width)
		apply_zero(f, put, nb, len);
	printf("strlen is %zu\n", len);
	printf("nb is %d\n", nb);

}

