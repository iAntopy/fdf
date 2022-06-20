#include "mtxlib.h"

void	_mtx_risubf_scalar(float sc, t_mtx *mtx)
{
	int	r;
	int	c;
	int	i;
	int	j;
	float	*mptr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			mptr = (float *)_mtx_idx(mtx, i, j);
			*mptr *= -1;
			*mptr += sc;
		}
	}
}

void	_mtx_rsubf_scalar(float sc, t_mtx *mtx, t_mtx *out)
{
	int	r;
	int	c;
	int	i;
	int	j;
	float	*optr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			optr = (float *)_mtx_idx(out, i, j);
			*optr = sc - *(float *)_mtx_idx(mtx, i, j);
		}
	}
}

void	_mtx_risubf_line(t_mtx *line, t_mtx *mtx)
{
	int	i;
	int	j;
	float	elem;
	float	*mptr;

	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		elem = *(float *)_mtx_idx(line, j, 0);
		while (++i < mtx->shape[0])
		{
			mptr = (float *)_mtx_idx(mtx, i, j);
			*mptr *= -1;
			*mptr += elem;
		}
	}
}

void	_mtx_rsubf_line(t_mtx *line, t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	float	*optr;
	float	elem;

	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		elem = *(float *)_mtx_idx(line, j, 0);
		while (++i < mtx->shape[0])
		{
			optr = (float *)_mtx_idx(out, i, j);
			*optr = elem - *(float *)_mtx_idx(mtx, i, j);
		}
	}
}
