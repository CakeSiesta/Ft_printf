/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:49:55 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/14 16:09:42 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		x;
	char		*ptr1;
	const char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	x = -1;
	if (dst == 0 && src == 0)
		return (0);
	while (++x < n)
		*(ptr1 + x) = *(ptr2 + x);
	return (dst);
}
