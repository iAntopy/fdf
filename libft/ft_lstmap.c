/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:48:57 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:08:34 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*new;
	t_lst	*crs;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	crs = new;
	while (lst->next)
	{
		lst = lst->next;
		crs->next = ft_lstnew(f(lst->content));
		if (!(crs->next))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		crs = crs->next;
	}
	return (new);
}
