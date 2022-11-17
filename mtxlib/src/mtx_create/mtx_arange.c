
#include "mtxlib.h"

static void	fill_arange_i(int *arr, int start, int end, int incr)
{
	while (start != end)
	{
		*(arr++) = start;
		start += incr;
	}
}

static void	fill_arange_f(float *arr, int start, int end, int incr)
{
	while (start != end)
	{
		*(arr++) += start;
		start += incr;
	}
}

t_mtx	*mtx_arange(int	a, int b, int dtype)
{
	t_mtx	*mtx;
	ssize_t	range;
	int	incr;

	range = b - a;
	incr = 1 - (2 * (range < 0));
	range *= incr;
	if (!(dtype == DTYPE_I || dtype == DTYPE_F) || (range > INT_MAX))
		return (NULL);	
	mtx = mtx_create_zeros(range, 1, dtype);
	if (!mtx)
		return (NULL);
	if (dtype == DTYPE_I)
		fill_arange_i(mtx->arr, a, b, incr);
	else if (dtype == DTYPE_F)
		fill_arange_f(mtx->arr, a, b, incr);
	return (mtx);
}
