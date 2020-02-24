/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:56:52 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/24 20:01:26 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoilen(const char *str, size_t *len)
{
	int	x;
	unsigned long long nb;
	int	symb;

	x = 0;
	nb = 0;
	symb = 1;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n' ||
			str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x++] == '-')
			symb = symb * (-1);
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb = (nb * 10) + (str[x] - 48);
		if (nb > LONG_MAX)
			return ((symb + 1) / -2);
		x++;
		(*len)++;
	}
	return ((int)(nb * symb));
}
