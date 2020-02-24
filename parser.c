/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:04:54 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/24 17:06:13 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struc_init(t_flag *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->percent = 0;
	flag->none = 0;
}

size_t		size_percent(const char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i] != '%')
		i++;
	while (ft_isalpha(str[i]) == 0)
	{
		i++;
		j++;
	}
	return (j);
}

size_t	parser(t_flag *f, char *str, va_list arg)
{
	size_t	i;
	char	*specs;

	i = 0;
	specs = ft_strdup("scdiupxX%");
	struc_init(f);
	if (ft_isalpha(str[i]) == 0)
	{
		while (str[i] == '0')
		{
			f->zero = 1;
			i++;
		}
		while (str[i] == '-')
		{
			f->minus = 1;
			i++;
		}
		while (str[i] == '0')
			i++;
		if (str[i] == '*' || (str[i] >= '1' && str[i] <= '9'))
		{
			if (str[i] == '*')
			{
				f->width = va_arg(arg, int);
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -f->width;
				}
				i++;
			}
			else
				f->width = ft_atoilen(&str[i], &i);
		}
		if (str[i++] == '.')
		{
			if (str[i] == '*')
			{
				f->precision = va_arg(arg, int);
				i++;
			}
			else
				f->precision = ft_atoilen(&str[i], &i);
			if (f->precision != -1 || f->minus != 0)
				f->zero = 0;
		}
	}
	if (str[i] == '%')
		f->percent = 1;
	if (f->precision < -1)
		f->precision = -1;
	if (ft_check_char(specs, str[i]) == 0)
		f->none = 1;
	free(specs);
	return (i);
}
