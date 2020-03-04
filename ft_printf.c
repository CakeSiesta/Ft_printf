/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:02:35 by mkravetz          #+#    #+#             */
/*   Updated: 2020/03/04 14:55:24 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	size_t		x;
	t_f			f;
	va_list		arg;
	t_put		put;

	x = 0;
	va_start(arg, format);
	put.pos = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			init_put(&put);
			struc_init(&f);
			put.len_perc = parser(&f, &format[x + 1], arg);
			if (f.none)
			{
				x += put.len_perc;
			}
			else
			{
				parse_spec(&format[x + 1], &f, &put, arg);
				x += put.len_perc + 1;
			}
			init_put(&put);
			struc_init(&f);
		}
		else
		{
			ft_write(format[x], &put);
		}
		x++;
	}
	va_end(arg);
	return (0);
}
/*
int main ()
{
	char c;
//	ft_printf("%-.75u", 2693642494u);
//	printf("\n%-.75u", 2693642494u);
	ft_printf("%0.*d\n" ,-18,-1360145032);
	printf("%0.*d\n" ,-18,-1360145032);
	c = 'a';

	return (0);
}
*/
/*
int		main(void)
{
	ft_printf("false print[%-7p]\n", 2);
	printf("-true print[%-7p]\n", 2);
	return (0);
}
*/
