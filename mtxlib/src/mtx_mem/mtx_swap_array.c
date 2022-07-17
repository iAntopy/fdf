/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_swap_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:01:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 18:47:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_swap_arrays(t_mtx *mtx)
{
	void	*temp;

	temp = mtx->arr;
	mtx->arr = mtx->swap;
	mtx->swap = temp;
}

int	mtx_swap_arrays(t_mtx *mtx)
{
	void	*temp;

	if (!mtx || !mtx->swap)
	{
		MTX_ERROR("!mtx or !swap");
		return (0);
	}
	temp = mtx->arr;
	mtx->arr = mtx->swap;
	mtx->swap = temp;
	return (1);
}

void	*mtx_malloc_swap(t_mtx *mtx)
{
	if (!mtx)
		return (MTX_ERROR("no input mtx"));
	if (!mtx->swap
		&& !malloc_free_p(mtx_sizeof_array(mtx), (void **)&mtx->swap))
		return (MTX_ERROR("malloc error"));
	return (mtx->swap);
}

// For inplace destructive opperations in a view mtx such as dot prod.
// first puts the result in a swap owned by the view mtx. Than copies
// the swap array in the original array. This function does not malloc
// the swap array, use mtx_malloc_swap() before the destructive
// opperation and route the output to swap. THIS OPPERATION IS 
// INNEFFICIANT.
t_mtx	*__mtx_copy_view_swap_to_array_4bytes(t_mtx *view)
{
	int	i;
	int	j;
	size_t	dsize;
	int	*swap;
	int	*arr;

	dsize = mtx_get_dsize(view->dtype);
	if (!view || !view->is_view || !view->swap || dsize != 4)
		return (MTX_ERROR("no view or !is_view or !swap or dsize != 4"));
	swap = view->swap;
	arr = _mtx_arr(view);
	i = -1;
	while (++i < view->shape[0])
	{
		j = -1;
		while (++j < view->shape[1])
			*(int *)_mtx_idx(arr, view->strides, i, j) = *(int *)(swap++);
	}
	return (view);
}
