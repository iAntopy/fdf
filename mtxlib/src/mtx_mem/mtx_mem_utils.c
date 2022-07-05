
#include "mtxlib.h"

int	malloc_free_p(size_t size, void **ptr)
{
	if (size)
	{
//		printf("malloc size %zu\n", size);
		*ptr = malloc(size);
		return (ptr != NULL);
	}
	else if (*ptr)
	{
//		printf("free ptr %p\n", *ptr);
		free(*ptr);
		*ptr = NULL;
	}
	return (1);
}

void	*malloc_free(size_t size, void **ptr)
{
	if (size)
	{
//		printf("malloc size %zu\n", size);
		*ptr = malloc(size);
		if (ptr)
			return (ptr);
	}
	else if (*ptr)
	{
//		printf("free ptr %p\n", *ptr);
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);

}

size_t	mtx_get_dsize(int dtype)
{
	if (dtype == DTYPE_I)
		return (sizeof(int));
	else if (dtype == DTYPE_F)
		return (sizeof(float));
	return (0);
}

size_t	mtx_get_nb_elems(t_mtx *mtx)
{
	return (mtx->shape[0] * mtx->shape[1]);
}

size_t	mtx_sizeof_array(t_mtx *mtx)
{
	return (mtx_get_nb_elems(mtx) * mtx_get_dsize(mtx->dtype));
}
