
#include "mtxlib.h"

static void	fill_identity_i(t_mtx *mtx)
{
	int	i;

	i = -1;
	while (++i < mtx->shape[0])
		*(int *)mtx_index(mtx, i, i) = 1;
}

static void	fill_identity_f(t_mtx *mtx)
{
	int	i;

	i = -1;
	while (++i < mtx->shape[0])
		*(float *)mtx_index(mtx, i, i) = 1;
}

t_mtx	*mtx_identity(int n, int dtype)
{
	t_mtx	*mtx;

	if (n < 1)
		return ((t_mtx *)fperror("mtx_identity : %d is invalid n", n));
	mtx = mtx_create_zeros(n, n, dtype);
	if (!mtx)
		return (NULL);
	if (dtype == DTYPE_I)
		fill_identity_i(mtx);
	else if (dtype == DTYPE_F)
		fill_identity_f(mtx);
	return (mtx);
}
/*
int	main()
{
	t_mtx	*mtx;

	mtx = mtx_identity(3, DTYPE_I);
	mtx_print(mtx);
	mtx_clear(&mtx);
	return (0);
}*/
