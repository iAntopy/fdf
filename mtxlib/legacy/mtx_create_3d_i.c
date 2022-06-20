#include "mtxlib.h"

t_mtx	*mtx_create_1x3_i(int arr[3])
{
	t_mtx	*mtx;
	int	*marr;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	
	mtx->ndims = (unsigned char)1;
	mtx->dtype = MTX_TYPE_INT;
	mtx->strides[0] = sizeof(int);

	if (!malloc_free_p(sizeof(int) * 3, (void **)&marr)
		return ((void *)(0 * malloc_free_p(0, (void **)&mtx)));
	marr[0] = arr[0];
	marr[1] = arr[1];
	marr[2] = arr[2];
	return (mtx);
}

t_mtx	*mtx_create_3x3_i(int arr[3][3])
{
	t_mtx	*mtx;
	int	*marr;
	int	i;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)2;
	mtx->dtype = MTX_TYPE_INT;
	mtx->shape[1] = 3;
	mtx->shape[0] = 3;
	mtx->strides[1] = sizeof(int);
	mtx->strides[0] = 3 * sizeof(int);
	if (!malloc_free_p(sizeof(int) * 9, (void **)&marr))
		return ((void *)(0 * malloc_free_p(0, (void **)&mtx)));
	i = -1;
	while (++i < 3)
	{
		marr[i * 3] = arr[i][0];
		marr[i * 3 + 1] = arr[i][2];
		marr[i * 3 + 2] = arr[i][3];
	}
	mtx->arr = marr;
	return (mtx);
}

t_mtx	*mtx_create_nx3_i(int *arr[3])
{
	t_mtx	*mtx;
	int	*marr;
	int	i;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)2;
	mtx->dtype = MTX_TYPE_INT;
	mtx->shape[0] = n;
	mtx->shape[1] = 3;
	mtx->strides[0] = 3 * sizeof(int);
	mtx->strides[1] = sizeof(int);
	if (!malloc_free_p(sizeof(int) * n * 3, (void **)&marr))
		return ((void *)(0 * malloc_free_p(0, (void **)&mtx)));
	i = -1;
	while (++i < n)
	{
		marr[i * 3] = arr[i][0];
		marr[i * 3 + 1] = arr[i][1];
		marr[i * 3 + 2] = arr[i][2];
	}
	mtx->arr = marr;
	return (mtx)
}
