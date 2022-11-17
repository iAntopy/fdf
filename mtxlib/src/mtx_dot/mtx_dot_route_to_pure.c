/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_dot_route_to_pure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:09:11 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 21:46:50 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// These are the most efficient dot applies where none of the arrays are views.

void	_mtx_dot_nxn_ii_to_pure(t_dopp *dop)
{
	int	j;
	int	k;
	int	*a;
	int	*b;
	int	*s;

	a = (int *)dop->a;
	b = (int *)dop->b;
	s = (int *)dop->o;
	while ((dop->n)--)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(a++) * b[j * dop->l];
			a -= dop->m;
			b++;
			s++;
		}
		a += dop->m;
		b -= dop->l;
	}
}

void	_mtx_dot_nxn_ff_to_pure(t_dopp *dop)
{
	int		j;
	int		k;
	float	*a;
	float	*b;
	float	*s;

	a = (float *)dop->a;
	b = (float *)dop->b;
	s = (float *)dop->o;
	while ((dop->n)--)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(a++) * b[j * dop->l];
			a -= dop->m;
			b++;
			s++;
		}
		a += dop->m;
		b -= dop->l;
	}
}

void	_mtx_dot_nxn_fi_to_pure(t_dopp *dop)
{
	int		j;
	int		k;
	float	*a;
	int		*b;
	float	*s;

	a = (float *)dop->a;
	b = (int *)dop->b;
	s = (float *)dop->o;
	while ((dop->n)--)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(a++) * b[j * dop->l];
			a -= dop->m;
			b++;
			s++;
		}
		a += dop->m;
		b -= dop->l;
	}
}

void	_mtx_dot_nxn_if_to_pure(t_dopp *dop)
{
	int		j;
	int		k;
	int		*a;
	float	*b;
	float	*s;

	a = (int *)dop->a;
	b = (float *)dop->b;
	s = (float *)dop->o;
	while ((dop->n)--)
	{
		k = -1;
		while (++k < dop->l)
		{
			j = -1;
			*s = 0;
			while (++j < dop->m)
				*s += *(a++) * b[j * dop->l];
			a -= dop->m;
			b++;
			s++;
		}
		a += dop->m;
		b -= dop->l;
	}
}
