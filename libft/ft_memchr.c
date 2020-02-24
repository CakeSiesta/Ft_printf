/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:11:38 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/17 19:00:49 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*unsig_s;

	x = 0;
	unsig_s = (unsigned char *)s;
	while (x < n)
	{
		if (unsig_s[x] == (unsigned char)c)
			return (unsig_s + x);
		x++;
	}
	return (0);
}
