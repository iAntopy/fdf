#include "mtxlib.h"

static int	mtxu_max_1D_i(t_mtx *mtx)
{
	int	i;
	int	n;
	int	high;

	n = mtx->shape[0];
	high = INT_MIN;
	i = -1;
	while (++i < n)
		if (mtx->arr[i] > high)
			high = mtx->arr[i];
	return (high);
}

static int	mtxu_max_2D_i(t_mtx *mtx)
{
	int	i;
	int	n;
	int	high;

	n = mtx->shape[0] * mtx->shape[1];
	high = INT_MIN;
	i = -1;
	while (++i < n)
		if (mtx->arr[i] > high)
			high = mtx->arr[i];
	return (high);
}

int	mtxu_max_i(t_mtx *mtx)
{
	if (mtx->ndims == 1)
		return (mtxu_max_1D_i(mtx));
	else if (mtx->ndims == 2)
		return (mtxu_max_2D_i(mtx));
}
