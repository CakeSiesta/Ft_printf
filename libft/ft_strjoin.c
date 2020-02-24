/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:32:27 by mkravetz          #+#    #+#             */
/*   Updated: 2020/02/12 19:04:35 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len_s1;
	int		x;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	x = ft_strlen(s2);
	if (!(joined = (char *)malloc(sizeof(char) * (len_s1 + x + 1))))
		return (NULL);
	x = -1;
	while (s1[++x])
		joined[x] = s1[x];
	x = -1;
	while (s2[++x])
		joined[len_s1 + x] = s2[x];
	joined[len_s1 + x] = '\0';
	return (joined);
}
