/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:02:35 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/27 17:42:03 by jherrald         ###   ########.fr       */
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
			put.len_perc = parser(&f, &format[x + 1], arg);
			if (f.none)
				x += put.len_perc + 1;
			else
			{
				parser_spec(&format[x + 1], &f, &put, arg);
				x += put.len_perc + 1;
			}
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

int main ()
{
	char c;

	c = 'a';
//	printf("%hhd", 100);
	ft_printf("[%-5.15p]\n", NULL);
	printf("[%-18.15p]\n", NULL);
	return (0);
}

/*
int		main(void)
{
	ft_printf("false print[%-7p]\n", 2);
	printf("-true print[%-7p]\n", 2);
	return (0);
}
*/
