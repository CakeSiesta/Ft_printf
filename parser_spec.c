/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:28:14 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 16:45:25 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser_spec(const char *format, t_f *f, t_put *put, va_list arg)
{
	if (format[put->len_perc] == 'd' || format[put->len_perc] == 'i')
		convers_d(arg, f, put);
}
