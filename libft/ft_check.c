/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:03:06 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/21 01:27:13 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_check(char c, const char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] == c)
			return (0);
		x++;
	}
	return (1);
}
