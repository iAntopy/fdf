/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 04:33:09 by iamongeo         ###   ########.fr       */
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
// positive and negative slicing are possible and the selection will be cropped
// to garantee that it is within bounds of the mtx and at least 1 row/col wide.


static int	* __validate_setup_slice(t_mtx *m, int slice[4], int *rr, int *cr)
{
	int	sx;
	int	sy;
	int	ex;
	int	ey;

	sx = slice[0];
	sy = slice[1];
	ex = slice[2];
	ey = slice[3];
	if (!slice)
		return (MTX_ERROR("missing input slice"));
	sx = ft_clamp(((sx < 0) * m->shape[0]) + sx, 0, m->shape[0] - 1);
	sy = ft_clamp(((sy < 0) * m->shape[1]) + sy, 0, m->shape[1] - 1);
	ex = ft_clamp(((ex < 0) * m->shape[0]) + ex, sx + 1, m->shape[0]);
	ey = ft_clamp(((ey < 0) * m->shape[1]) + ey, sy + 1, m->shape[1]);
	*rr = ex - sx;
	*cr = ey - sy;
	return (slice);
}

t_mtx	*mtx_slice_view(t_mtx *mtx, int slice[4], t_mtx	*out)
{
	t_mtx	*ret;
	int		rrange;
	int		crange;

	if (!mtx)
		return (MTX_ERROR("missing mtx input"));
	if (!__validate_setup_slice(mtx, slice, &rrange, &crange))
		return (MTX_ERROR("invalid slice"));
	ret = out;
	if (!ret && !mtx_dup_struct(mtx, &ret))
		return (MTX_ERROR("!mtx or malloc error"));
	else
		mtx_dup_struct_inplace(mtx, ret);
	ret->offset = (mtx->strides[0] * slice[0] + mtx->strides[1] * slice[1]);
	ret->shape[0] = rrange;
	ret->shape[1] = crange;
	ft_printf("slice view : shapes set (rrange %d, crange %d)\n", rrange, crange);
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

t_mtx	*mtx_select_row(t_mtx *mtx, int row, t_mtx *out)
{
	int	slice[4];

	slice[0] = row;
	slice[1] = 0;
	slice[2] = row + 1;
	slice[3] = INT_MAX;
	return (mtx_slice_view(mtx, slice, out));
}

t_mtx	*mtx_select_col(t_mtx *mtx, int col, t_mtx *out)
{
	int	slice[4];

	slice[0] = 0;
	slice[1] = col;
	slice[2] = INT_MAX;
	slice[3] = col + 1;
	return (mtx_slice_view(mtx, slice, out));
}
