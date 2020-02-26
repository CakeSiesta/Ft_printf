/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:02:35 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/26 14:26:46 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	size_t		x;
	size_t		len;
	t_f			f;
	va_list		arg;
	t_put		put;

	x = 0;
	va_start(arg, format);
	init_put(&put);
	put.pos = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			len = parser(&f, &format[x + 1], arg);
			if (f.none)
				x += len + 1;
			else
			{
				printf("len is %zu\n", len);
				parser_spec(&format[x + 1], len, &f, arg);
				x += len + 1;
			}
		}
		else
			ft_write(format[x], &put);
		x++;
	}
	va_end(arg);
	return (0);
}

int main ()
{
	ft_printf("coucou%010d\n", -88);
	printf("coucou[%010d]\n", -88);
	return (0);
}

//
////int		main(void)
////{
////	ft_printf("false print[%-7p]\n", 2);
////	printf("-true print[%-7p]\n", 2);
////	return (0);
////}
