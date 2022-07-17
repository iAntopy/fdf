/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_dot_route_to_view.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:01:20 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 21:48:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_dot_nxn_ii_to_view(t_dopp *dop)
{
	int	i;
	int	j;
	int	k;
	int	*s;

	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			s = (int *)_mtx_idx(dop->o, dop->os, i, k);
			*s = 0;
			while (++j < dop->m)
				*s += *(int *)_mtx_idx(dop->a, dop->as, i, j) * *(int *)_mtx_idx(dop->b, dop->bs, j, k);
		}
	}
}

void	_mtx_dot_nxn_ff_to_view(t_dopp *dop)
{
	int		i;
	int		j;
	int		k;
	float	*s;

	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			s = (float *)_mtx_idx(dop->o, dop->os, i, k);
			*s = 0;
			while (++j < dop->m)
				*s += *(float *)_mtx_idx(dop->a, dop->as, i, j) * *(float *)_mtx_idx(dop->b, dop->bs, j, k);
		}
	}
}

void	_mtx_dot_nxn_fi_to_view(t_dopp *dop)
{
	int		i;
	int		j;
	int		k;
	float	*s;

	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			s = (float *)_mtx_idx(dop->o, dop->os, i, k);
			*s = 0;
			while (++j < dop->m)
				*s += *(float *)_mtx_idx(dop->a, dop->as, i, j) * *(int *)_mtx_idx(dop->b, dop->bs, j, k);
		}
	}
}

void	_mtx_dot_nxn_if_to_view(t_dopp *dop)
{
	int		i;
	int		j;
	int		k;
	float	*s;

	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			s = (float *)_mtx_idx(dop->o, dop->os, i, k);
			*s = 0;
			while (++j < dop->m)
				*s += *(int *)_mtx_idx(dop->a, dop->as, i, j) * *(float *)_mtx_idx(dop->b, dop->bs, j, k);
		}
	}
}
