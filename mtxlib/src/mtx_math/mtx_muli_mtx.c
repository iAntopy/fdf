/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_muli_mtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:23:57 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:30:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_imuli_mtx(t_mtx *m1, t_mtx *m2)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	lptr;

	r = m1->shape[0];
	c = m1->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			lptr = *(int *)_mtx_idx(m2, i, j);
			*(int *)_mtx_idx(m1, i, j) *= lptr;
		}
	}
}

void	_mtx_muli_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out)
{
	int	i;
	int	j;
	int	*optr;

	i = -1;
	while (++i < m1->shape[0])
	{
		j = -1;
		while (++j < m1->shape[1])
		{
			optr = (int *)_mtx_idx(out, i, j);
			*optr = *(int *)_mtx_idx(m1, i, j);
			*optr *= *(int *)_mtx_idx(m2, i, j);
		}
	}
}
