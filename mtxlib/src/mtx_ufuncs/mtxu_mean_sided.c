/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_mean_sided.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:18:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:14:38 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_mean_by_row_f(t_mtx *mtx, t_mtx *out)
{
	_mtx_sum_by_row_f(mtx, out);
	_mtx_idivf_scalar(out, mtx->shape[1]);
}

void	_mtx_mean_by_col_f(t_mtx *mtx, t_mtx *out)
{
	_mtx_sum_by_col_f(mtx, out);
	_mtx_idivf_scalar(out, mtx->shape[0]);
}

void	_mtx_mean_by_row_i(t_mtx *mtx, t_mtx *out)
{
	_mtx_sum_by_row_f(mtx, out);
	_mtx_idivi_scalar(out, mtx->shape[1]);
}

void	_mtx_mean_by_col_i(t_mtx *mtx, t_mtx *out)
{
	_mtx_sum_by_col_i(mtx, out);
	_mtx_idivi_scalar(out, mtx->shape[0]);
}

t_mtx	*mtx_mean_sided(t_mtx *mtx, int axis, t_mtx *out)
{
	static UFUNC_SIDED	ufuncs[2][2] = {
	{_mtx_mean_by_col_i, _mtx_mean_by_col_f},
	{_mtx_mean_by_row_i, _mtx_mean_by_row_f}};
	t_mtx				*ret;

	if (!mtx_isvalid_sided_ufunc(mtx, axis, out, (char *)__FUNCTION__))
		return (NULL);
	ret = out;
	if (!ret && axis == ROWWISE)
		ret = mtx_create_empty(mtx->shape[1], 1, mtx->dtype);
	else if (!ret && axis == COLWISE)
		ret = mtx_create_empty(mtx->shape[0], 1, mtx->dtype);
	if (!ret)
		return (fperror("%s : malloc error ", __FUNCTION__));
	ufuncs[axis][mtx->dtype == DTYPE_F](mtx, ret);
	return (ret);
}
