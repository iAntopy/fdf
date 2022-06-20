
#include "mtxlib.h"

t_mtx	*mtx_transpose(t_mtx *mtx)
{
	if (mtx->ndims == 1)
		return (NULL);
	ft_swap_i(&mtx->shape[0], &mtx->shape[1]);
	ft_swap_i(&mtx->strides[0], &mtx->strides[1]);
	return (mtx);
}
/*
int	main()
{
	t_mtx	*mtx;

	mtx = mtx_identity(5, DTYPE_I);
	mtx_print(mtx);
	mtx_clear(&mtx);
	return (0);
}
*/
