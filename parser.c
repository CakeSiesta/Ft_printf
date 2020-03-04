/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:04:54 by mkravetz          #+#    #+#             */
/*   Updated: 2020/03/04 18:16:48 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struc_init(t_f *f)
{
	f->zero = 0;
	f->minus = 0;
	f->width = 0;
	f->precision = -1;
	f->percent = 0;
	f->none = 0;
}

void	init_put(t_put *put)
{
	put->width = 0;
	put->precision = 0;
	put->neg = 0;
}

static void		parser_conditions(t_f *f, char c, char *specs)
{
	if (c == '%')
		f->percent = 1;
	if (f->precision < -1)
		f->precision = -1;
	if ((f->precision != -1 || f->minus != 0) && !f->percent)
		f->zero = 0;
	if (ft_check_char(specs, c) == 0)
		f->none = 1;
}

size_t	parser(t_f *f, const char *str, va_list arg)
{
	size_t	x;
	char	*specs;

	x = 0;
	specs = "scdiupxX%";
	struc_init(f);
	if (ft_isalpha(str[x]) == 0)
	{
		while (str[x] == '0')
		{
			f->zero = 1;
			x++;
		}
		while (str[x] == '-')
		{
			f->minus = 1;
			x++;
		}
		while (str[x] == '0')
			x++;
		if (str[x] == '*' || (str[x] >= '1' && str[x] <= '9'))
		{
			if (str[x] == '*')
			{
				f->width = va_arg(arg, int);
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -f->width;
				}
				x++;
			}
			else
				f->width = ft_atoilen(&str[x], &x);
		}
		if (str[x] == '.')
		{
			x++;
			if (str[x] == '*')
			{
				f->precision = va_arg(arg, int);
				x++;
			}
			else
				f->precision = ft_atoilen(&str[x], &x);
		}
	}
	parser_conditions(f, str[x], specs);
	return (x);
}
