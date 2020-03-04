/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:09:18 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/04 20:19:20 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_llunum(unsigned long long num, t_put *put)
{
	if (num >= 10)
		ft_write_num((num / 10), put);
	ft_write((num % 10) + '0', put);
}

t_llu	ft_strlen_lluint(unsigned long long num)
{
	unsigned long long x;

	x = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

int		ft_lenght_hex(long long unsigned int num)
{
	long long unsigned int x;

	x = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		x++;
	}
	return (x);
}

char	ft_hex_conversion(long long unsigned int n, int x)
{
	long long unsigned int		mod;
	char						*hex_min;
	char						*hex_maj;

	hex_min = "0123456789abcdef";
	hex_maj = "0123456789ABCDEF";
	if (x == 0)
	{
		if (n)
		{
			mod = n % 16;
			return (hex_min[mod]);
		}
	}
	if (x == 1)
	{
		if (n)
		{
			mod = n % 16;
			return (hex_maj[mod]);
		}
	}
	return (0);
}

char	ft_hexa_min(long long unsigned int num, t_put *put, int x)
{
	int		size;
	char	*new;
	int		i;

	i = 0;
	size = ft_lenght_hex(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (num == 0)
		ft_write('0', put);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = ft_hex_conversion(num, x);
		num = num / 16;
	}
	while (new[i])
	{
		ft_write(new[i], put);
		i++;
	}
	free(new);
	return (0);
}
