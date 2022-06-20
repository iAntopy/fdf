/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:36:19 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 10:22:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// DOES NOT work with views
void	__mtx_isqrtf(float *arr, size_t n_elem)
{
	while (n_elem--)
	{
		*arr = sqrtf(*arr);
		arr++;
	}
}

// DOES NOT work with views
void	__mtx_sqrtf(float *arr, float *out, size_t n_elem)
{
	while (n_elem--)
	{
		*out = sqrtf(*arr);
		out++;
		arr++;
	}
}

void	_mtx_isqrtf(t_mtx *mtx)
{
	int		i;
	int		j;
	int		r;
	int		c;
	float	*v;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j =  -1;
		while (++j < c)
		{
			v = (float *)_mtx_idx(mtx, i, j);
			*v = sqrtf(*v);
		}
	}
}

void	_mtx_sqrtf(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	int		r;
	int		c;
	float	*v;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			v = (float *)_mtx_idx(mtx, i, j);
			*(float *)_mtx_idx(out, i, j) = sqrtf(*v);
		}
	}
}

t_mtx	*mtx_sqrt(t_mtx *mtx, int inplace, t_mtx *out)
{
	t_mtx	*ret;

	if (!mtx || mtx->dtype != DTYPE_F)
		return (fperror("%s : invalid type", __FUNCTION__));
	if (inplace)
	{
		if (mtx->is_view)
			_mtx_isqrtf(mtx);
		else
			__mtx_isqrtf(mtx->arr, mtx->shape[0] * mtx->shape[1]);
		return (mtx);
	}
	ret = out;
	if (!out && !mtx_dup_empty(mtx, &ret, DTYPE_F))
		return (NULL);
	if (mtx->is_view)
		_mtx_sqrtf(mtx, out);
	else
		__mtx_sqrtf(mtx->arr, ret->arr, mtx->shape[0] * mtx->shape[1]);
	return (ret);
}
