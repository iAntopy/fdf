#include "mtxlib.h"

void	_mtx_iaddf_mtx(t_mtx *mtx, t_mtx *line)
{
	int	r;
	int	c;
	int	i;
	int	j;
	float	lptr;

	r = mtx->shape[0];
	c = mtx->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			lptr = *(float *)_mtx_idx(line, i, j);
			*(float *)_mtx_idx(mtx, i, j) += lptr;
		}
	}
}

void	_mtx_addf_mtx(t_mtx *mtx, t_mtx *line, t_mtx *out)
{
	int	i;
	int	j;
	float	*optr;

	i = -1;
	while (++i < mtx->shape[0])
	{
		j = -1;
		while (++j < mtx->shape[1])
		{
			optr = (float *)_mtx_idx(out, i, j);
			*optr = *(float *)_mtx_idx(line, i, j);
			*optr += *(float *)_mtx_idx(mtx, i, j);
		}
	}
}
