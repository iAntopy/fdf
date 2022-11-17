/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:48:33 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:07:29 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*elem;

	elem = NULL;
	if (!ft_malloc_p(sizeof(t_lst), (void **)&elem))
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
