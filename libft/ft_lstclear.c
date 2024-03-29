/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:47:19 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:10:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*cur;

	if (!lst)
		return ;
	while (*lst)
	{
		cur = *lst;
		*lst = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
