/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:46:01 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/15 17:44:47 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	if (n)
	{
		ptrdst = dst;
		ptrsrc = src;
		while (n-- != 0)
		{
			if ((*ptrdst++ = *ptrsrc++) == (unsigned char)c)
				return (ptrdst);
		}
	}
	return (0);
}
