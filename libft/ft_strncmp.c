/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 08:59:34 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/10 22:56:27 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	int		res;

	x = 0;
	res = 0;
	if (n == 0)
		return (0);
	while ((s1[x] != '\0') && (s2[x] != '\0')
			&& (s1[x] == s2[x]) && (n - 1 - x))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
