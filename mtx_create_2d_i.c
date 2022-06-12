
#include "mtxlib.h"

t_mtx	*mtx_create_1x2_i(int arr[2])
{
	t_mtx	*mtx;
	int	*marr;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	
	mtx->ndims = (unsigned char)1;
	mtx->dtype = DTYPE_I;
	mtx->shape[0] = 2;
	mtx->strides[0] = sizeof(int);

	if (!malloc_free_p(sizeof(int) * 2, (void **)&marr))
		return ((void *)(0 * malloc_free_p(0, (void **)&mtx)));
	marr[0] = arr[0];
	marr[1] = arr[1];
	return (mtx);
}

t_mtx	*mtx_create_2x2_i(int arr[2][2])
{
	t_mtx	*mtx;
	int	*marr;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	
	mtx->ndims = (unsigned char)2;
	mtx->dtype = DTYPE_I;
	mtx->shape[0] = 2;
	mtx->shape[1] = 2;
	mtx->strides[1] = sizeof(int);
	mtx->strides[0] = 2 * mtx->strides[1];

	if (!malloc_free_p(sizeof(int) * 4, (void **)&arr))
		return ((t_mtx *)(0 * malloc_free_p(0, (void **)&mtx)));
	marr[0] = arr[0][0];
	marr[1] = arr[0][1];
	marr[2] = arr[1][0];
	marr[3] = arr[1][1];
	mtx->arr = marr;
	return (mtx);
}

t_mtx	*mtx_create_nx2_i(int n, int *arr[2])
{
	t_mtx	*mtx;
	int	*marr;
	int	i;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)2;
	mtx->dtype = DTYPE_I;
	mtx->shape[0] = n;
	mtx->shape[1] = 2;
	mtx->strides[1] = sizeof(int);
	mtx->strides[0] = 2 * sizeof(int);
	if (!malloc_free_p(sizeof(int) * n * 2, (void **)&marr))
		return ((t_mtx *)(0 * malloc_free_p(0, (void **)&mtx)));
	i = -1;
	while (++i < n)
	{
		marr[2 * i] = arr[i][0];
		marr[2 * i + 1] = arr[i][1];
	}
	mtx->arr = marr;
	return (mtx);
}
