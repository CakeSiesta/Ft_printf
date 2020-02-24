/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:45:33 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/17 19:01:15 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	if (dst == 0 && src == 0)
		return (0);
	ptrdst = (unsigned char*)dst;
	ptrsrc = (unsigned char*)src;
	x = -1;
	if (ptrdst < ptrsrc)
		while (++x < len)
			ptrdst[x] = ptrsrc[x];
	else
		while (len-- > 0)
			ptrdst[len] = ptrsrc[len];
	return (dst);
}
