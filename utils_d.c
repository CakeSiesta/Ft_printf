/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:43:47 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/26 21:42:19 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_put(t_f *f, t_put *put)
{
	if (f->precision != -1 && f->precision > put->len)
		put->precision = f->precision - put->len;
	if (f->width > f->precision && f->width > put->len)
		put->width = f->width - put->precision - put->neg - put->len;
}
