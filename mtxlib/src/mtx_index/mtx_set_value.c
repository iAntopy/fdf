/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_set_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:04:42 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/22 02:10:30 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_set_index_f(t_mtx *mtx, int row, int col, float value)
{
	float	*idx_p;

	idx_p = (float *)_mtx_idx(_mtx_arr(mtx), mtx->strides, row, col);
	*idx_p = value;
}

void	_mtx_set_index_i(t_mtx *mtx, int row, int col, int value)
{
	int	*idx_p;

	idx_p = (int *)_mtx_idx(_mtx_arr(mtx), mtx->strides, row, col);
	*idx_p = value;
}

void	mtx_set_index_f(t_mtx *mtx, int row, int col, float value)
{
	float	*idx_p;

	idx_p = (float *)mtx_index(mtx, row, col);
	if (!idx_p)
	{
		MTX_ERROR("index out of bounds");
		return ;
	}
	*idx_p = value;
}

void	mtx_set_index_i(t_mtx *mtx, int row, int col, int value)
{
	int	*idx_p;

	idx_p = (int *)mtx_index(mtx, row, col);
	if (!idx_p)
	{
		MTX_ERROR("index out of bounds");
		return ;
	}
	*idx_p = value;
}
