#include "mtxlib.h"

void	_mtx_imuli_scalar(t_mtx *mtx, int sc)
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
			*(int *)_mtx_idx(mtx, i, j) *= sc;
	}
}

void	_mtx_muli_scalar(t_mtx *mtx, int sc, t_mtx *out)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	*optr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			optr = (int *)_mtx_idx(out, i, j);
			*optr = sc * (*(int *)_mtx_idx(mtx, i, j));
		}
	}
}

void	_mtx_imuli_line(t_mtx *mtx, t_mtx *line)
{
	int	r;
	int	c;
	int	i;
	int	j;
	int	elem;

	r = mtx->shape[0];
	c = mtx->shape[1];
	j = -1;
	while (++j < c)
	{
		i = -1;
		elem = *(int *)_mtx_idx(line, j, 0);
		while (++i < r)
			*(int *)_mtx_idx(mtx, i, j) *= elem;
	}
}

void	_mtx_muli_line(t_mtx *mtx, t_mtx *line, t_mtx *out)
{
	int	i;
	int	j;
	int	elem;
	int	*optr;

	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		elem = *(int *)_mtx_idx(line, j, 0);
		while (++i < mtx->shape[0])
		{
			optr = (int *)_mtx_idx(out, i, j);
			*optr = *(int *)_mtx_idx(mtx, i, j) * elem;
		}
	}
}
