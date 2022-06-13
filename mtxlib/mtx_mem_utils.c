
#include "mtxlib.h"

int	malloc_free_p(size_t size, void **ptr)
{
	if (size)
	{
		printf("malloc size %zu\n", size);
		*ptr = malloc(size);
		return (ptr != NULL);
	}
	else if (*ptr)
	{
		printf("free ptr %p\n", *ptr);
		free(*ptr);
		*ptr = NULL;
	}
	return (1);
}

void	*malloc_free(size_t size, void **ptr)
{
	if (size)
	{
		printf("malloc size %zu\n", size);
		*ptr = malloc(size);
		if (ptr)
			return (ptr);
	}
	else if (*ptr)
	{
		printf("free ptr %p\n", *ptr);
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);

}

void	mtx_clear(t_mtx **mtx)
{
	if (!(mtx && *mtx))
		return ;
	if ((*mtx)->arr)
		malloc_free_p(0, (void **)&((*mtx)->arr));
	malloc_free_p(0, (void **)mtx);
	*mtx = NULL;
}
