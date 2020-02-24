/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:25:22 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/20 15:10:09 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		x = 1;
	while (num != 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

char		*ft_itoa(int n)
{
	size_t	num;
	int		sign;
	int		size;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? 1 : 0;
	num = (n < 0) ? -n : n;
	size = (count_len(n));
	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	new[size] = '\0';
	if (sign == 1)
		new[0] = '-';
	while (size-- > sign)
	{
		new[size] = (num % 10) + '0';
		num /= 10;
	}
	return (new);
}
