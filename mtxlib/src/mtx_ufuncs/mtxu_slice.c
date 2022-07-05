/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:06:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

// mtx_slice_view provides a seperate t_mtx struct which gives a view of 
// a slice of the original matrix described by the slice param.
// A view means that the data of the array is the same as the original array
// so that changes made in the view matrix DO change the data in the original.
// A view matrix can be transposed just as a regular matrix with mtx_transpose.
//
// slice is a 4 int array where each member represents the following:
//	- slice[0] = row_s = starting row index.
//	- slice[1] = col_s = starting col index.
//	- slice[2] = row_e = ending row index (indexed exclisivly [row_s:row_e[ ).
//	- slice[3] = col_e = ending col index (indexed exclisivly [col_s:col_e[ ).
// [side]_e must be greater than [side_s].
// if INT_MAX is given as [side]_e, slicing is done to the end of this side of 
// matrix. Indices must within [0:shape[side][ exclusively.

t_mtx	*mtx_slice_view(t_mtx *mtx, const int slice[4])
{
	t_mtx	*ret;
	int	rrange;
	int	crange;


	if (!mtx_index_is_inbound(mtx, slice[0], slice[1]))
		return (MTX_ERROR("slice start is out off bounds."));
	rrange = slice[2] - slice[0];
	crange = slice[3] - slice[1];
	if (rrange < 1 || crange < 1)
		return (MTX_ERROR("hori and vert slice ranges must be > 0."));
	if (!mtx || !mtx_dup_struct(mtx, &ret))
		return (MTX_ERROR("!mtx or malloc error"));
	ret->offset = (mtx->strides[0] * slice[0]);
	ret->offset += mtx->strides[1] * slice[1];
	ret->shape[0] = ft_clamp(rrange, 0, mtx->shape[0]);
	ret->shape[1] = ft_clamp(crange, 0, mtx->shape[1]);
	ret->is_view = 1;
	if (rrange == 1)
		mtx_transpose(ret);
	ret->ndims = 2 - (rrange == 1 || crange == 1);
	return (ret);
}

/*
// View whole matrix, is_view is set to 0 because there is no offset in memmory 
// to take special care for. Since most functions have will index faster on 
// whole arrays than partial ones (sliced views), we treat the view as the 
// original by just copying its ptr. vout should be a ptr to localy declared 
// t_mtx in a function call, not malloced.
t_mtx	*mtx_view(t_mtx *mtx, t_mtx *vout)
{
	t_mtx	*view;

	if (!mtx)
		return (MTX_ERROR("!mtx"));
	if (vout)
	{
		ft_memcpy(vout, mtx, sizeof(t_mtx));
		vout->out = NULL;
		vout->is_view = 0;
		view = vout;
	}
	else if (!mtx_dup_struct(mtx, &view))
		return (MTX_ERROR("malloc error"));
	view->arr = mtx->arr;
	vout->is_view = 0;
	return (view);
}
*/

t_mtx	*mtx_select_row(t_mtx *mtx, int row)
{
	t_mtx		*ret;
	const int	slice[4] = {row, 0, row + 1, INT_MAX};

	if (!mtx || !mtx_index_is_inbound(mtx, row, 0))
		return (fperror("mtx_select_row : row %d is out of bounds", row));
	ret = mtx_slice_view(mtx, slice);
	return (ret);
}

t_mtx	*mtx_select_col(t_mtx *mtx, int col)
{
	t_mtx		*ret;
	const int	slice[4] = {0, col, INT_MAX, col + 1};

	if (!mtx || !mtx_index_is_inbound(mtx, 0, col))
		return (fperror("mtx_select_row : col %d is out of bounds", col));
	ret = mtx_slice_view(mtx, slice);
	return (ret);
}
