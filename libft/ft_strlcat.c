/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:02:07 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/04 19:30:59 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Line 37 --> because n stops at '/0'
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*ptrdst;
	const char	*ptrsrc;
	size_t		n;
	size_t		len_diff;

	ptrdst = dst;
	ptrsrc = src;
	n = size;
	while (n-- != 0 && *ptrdst)
		ptrdst++;
	len_diff = ptrdst - dst;
	n = size - len_diff;
	if (n == 0)
		return (len_diff + ft_strlen(ptrsrc));
	while (*ptrsrc)
	{
		if (n != 1)
		{
			*ptrdst++ = *ptrsrc;
			n--;
		}
		ptrsrc++;
	}
	*ptrdst = '\0';
	return (len_diff + (ptrsrc - src));
}
