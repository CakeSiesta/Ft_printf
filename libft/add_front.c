/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 04:11:17 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/16 04:23:08 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*add_front(char c, char *str, int i)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	if (!str)
		return (NULL);
	if (i == 0)
	{
		ret[0] = c;
		i = 1;
	}
	while (*str)
	{
		ret[i] = *str;
		i++;
		str++;
	}
	if (i == 1)
		ret[i] = c;
	return (ret);
}
