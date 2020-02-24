/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:10:12 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/24 22:19:15 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef long long unsigned	t_llu;

/*
** Flag activate
*/

typedef struct	s_f
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	int			percent;
	int			none;
}				t_f;

/*
** Copy the amounts of zeros or spaces in these variables to add them
** in the buffer
*/

typedef struct	s_put
{
	int			pad_zero;
	int			pad_width;
	int			pad_precision;
	int			pad_minus;
	int			neg;
}				t_put;

int				ft_printf(const char *format, ...);
int				ft_atoilen(const char *str, size_t *len);
void			fill_put(t_f *f);
void			convers_d(va_list arg, t_f *f);
void			parser_spec(const char *format, size_t len, t_f *f, va_list arg);
size_t			parser(t_f *f, const char *str, va_list arg);
#endif
