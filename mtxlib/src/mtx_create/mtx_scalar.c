
#include "mtxlib.h"

t_mtx	*mtx_scalar(void *s, int dtype)
{
	t_mtx	*mtx;

	mtx = mtx_create_empty(1, 1, dtype);
	if (!mtx)
		return (NULL);
	mtx->arr = s;
	return (mtx);
}
