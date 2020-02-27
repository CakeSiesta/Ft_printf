/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:28:14 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/27 15:03:56 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser_spec(const char *format, t_f *f, t_put *put, va_list arg)
{
	if (format[put->len_perc] == 'd' || format[put->len_perc] == 'i')
		convers_d(arg, f, put);
	if (format[put->len_perc] == 'u')
		convers_u(arg, f, put);
	if (format[put->len_perc] == 'x')
		convers_x(arg, f, put, 0);
	if (format[put->len_perc] == 'X')
		convers_x(arg, f, put, 1);

}
