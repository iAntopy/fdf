#include "mtxlib.h"

int	mtx_dot_12o12(t_mtx *m1, t_mtx *m2, int *out)
{
	out = m1->arr[0] * m2->arr[0] + m1->arr[1] * m2->arr[1];
	return (1);
}
