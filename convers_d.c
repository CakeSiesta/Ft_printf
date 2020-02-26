/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:53:37 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 13:01:09 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_put(t_f *f, t_put *put, size_t len)
{
	printf("wouhou\n");
	if (f->precision)
	{
		put->precision = f->width
	}
	if (f->width)
	{
		put->width = f->width - len;
		printf("put->width is %d\n", put->width);
	}
			
}


void	convers_d(va_list arg, t_f *f, t_put *put)
{
	int		nb;
	size_t	len;

	printf("in convers d\n");
	nb = va_arg(arg, int);
	len = ft_strlen_int(nb);
	printf("strlen is %zu\n", len);
	printf("nb is %d\n", nb);
	fill_put(f, put, len); // fill put/pad structure	

}

