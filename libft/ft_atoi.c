/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:37:07 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/10 22:19:48 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** It handles long long overflows like the actual atoi.
*/

#include "libft.h"

static int	ft_isspace_and_symb(const char *str, int *symb)
{
	int		x;
	long	nb;

	x = 0;
	*symb = 1;
	nb = 0;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
			|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			*symb = *symb * (-1);
		x++;
	}
	return (x);
}

int			ft_atoi(const char *str)
{
	int		x;
	long	nb;
	int		symb;

	nb = 0;
	x = ft_isspace_and_symb(str, &symb);
	while (str[x] >= '0' && str[x] <= '9')
	{
		if ((nb * 10) + str[x] - 48 >= nb)
			nb = (nb * 10) + str[x] - 48;
		else
			return ((symb == -1) ? 0 : -1);
		x++;
	}
	return (str[x] == ('-' | '+') ? (0) : (nb * symb));
}
