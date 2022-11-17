/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:47:39 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:08:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstcreate(void *content, size_t size)
{
	void	*data;
	t_lst	*lst;

	data = NULL;
	if (!ft_malloc_p(size, (void **)&data))
		return (NULL);
	ft_memcpy(data, content, size);
	lst = ft_lstnew(data);
	return (lst);
}
