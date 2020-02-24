/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_convert_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:47:33 by mkravetz          #+#    #+#             */
/*   Updated: 2020/01/28 14:21:29 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen_base(unsigned long long n, int base)
{
	size_t		size;

	size = 0;
	if (base < 2 || base > 16)
		return (0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static char		*ft_itoa_cal(char *str, unsigned long long n, int len, int base)
{
	int pos;
	int i;
	int j;

	i = 0;
	j = 1;
	pos = 87;
	if ((n % base) < 10)
		str[len--] = (char)(n % base) + 48;
	else
		str[len--] = (char)(n % base) + pos;
	while (n >= base)
	{
		n = n / base;
		if ((n % base) < 10)
			str[len--] = (char)(n % base) + 48;
		else
			str[len--] = (char)(n % base) + pos;
	}
	return (str);
}

char			*ft_llutoa_convert_base(unsigned long long nb, int base)
{
	int					len;
	char				*str;
	unsigned long long	n;

	n = (unsigned long long)nb;
	if (base < 2 || base > 16)
		return (NULL);
	len = (int)ft_intlen_base((unsigned long long)n, base);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	len--;
	return (ft_itoa_cal(str, n, len, base));
}
