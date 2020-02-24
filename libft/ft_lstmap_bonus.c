/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:48:50 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/11 15:41:59 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Marche pas aux tests parce que del est protected
** (enlever le '|| !del' ligne 24 pour test)
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *alst;

	if (!lst || !del)
		return (NULL);
	if (!f)
		return (lst);
	if (!(alst = ft_lstnew(f(lst->content))))
		return (NULL);
	if (lst->next)
	{
		if (!(alst->next = ft_lstmap(lst->next, f, del)))
		{
			ft_lstdelone(lst, del);
			return (NULL);
		}
	}
	else
		alst->next = NULL;
	return (alst);
}
