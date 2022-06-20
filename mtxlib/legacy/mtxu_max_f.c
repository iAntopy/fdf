#include "mtxlib.h"

static float	mtxu_max_1D_f(t_mtx *mtx)
{
	int	i;
	int	n;
	float	high;

	n = mtx->shape[0];
	high = FLT_MIN;
	i = -1;
	while (++i < n)
		if (mtx->arr[i] > high)
			high = mtx->arr[i];
	return (high);
}

static float	mtxu_max_2D_f(t_mtx *mtx)
{
	int	i;
	int	n;
	float	high;

	n = mtx->shape[0] * mtx->shape[1];
	high = FLT_MIN;
	i = -1;
	while (++i < n)
		if (mtx->arr[i] > high)
			high = mtx->arr[i];
	return (high);
}

float	mtxu_max_i(t_mtx *mtx)
{
	if (mtx->ndims == 1)
		return (mtxu_max_1D_f(mtx));
	else if (mtx->ndims == 2)
		return (mtxu_max_2D_f(mtx));
}
