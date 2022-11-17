/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:53:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/14 21:43:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

// Does NOT work with views, Very fast.
t_mtx	*__mtx_fill_zeros(t_mtx *mtx)
{
	ft_memclear(mtx->arr, mtx_sizeof_array(mtx));
	return (mtx);
}
/*
	arr = mtx->arr;
	while (arr_size > sizeof(size_t))
	{
		*(arr++) = 0;
		arr_size -= sizeof(size_t);
	}
	carr = (char *)arr;
	while (arr_size--)
		*(carr++) = 0;

	return (mtx);
}
*/

t_mtx	*_mtx_fill_zeros(t_mtx *mtx)
{
	int	i;
	int	j;
	int	*arr;

	if (mtx_get_dsize(mtx->dtype) != 4)
		return (MTX_ERROR("Can't fill mtx with dsize other then 4"));
	arr = _mtx_arr(mtx);
	i = -1;
	while (++i < mtx->shape[0])
	{
		j = -1;
		while (++j < mtx->shape[1])
			*(int *)_mtx_idx(arr, mtx->strides, i, j) = 0;
	}
	return (mtx);
}

static void	__mtx_fill(void *a, void *v, size_t dsize, size_t n_elems)
{
	U_CHAR	*carr;
	U_INT	*iarr;
	size_t	*sarr;

	if (dsize == sizeof(U_INT))
	{
		iarr = (U_INT *)a;
		while (n_elems--)
			*(iarr++) = *(U_INT *)v;
	}
	else if (dsize == sizeof(U_CHAR))
	{
		carr = (U_CHAR *)a;
		while (n_elems--)
			*(carr++) = *(U_CHAR *)v;
	}
	else if (dsize == sizeof(size_t))
	{
		sarr = (size_t *)a;
		while (n_elems--)
			*(sarr++) = *(size_t *)v;
	}
}

static int	__reset_j(int *j)
{
	*j = -1;
	return (1);
}

static void	__mtx_fill_view(t_mtx *m, void *value, size_t dsize)
{
	int		r;
	int		c;
	int		i;
	int		j;
	void	*arr;

	r = m->shape[0];
	c = m->shape[1];
	i = -1;
	arr = _mtx_arr(m);
	if (dsize == sizeof(U_INT))
		while (++i < r && __reset_j(&j))
			while (++j < c)
				*(U_INT *)_mtx_idx(arr, m->strides, i, j) = *(U_INT *)value;
	else if (dsize == sizeof(size_t))
		while (++i < r && __reset_j(&j))
			while (++j < c)
				*(size_t *)_mtx_idx(arr, m->strides, i, j) = *(size_t *)value;
	else if (dsize == sizeof(U_CHAR))
		while (++i < r && __reset_j(&j))
			while (++j < c)
				*(U_CHAR *)_mtx_idx(arr, m->strides, i, j) = *(U_CHAR *)value;
}

//fills matrix with the value pointed by void *. The size of the 
//value to copy is derived from the matrix dtype.
t_mtx	*mtx_fill(t_mtx *mtx, void *value)
{
	size_t	dsize;

	if (!mtx || !value)
		return (MTX_ERROR("missing params"));
	dsize = mtx_get_dsize(mtx->dtype);
	if (mtx->is_view)
	{
		if ((dsize == 4) && (*(int *)value == 0))
			_mtx_fill_zeros(mtx);
		else
			__mtx_fill_view(mtx, value, dsize);
	}
	else
	{
		if ((dsize == 4) && (*(int *)value == 0))
			__mtx_fill_zeros(mtx);
		else
			__mtx_fill(mtx->arr, value, dsize, mtx_get_nb_elems(mtx));
	}
	return (mtx);
}
