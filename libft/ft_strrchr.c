/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:41:55 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/18 15:01:54 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	x;

	x = ft_strlen((char *)s);
	while (x != 0 && s[x] != (char)c)
		x--;
	if (s[x] == (char)c)
		return ((char *)&s[x]);
	return (NULL);
}
