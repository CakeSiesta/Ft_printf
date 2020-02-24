/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:27:00 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/23 17:59:18 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(unsigned int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

char		*ft_utoa(unsigned int n)
{
	size_t	num;
	int		size;
	char	*new;

	num = n;
	size = (count_len(n));
	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = (num % 10) + '0';
		num /= 10;
	}
	return (new);
}
