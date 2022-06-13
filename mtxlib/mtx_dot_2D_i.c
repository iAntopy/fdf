#include "mtxlib.h"

/*
int	mtx_valid_t(t_mtx *mtx, int mtx_type)
{
	return (mtx->dtype == mtx_type);
}

int	mtx_valid_shp(t_mtx *mtx, int ndims, int rows, int cols)
{
	if (ndims != mtx->ndims)
		return (0);
	if (ndims == 1 && mtx->shape[0] != rows)
		return (0);
	else if (ndims == 2 && (mtx->shape[0] != rows
		|| mtx->shape[1] != cols))
		return (0);
	return (1);
}
*/
int	__mtx_dot_22o22(int *a1, int *a2, int *out)
{
	out[0] = a1[0] * a2[0] + a1[1] * a2[2];
	out[1] = a1[0] * a2[1] + a1[1] * a2[3];
	out[2] = a1[2] * a2[0] + a1[3] * a2[2];
	out[3] = a1[2] * a2[1] + a1[3] * a2[3];
	return (1);
}

int	__mtx_dot_n2o22(int *a1, int *a2, int n, int *out)
{
	int	i;
	int	off;

	i = -1;
	while (++i < n)
	{
		off = i * 2;
		out[off] = a1[off] * a2[0] + a1[off + 1] * a2[2];
		out[off + 1] = a1[off] * a2[1] + a1[off + 1] * a2[3];
	}
	return (1);
}
