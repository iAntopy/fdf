#include "mtxlib.h"

static void	__apply_trig_func(float *a, float *b, size_t n_elems, float (*func)(float))
{
	while (n_elems--)
		*(a++) = (float)func(*(b++));
}

static t_mtx	*__apply_trig(t_mtx *mtx, float (*func)(float))
{
	t_mtx	*res;

	if (!mtx || mtx->dtype != DTYPE_F)
		return (fperror("mtx_trig : no input mtx or mtx->dtype != FLOAT"));
	res = mtx_dup_empty(mtx, DTYPE_F);
	if (!res)
		return (fperror("mtx_trig : malloc error"));
	__apply_trig_func(res->arr, mtx->arr, res->shape[0] * res->shape[1], func);
	return (res);
}

t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float))
{
	return (__apply_trig(mtx, func));
}
