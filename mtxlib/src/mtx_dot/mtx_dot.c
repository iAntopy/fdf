/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:00:42 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 19:00:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

void	_mtx_dot_nxn_ii(t_mtx *a, t_mtx *b, t_mtx *out)
{
	int	i;
	int j;
	int k;
	int	s;

	i = -1;
	while (++i < a->shape[0])
	{
		k = -1;
		while (++k < b->shape[1])
		{
			s = 0;
			j = -1;
			while (++j < a->shape[1])
				s += *(int *)_mtx_idx(a, i, j) * *(int *)_mtx_idx(b, j, k);
			*(int *)_mtx_idx(out, i, k) = s;
		}
	}
}

void	_mtx_dot_nxn_ff(t_mtx *a, t_mtx *b, t_mtx *out)
{
	int		i;
	int		j;
	int 	k;
	float	s;

	i = -1;
	while (++i < a->shape[0])
	{
		k = -1;
		while (++k < b->shape[1])
		{
			s = 0;
			j = -1;
			while (++j < a->shape[1])
				s += *(float *)_mtx_idx(a, i, j) * *(float *)_mtx_idx(b, j, k);
			*(float *)_mtx_idx(out, i, k) = s;
		}
	}
}

void	_mtx_dot_nxn_fi(t_mtx *a, t_mtx *b, t_mtx *out)
{
	int		i;
	int		j;
	int 	k;
	float	s;

	i = -1;
	while (++i < a->shape[0])
	{
		k = -1;
		while (++k < b->shape[1])
		{
			s = 0;
			j = -1;
			while (++j < a->shape[1])
				s += *(float *)_mtx_idx(a, i, j) * *(int *)_mtx_idx(b, j, k);
			*(float *)_mtx_idx(out, i, k) = s;
		}
	}
}

void	_mtx_dot_nxn_if(t_mtx *a, t_mtx *b, t_mtx *out)
{
	int		i;
	int		j;
	int 	k;
	float	s;

	i = -1;
	while (++i < a->shape[0])
	{
		k = -1;
		while (++k < b->shape[1])
		{
			s = 0;
			j = -1;
			while (++j < a->shape[1])
				s += *(int *)_mtx_idx(a, i, j) * *(float *)_mtx_idx(b, j, k);
			*(float *)_mtx_idx(out, i, k) = s;
		}
	}
}

t_mtx	*mtx_dot(t_mtx *a, t_mtx *b, t_mtx **out)
{
	t_mtx	*ret;

	ret = NULL;
	printf("mtx_dot : START\n");
	printf("mtx_dot : input matrices : \n");
	mtx_print(a);
	mtx_print(b);
	if ((out && !mtx_isvalid_broadcast_to_dot(a, b, *out))
		|| (!out && !mtx_isvalid_broadcast_dot(a, b)))
		return (NULL);
	if (!out)
		ret = mtx_create_empty(a->shape[0], b->shape[1], mtx_dtype_out(a, b));
	else if (*out == a || *out == b)
		return (fperror("mtx_dot : out mtx == a or b input. TODO: allow == a"));
	else
		ret = *out;
	printf("mtx_dot : ret matrix collected (%p)\n", ret);
	if (a->dtype == DTYPE_F && b->dtype == DTYPE_F)
		_mtx_dot_nxn_ff(a, b, ret);
	else if (a->dtype == DTYPE_I && b->dtype == DTYPE_I)
		_mtx_dot_nxn_ii(a, b, ret);
	else if (a->dtype == DTYPE_F && b->dtype == DTYPE_I)
		_mtx_dot_nxn_fi(a, b, ret);
	else if (a->dtype == DTYPE_I && b->dtype == DTYPE_F)
		_mtx_dot_nxn_if(a, b, ret);
	return (ret);
}
