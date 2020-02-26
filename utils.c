/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:18:39 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/26 17:43:51 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoilen(const char *str, size_t *len)
{
	int						x;
	unsigned long long int	nb;
	int						symb;

	x = 0;
	nb = 0;
	symb = 1;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
			|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
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

void	ft_write(const char c, t_put *put) 
{
	write(1, &c, 1);
	put->pos++;	
}

int		ft_strlen_int(int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

void	ft_write_num(int num, t_put *put)
{
	if (num < 0)
		num = -num;
	if (num >= 10)
	{
		ft_write_num((num / 10), put);
		put->pos++;
	}
	ft_write((num % 10) + '0', put);
}
