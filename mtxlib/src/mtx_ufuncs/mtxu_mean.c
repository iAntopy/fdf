/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_mean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:05:18 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:09:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

//works on full raw array, NOT on views.
int	__mtxu_mean_i(int *arr, size_t n_elem)
{
	int		sum;

	sum = __mtxu_sum_i(arr, n_elem);
	return (sum / n_elem);
}

float	__mtxu_mean_f(float *arr, size_t n_elem)
{
	float	sum;

	sum = __mtxu_sum_f(arr, n_elem);
	return (sum / n_elem);
}

float	_mtxu_mean_f(t_mtx *mtx)
{
	float	sum;

	sum = _mtxu_sum_f(mtx);
	return (sum / (mtx->shape[0] * mtx->shape[1]));
}

int	_mtxu_mean_i(t_mtx *mtx)
{
	int	sum;

	sum = _mtxu_sum_i(mtx);
	return (sum / (mtx->shape[0] * mtx->shape[1]));
}

void	*mtxu_mean(t_mtx *mtx, void *out)
{
	float	res_f;
	float	res_i;

	if (mtx->dtype == DTYPE_I)
	{
		if (mtx->is_view)
			res_i = _mtxu_mean_i(mtx);
		else	
			res_i = __mtxu_mean_i(mtx->arr, mtx->shape[0] * mtx->shape[1]);
		*(int *)out = res_i;
	}
	else if (mtx->dtype == DTYPE_F)
	{
		if (mtx->is_view)
			res_f = _mtxu_mean_f(mtx);
		else	
			res_f = __mtxu_mean_f(mtx->arr, mtx->shape[0] * mtx->shape[1]);
		*(float *)out = res_f;
	}
	else
		fperror("%s : dtype of mtx is invalid ", __FUNCTION__);
	return (out);	
}
