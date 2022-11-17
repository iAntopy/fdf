/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_dot_route_to_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:00:25 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 17:08:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_dot_nxn_ii_to_arr(t_dopp *dop)
{
	int	i;
	int	j;
	int	k;
	int	*s;

	s = (int *)dop->o;
	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(int *)_mtx_idx(dop->a, dop->as, i, j) * *(int *)_mtx_idx(dop->b, dop->bs, j, k);
			s++;
		}
	}
}

void	_mtx_dot_nxn_ff_to_arr(t_dopp *dop)
{
	int		i;
	int		j;
	int		k;
	float	*s;

	s = (float *)dop->o;
	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(float *)_mtx_idx(dop->a, dop->as, i, j) * *(float *)_mtx_idx(dop->b, dop->bs, j, k);
			s++;
		}
	}
}

void	_mtx_dot_nxn_fi_to_arr(t_dopp *dop)
{
	int		i;
	int		j;
	int		k;
	float	*s;

	s = (float *)dop->o;
	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(float *)_mtx_idx(dop->a, dop->as, i, j) * *(int *)_mtx_idx(dop->b, dop->bs, j, k);
			s++;
		}
	}
}

void	_mtx_dot_nxn_if_to_arr(t_dopp *dop)
{
	int		i;
	int		j;
	int		k;
	float	*s;

	s = (float *)dop->o;
	i = -1;
	while (++i < dop->n)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(int *)_mtx_idx(dop->a, dop->as, i, j) * *(float *)_mtx_idx(dop->b, dop->bs, j, k);
			s++;
		}
	}
}
