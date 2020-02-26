/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:10:12 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/26 21:42:34 by jherrald         ###   ########.fr       */
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
	int			width;
	int			precision;
	int			neg;
	int			pos;
	size_t		len; // len de l'argument convert
	size_t		len_perc; // len entre le pourcent et le specifier
}				t_put;

int				ft_printf(const char *format, ...);
int				ft_atoilen(const char *str, size_t *len);
void			fill_put(t_f *f, t_put *put);
void			apply_zero(t_f *f, t_put *put, int nb);
void			apply_minus(t_f *f, t_put *put, int nb);
void			apply_width(t_f *f, t_put *put, int nb);
void			apply_precision(t_f *f, t_put *put, int nb);
void			apply_precision_param_zero(t_f *f, t_put *put);
void			convers_d(va_list arg, t_f *f, t_put *put);
void			parser_spec(const char *format, t_f *f, t_put *put, va_list arg);
size_t			parser(t_f *f, const char *str, va_list arg);
void			init_put(t_put *put);
void			struc_init(t_f *f);
void			ft_write(const char c, t_put *put);
int				ft_strlen_int(int num);
void			ft_write_num(int num, t_put *put);
#endif
