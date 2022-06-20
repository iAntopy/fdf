/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rdivi_scalar_and_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:22:18 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:29:05 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_ridivi_scalar(int sc, t_mtx *mtx)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	*mptr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			mptr = (int *)_mtx_idx(mtx, i, j);
			*mptr = sc / *mptr;
		}
	}
}

void	_mtx_rdivi_scalar(int sc, t_mtx *mtx, t_mtx *out)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	*optr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			optr = (int *)_mtx_idx(out, i, j);
			*optr = sc / *(int *)_mtx_idx(mtx, i, j);
		}
	}
}

void	_mtx_ridivi_line(t_mtx *line, t_mtx *mtx)
{
	int	i;
	int	j;
	int	elem;
	int	*mptr;

	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		elem = *(int *)_mtx_idx(line, j, 0);
		while (++i < mtx->shape[0])
		{
			mptr = (int *)_mtx_idx(mtx, i, j);
			*mptr = elem / *mptr;
		}
	}
}

void	_mtx_rdivi_line(t_mtx *line, t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	*optr;
	int	elem;

	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		elem = *(int *)_mtx_idx(line, j, 0);
		while (++i < mtx->shape[0])
		{
			optr = (int *)_mtx_idx(out, i, j);
			*optr = elem / *(int *)_mtx_idx(mtx, i, j);
		}
	}
}
