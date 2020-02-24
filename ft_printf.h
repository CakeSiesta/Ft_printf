/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:10:12 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/24 17:12:34 by mkravetz         ###   ########.fr       */
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

typedef struct	s_flag
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	int			percent;
	int			none;
}				t_flag;

int				ft_printf(char *format, ...);

int				ft_convert_str(va_list arg, t_pos *pos,
						t_flag *flag);

char			*ft_convert_int(va_list ap, t_pos *pos,
						t_flag *flag);

char			*ft_convert_hex(va_list arg, t_pos *pos,
						t_flag *flag, char *format);

int				ft_convert_char(va_list arg, t_pos *pos,
						t_flag *flag);

char			*ft_convert_usint(va_list arg, t_pos *pos,
						t_flag *flag);

char			*ft_convert_ptr(va_list arg, t_pos *pos,
						t_flag *flag);

size_t			parser(t_flag *f, char *str, va_list arg);

size_t			size_percent(const char *str);

char			*pad_maker(char c, size_t len);

int				ft_atoilen(const char *str, size_t *len);
#endif
