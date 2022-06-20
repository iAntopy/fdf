/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:53:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 18:52:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

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
	int	r;
	int	c;
	int	i;
	int	j;

	r = m->shape[0];
	c = m->shape[1];
	i = -1;
	if (dsize == sizeof(U_INT))
		while (++i < r && __reset_j(&j))
			while (++j < c)
				*(U_INT *)_mtx_idx(m, i, j) = *(U_INT *)value;
	else if (dsize == sizeof(size_t))
		while (++i < r && __reset_j(&j))
			while (++j < c)
				*(size_t *)_mtx_idx(m, i, j) = *(size_t *)value;
	else if (dsize == sizeof(U_CHAR))
		while (++i < r && __reset_j(&j))
			while (++j < c)
				*(U_CHAR *)_mtx_idx(m, i, j) = *(U_CHAR *)value;
}

//fills matrix with the value pointed by void *. The size of the 
//value to copy is derived from the matrix dtype.
void	mtx_fill(t_mtx *mtx, void *value)
{
	size_t	dsize;

	dsize = get_dsize(mtx->dtype);
	if (mtx->is_view)
		__mtx_fill_view(mtx, value, dsize);
	else
		__mtx_fill(mtx->arr, value, dsize, mtx->shape[0] * mtx->shape[1]);
}
