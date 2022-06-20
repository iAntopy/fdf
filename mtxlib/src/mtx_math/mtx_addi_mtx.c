/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_addi_mtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:24:12 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:29:55 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_iaddi_mtx(t_mtx *mtx, t_mtx *line)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	lptr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			lptr = *(int *)_mtx_idx(line, i, j);
			*(int *)_mtx_idx(mtx, i, j) += lptr;
		}
	}
}

void	_mtx_addi_mtx(t_mtx *mtx, t_mtx *line, t_mtx *out)
{
	int	i;
	int	j;
	int	*optr;

	i = -1;
	while (++i < mtx->shape[0])
	{
		j = -1;
		while (++j < mtx->shape[1])
		{
			optr = (int *)_mtx_idx(out, i, j);
			*optr = *(int *)_mtx_idx(line, i, j);
			*optr += *(int *)_mtx_idx(mtx, i, j);
		}
	}
}
