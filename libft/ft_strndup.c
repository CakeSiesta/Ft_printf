/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:52:50 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/31 16:55:10 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int y)
{
	int		x;
	char	*target;

	x = 0;
	if (!(target = malloc(sizeof(char) * (y + 1))))
		return (NULL);
	while (x < y)
	{
		target[x] = s1[x];
		x++;
	}
	target[x] = '\0';
	return (target);
}
