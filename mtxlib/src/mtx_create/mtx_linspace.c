#include "mtxlib.h"

t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end)
{
	t_mtx	*mtx;
	float	range;
	float	incr;
	int	i;
	float	*fptr;

	if (!n_divs || start == end)
		return (fperror("mtx_linspace : n_divs or range == 0"));
	n_divs += !!w_end;
	mtx = mtx_create_empty(n_divs, 1, DTYPE_F);
	if (!mtx)
		return (NULL);
	mtx_print(mtx);
	mtx_display_info(mtx);
	range = end - start;
	incr = range / (n_divs - !!w_end);
	i = -1;
	while (++i < n_divs)
	{
//		printf("linspace : i %d / %d, range %.03f, incr %.03f, (n_divs - !w_end) %d\n", i + 1, n_divs, range, incr, (n_divs - !w_end));
		fptr = mtx_index(mtx, i, 0);
		if (!fptr)
			return (mtx_clear(&mtx));
		*fptr = start;
		start += incr;
	}
	return (mtx);
}
