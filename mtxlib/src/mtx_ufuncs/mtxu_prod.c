/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_prod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:16:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 08:20:48 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

//works on full raw array, NOT on views.
int	__mtxu_prod_i(int *arr, size_t n_elem)
{
	int	prod;

	prod = *(arr++);
	while (--n_elem)
		prod *= *(arr++);
	return (prod);
}

//works on full raw array, NOT on views.
float	__mtxu_prod_f(float *arr, size_t n_elem)
{
	float	prod;

	prod = *(arr++);
	while (--n_elem)
		prod *= *(arr++);
	return (prod);
}

float	_mtxu_prod_f(t_mtx *mtx)
{
	int		i;
	int		j;
	float	prod;

	i = mtx->shape[0];
	prod = 1;
	while (--i)
	{
		j = mtx->shape[1];
		while (--j)
			prod *= *(float *)_mtx_idx(mtx, i, j);
	}
	return (prod);
}

int	_mtxu_prod_i(t_mtx *mtx)
{
	int	i;
	int	j;
	int	prod;

	i = mtx->shape[0];
	prod = 1;
	while (--i)
	{
		j = mtx->shape[1];
		while (--j)
			prod *= *(int *)_mtx_idx(mtx, i, j);
	}
	return (prod);
}

void	*mtxu_prod(t_mtx *mtx, void *out)
{
	int		res_i;
	float	res_f;

	if (mtx->dtype == DTYPE_I)
	{
		if (mtx->is_view)
			res_i = _mtxu_prod_i(mtx);
		else
			res_i = __mtxu_prod_i(mtx->arr, mtx->shape[0] * mtx->shape[1]);
		*(int *)out = res_i;
	}
	else if (mtx->dtype == DTYPE_F)
	{
		if (mtx->is_view)
			res_f = _mtxu_prod_f(mtx);
		else
			res_f = __mtxu_prod_f(mtx->arr, mtx->shape[0] * mtx->shape[1]);
		*(float *)out = res_f;
	}
	else
		fperror("%s : mtx->dtype is invalid", __FUNCTION__);
	return (out);
}
