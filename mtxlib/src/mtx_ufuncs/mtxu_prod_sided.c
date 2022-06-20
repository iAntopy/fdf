/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_prod_sided.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:22:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 08:27:40 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_prod_by_row_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	prod;
	int		r;
	int		c;

	i = -1;
	r = mtx->shape[0];
	c = mtx->shape[1];
	while (++i < r)
	{
		j = -1;
		prod = 1;
		while (++j < c)
			prod *= *(float *)_mtx_idx(mtx, i, j);
		*(float *)_mtx_idx(out, i, 0) = prod;
	}
}

void	_mtx_prod_by_col_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	prod;
	int		r;
	int		c;

	j = -1;
	r = mtx->shape[0];
	c = mtx->shape[1];
	while (++j < c)
	{
		i = -1;
		prod = 1;
		while (++i < r)
			prod *= *(float *)_mtx_idx(mtx, i, j);
		*(float *)_mtx_idx(out, j, 0) = prod;
	}
}

void	_mtx_prod_by_row_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	prod;
	int	r;
	int	c;

	i = -1;
	r = mtx->shape[0];
	c = mtx->shape[1];
	while (++i < r)
	{
		j = -1;
		prod = 1;
		while (++j < c)
			prod *= *(int *)_mtx_idx(mtx, i, j);
		*(int *)_mtx_idx(out, i, 0) = prod;
	}
}

void	_mtx_prod_by_col_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	prod;
	int	r;
	int	c;

	j = -1;
	r = mtx->shape[0];
	c = mtx->shape[1];
	while (++j < c)
	{
		i = -1;
		prod = 1;
		while (++i < r)
			prod *= *(int *)_mtx_idx(mtx, i, j);
		*(int *)_mtx_idx(out, j, 0) = prod;
	}
}

t_mtx	*mtx_prod_sided(t_mtx *mtx, int axis, t_mtx *out)
{
	static UFUNC_SIDED	ufuncs[2][2] = {
	{_mtx_prod_by_col_i, _mtx_prod_by_col_f},
	{_mtx_prod_by_row_i, _mtx_prod_by_row_f}};
	t_mtx				*ret;

	if (!mtx_isvalid_sided_ufunc(mtx, axis, out, (char *)__FUNCTION__))
		return (NULL);
	ret = out;
	if (!ret && axis == ROWWISE)
		ret = mtx_create_empty(mtx->shape[1], 1, mtx->dtype);
	else if (!ret && axis == COLWISE)
		ret = mtx_create_empty(mtx->shape[0], 1, mtx->dtype);
	if (!mtx)
		return (fperror("%s : malloc error ", __FUNCTION__));
	ufuncs[axis][mtx->dtype == DTYPE_F](mtx, ret);
	return (ret);
}
