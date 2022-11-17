/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_fill_typed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:43:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/20 03:17:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// DOESN'T WORK WITH VIEWS
t_mtx	*__mtx_fill_int(t_mtx *mtx, int value)
{
	int		*arr;
	size_t		nelems;

	arr = mtx->arr;
	nelems = mtx_get_nb_elems(mtx);
	while (nelems--)
		*(arr++) = value;
	return (mtx);
}

// DOESN'T WORK WITH VIEWS
t_mtx	*__mtx_fill_float(t_mtx *mtx, float value)
{
	float	*arr;
	size_t	nelems;

	arr = mtx->arr;
	nelems = mtx_get_nb_elems(mtx);
	while (nelems--)
		*(arr++) = value;
	return (mtx);
}

// WORKS WITH VIEWS
t_mtx	*_mtx_fill_int(t_mtx *mtx, int value)
{
	int	*arr;
	int	i;
	int	j;
	int	r;
	int	c;

	arr = _mtx_arr(mtx);
	i = -1;
	r = mtx->shape[0];
	c = mtx->shape[1];
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			*(int *)_mtx_idx(arr, mtx->strides, i, j) = value;
	}
	return (mtx);
}

// WORKS WITH VIEWS
t_mtx	*_mtx_fill_float(t_mtx *mtx, float value)
{
	float	*arr;
	int		i;
	int		j;
	int		r;
	int		c;

	arr = _mtx_arr(mtx);
	i = -1;
	r = mtx->shape[0];
	c = mtx->shape[1];
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			*(float *)_mtx_idx(arr, mtx->strides, i, j) = value;
	}
	return (mtx);
}

