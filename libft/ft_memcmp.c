/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:21:10 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/15 18:27:33 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*unsig_s1;
	unsigned char	*unsig_s2;

	x = 0;
	unsig_s1 = (unsigned char*)s1;
	unsig_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (x < n && unsig_s1[x] == unsig_s2[x])
		x++;
	if (x == n)
		x--;
	return (unsig_s1[x] - unsig_s2[x]);
}
