#include "mtxlib.h"

void	_mtx_iaddf_scalar(t_mtx *mtx, float sc)
{
	int	r;
	int	c;
	int	i;
	int	j;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			*(float *)_mtx_idx(mtx, i, j) += sc;
	}
}

void	_mtx_addf_scalar(t_mtx *mtx, float sc, t_mtx *out)
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
			*optr = sc + *(float *)_mtx_idx(mtx, i, j);
		}
	}
}

void	_mtx_iaddf_line(t_mtx *mtx, t_mtx *line)
{
	int	r;
	int	c;
	int	i;
	int	j;
	float	elem;

	r = mtx->shape[0];
	c = mtx->shape[1];
	j = -1;
	while (++j < c)
	{
		i = -1;
		elem = *(float *)_mtx_idx(line, j, 0);
		while (++i < r)
			*(float *)_mtx_idx(mtx, i, j) += elem;
	}
}

void	_mtx_addf_line(t_mtx *mtx, t_mtx *line, t_mtx *out)
{
	int	i;
	int	j;
	float	elem;
	float	*optr;

	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		elem = *(float *)_mtx_idx(line, j, 0);
		while (++i < mtx->shape[0])
		{
			optr = (float *)_mtx_idx(out, i, j);
			*optr += *(float *)_mtx_idx(mtx, i, j) + elem;
		}
	}
}
