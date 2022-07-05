/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:14:45 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:02:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// ft_random in minilibft
void	__mtx_fill_random(t_mtx *mtx)
{
	int		i;
	int		j;
	int		r;
	int		c;
	float	*marr;

	marr = _mtx_arr(mtx);
	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			*(float *)_mtx_idx(marr, mtx->strides, i, j) = ft_random();
	}
}

void	__mtx_fill_randint(t_mtx *mtx, int min, int range)
{
	int	i;
	int	j;
	int	r;
	int	c;
	int	*marr;

	marr = _mtx_arr(mtx);
	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			*(int *)_mtx_idx(marr, mtx->strides, i, j) = ft_randint(min, range);
	}
}

// Creates <n x m> array of random float nbs in range [0, 1]
t_mtx	*mtx_random(int rows, int cols, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (!ret)
	{
		ret = mtx_create_empty(rows, cols, DTYPE_F);
		if (!ret)
			return (MTX_ERROR("malloc error"));
	}
	if (!((ret->shape[0] == rows) && (ret->shape[1] == cols))
		|| (ret->dtype != DTYPE_F))
		return (MTX_ERROR(" mismatch output shape/dtype"));
	__mtx_fill_random(ret);
	return (ret);
}

// Creates <n x m> array of random int nbs in argument range.
t_mtx	*mtx_randint(int rows, int cols, int limits[2], t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (!ret)
	{
		ret = mtx_create_empty(rows, cols, DTYPE_I);
		if (!ret)
			return (MTX_ERROR(" malloc error"));
	}
	if (!((ret->shape[0] == rows) && (ret->shape[1] == cols))
		|| (ret->dtype != DTYPE_I))
		return (MTX_ERROR("mismatch output shape/dtype"));
	if (limits[0] > limits[1])
		ft_swap_i(limits, limits + 1);
	__mtx_fill_randint(ret, limits[0], limits[1] - limits[0]);
	return (ret);
}
