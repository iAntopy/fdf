
#include "mtxlib.h"

static void	__mtx_setup_1d(t_mtx *mtx, int rows, int cols, size_t stride)
{
	mtx->ndims = (unsigned char)1;
	mtx->shape[0] = (rows > 1) * rows + (cols > 1) * cols;
	mtx->shape[1] = 1;
	mtx->strides[0] = stride;
	mtx->strides[1] = 0;
	mtx->is_view = 0;
}

static void	__mtx_setup_2d(t_mtx *mtx, int rows, int cols, size_t stride)
{	
	mtx->ndims = (unsigned char)2;
	mtx->shape[0] = rows;
	mtx->shape[1] = cols;
	mtx->strides[1] = stride;
	mtx->strides[0] = cols * stride;
	mtx->is_view = 0;
}

t_mtx	*mtx_create_empty(int rows, int cols, int dtype)
{
	t_mtx	*mtx;
	size_t	dsize;

	if (rows < 1 || cols < 1 || !(dtype == DTYPE_I || dtype == DTYPE_F))
	{
		perror("mtx_creat_empty : Invalid inputs ");
		return (NULL);
	}
	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)((rows > 1) + (cols > 1));
	dsize = get_dsize(dtype);
	mtx->dtype = dtype;
	mtx->arr = NULL;
	mtx->swap = NULL;
	if (rows == 1 || cols == 1)
		__mtx_setup_1d(mtx, rows, cols, dsize);
	else
		__mtx_setup_2d(mtx, rows, cols, dsize);
	if (!malloc_free_p(dsize * rows * cols, (void **)&(mtx->arr)))
		return (malloc_free(0, (void **)&mtx));
	mtx->swap = NULL;
	return (mtx);
}

t_mtx	*mtx_create_zeros(int rows, int cols, int dtype)
{
	t_mtx		*mtx;
	size_t		zero;

	zero = 0;
	mtx = mtx_create_empty(rows, cols, dtype);
	if (!mtx)
		return (NULL);
	mtx_fill(mtx, &zero);
	return (mtx);
}

t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype)
{
	t_mtx		*mtx;

	if (!arr)
		return (NULL);
	mtx = mtx_create_empty(rows, cols, dtype);
	if (!mtx)
		return (NULL);
	if (!mtx_init_as_array(mtx, arr, rows, cols))
	{
		mtx_clear(&mtx);
		return (fperror("mtx_create_array : failed to cpy arr data"));
	}
	return (mtx);
}
