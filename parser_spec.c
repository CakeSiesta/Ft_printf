/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:28:14 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/25 21:58:06 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser_spec(const char *format, size_t len, t_f *f, va_list arg)
{
	printf("len in parser is[%zu]\n", len);
	printf("char is [%c]\n", format[len - 1]);
	if (format[len] == 'd' || format[len] == 'i')
		convers_d(arg, f);

}
