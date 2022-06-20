#include "mtxlib.h"

void	_mtx_isubf_mtx(t_mtx *m1, t_mtx *m2)
{
	int	r;
	int	c;
	int	i;
	int	j;
	float	elem;

	r = m1->shape[0];
	c = m1->shape[1];
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			elem = *(float *)_mtx_idx(m2, i, j);
			*(float *)_mtx_idx(m1, i, j) -= elem;
		}
	}
}

void	_mtx_subf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out)
{
	int	i;
	int	j;
	float	*optr;
	float	elem;

	i = -1;
	while (++i < m1->shape[0])
	{
		j = -1;
		while (++j < m1->shape[1])
		{
			optr = (float *)_mtx_idx(out, i, j);
			elem = *(float *)_mtx_idx(m2, i, j);
			*optr = *(float *)_mtx_idx(m1, i, j) - elem;
		}
	}
}
