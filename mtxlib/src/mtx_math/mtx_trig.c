#include "mtxlib.h"

t_mtx	*mtx_sin(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, sinf, out));
}

t_mtx	*mtx_cos(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, cosf, out));
}

t_mtx	*mtx_tan(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, tanf, out));
}

t_mtx	*mtx_asin(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, asinf, out));
}

t_mtx	*mtx_aacos(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, acosf, out));
}
