/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_swap_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:01:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/19 02:09:37 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	mtx_swap_arrays(t_mtx *mtx)
{
	void	*temp;

	if (!mtx || !mtx->swap)
	{
		fperror("%s : !mtx or !swap", __FUNCTION__);
		return (0);
	}
	temp = mtx->arr;
	mtx->arr = mtx->swap;
	mtx->swap = temp;
	return (1);
}

void	*mtx_malloc_swap_array(t_mtx *mtx)
{
	if (!mtx)
		return (fperror("%s : no mtx given", __FUNCTION__));
	if (!mtx->swap
		&& !malloc_free_p(mtx_sizeof_array(mtx), (void **)&mtx->swap))
		return (fperror("%s : malloc error", __FUNCTION__));
	return ((void *)1ULL);
}
