/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:36:00 by mkravetz          #+#    #+#             */
/*   Updated: 2019/10/29 16:19:49 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*mall;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((mall = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	x = -1;
	while (++x < ft_strlen(s))
		mall[x] = (*f)((unsigned int)x, s[x]);
	mall[x] = '\0';
	return (mall);
}
