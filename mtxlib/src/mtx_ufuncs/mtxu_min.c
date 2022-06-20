/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:15:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:38:49 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

//works on full raw array, NOT on views.
int	*__mtxu_min_i(int *arr, size_t n_elem)
{
	int	*res;

	res = arr;
	while (n_elem--)
	{
		if (*arr < *res)
			res = arr;
		arr++;
	}
	return (res);
}

//works on full raw array, NOT on views.
float	*__mtxu_min_f(float *arr, size_t n_elem)
{
	float	*res;

	res = arr;
	while (n_elem--)
	{
		if (*arr < *res)
			res = arr;
		arr++;
	}
	return (res);
}

float	*_mtxu_min_f(t_mtx *mtx)
{
	int		i;
	int		j;
	float	*res;
	float	*value;

	res = (float *)mtx->arr;
	i = mtx->shape[0];
	while (i--)
	{
		j = -1;
		while (++j < mtx->shape[1])
		{
			value = (float *)_mtx_idx(mtx, i, j);
			if (*value < *res)
				res = value;
		}
	}
	return (res);
}

int	*_mtxu_min_i(t_mtx *mtx)
{
	int	i;
	int	j;
	int	*res;
	int	*value;

	res = (int *)mtx->arr;
	i = mtx->shape[0];
	while (i--)
	{
		j = -1;
		while (++j < mtx->shape[1])
		{
			value = (int *)_mtx_idx(mtx, i, j);
			if (*value < *res)
				res = value;
		}
	}
	return (res);
}

void	*mtxu_min(t_mtx *mtx)
{
	void	*res;

	res = NULL;
	if (mtx->dtype == DTYPE_I)
	{
		if (mtx->is_view)
			res = _mtxu_min_i(mtx);
		else
			res = __mtxu_min_i(mtx->arr, mtx->shape[0] * mtx->shape[1]);
	}
	else if (mtx->dtype == DTYPE_F)
	{
		if (mtx->is_view)
			res = _mtxu_min_f(mtx);
		else
			res = __mtxu_min_f(mtx->arr, mtx->shape[0] * mtx->shape[1]);
	}
	else
		fperror("%s : dtype of mtx is invalid ", __FUNCTION__);
	return (res);
}
