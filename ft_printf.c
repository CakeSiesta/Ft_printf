/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:02:35 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/25 18:15:33 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	size_t		x;
	size_t		len;
	t_f			f;
	va_list		arg;

	x = 0;
	va_start(arg, format);
	while (format[x])
	{
		if (format[x] == '%')
		{
			len = parser(&f, &format[x + 1], arg);
			parser_spec(&format[x + 1], len, &f, arg);
			x++;
		}
		else
			write(1, &format[x++], 1);
	}
	va_end(arg);
	return (0);
}

int main ()
{
	ft_printf("coucou%-10d\n", 10);
	return (0);
}

//
////int		main(void)
////{
////	ft_printf("false print[%-7p]\n", 2);
////	printf("-true print[%-7p]\n", 2);
////	return (0);
////}
