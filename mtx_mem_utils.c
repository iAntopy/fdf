
#include "mtxlib.h"

int	malloc_free_p(size_t size, void **ptr)
{
	if (size)
	{
		*ptr = malloc(size);
		return (ptr != NULL);
	}
	else if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (1);
}

void	mtx_clear(t_mtx *mtx)
{
	malloc_free_p(0, (void **)mtx->arr);
	malloc_free_p(0, (void **)mtx);
}
