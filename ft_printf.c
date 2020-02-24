/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:02:35 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/24 17:04:16 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	size_t		i;
	size_t		j;
	t_flag		flag;
	int			nb;
	va_list		arg;

	i = 0;
	j = 0;

	pos = pos_init();
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			pos->len = size_percent(format);
			parser(&flag, &format[i + 1], arg);
			if (format[pos->len + i - 1] == 's')
				ft_convert_str(arg, pos, &flag);
			if (format[pos->len + i - 1] == 'c' || format[pos->len + i - 1] == '%')
				ft_convert_char(arg, pos, &flag);
			if (format[pos->len + i - 1] == 'd' || format[pos->len + i - 1] == 'i')
				ft_convert_int(arg, pos, &flag);
			if (format[pos->len + i - 1] == 'u')
				ft_convert_usint(arg, pos, &flag);
			if (format[pos->len + i - 1] == 'p')
				ft_convert_ptr(arg, pos, &flag);
			if (format[pos->len + i - 1] == 'x' || format[pos->len + i - 1] == 'X')
				ft_convert_hex(arg, pos, &flag, format);
		}
		else
			write(1, &format[i++], 1);
	}
	va_end(arg);
	return (ft_strlen(buffer));
}
//
////int		main(void)
////{
////	ft_printf("false print[%-7p]\n", 2);
////	printf("-true print[%-7p]\n", 2);
////	return (0);
////}
