#include "mtxlib.h"

float	_mtx_dotf_1D_1D(t_mtx *m1, t_mtx *m2)
{
	float	res;
	float	*ma1;
	float	*ma2;
	size_t	n_elems;

	res = 0;
	ma1 = (float *)m1->arr;
	ma2 = (float *)m2->arr;
	n_elems = m1->shape[0];
	while (n_elems--)
		res += (*(ma1++)) * (*(ma2++));
	return (res);
}

float	_mtx_dotf_1x2_1x2(t_mtx *m1, t_mtx *m2)
{
	return (((float *)m1->arr)[0] * ((float *)m2->arr)[0]
		+ ((float *)m1->arr)[1] * ((float *)m2->arr)[1]);
}

float	_mtx_dotf_1x3_1x3(t_mtx *m1, t_mtx *m2)
{
	return (((float *)m1->arr)[0] * ((float *)m2->arr)[0]
		+ ((float *)m1->arr)[1] * ((float *)m2->arr)[1]
		+ ((float *)m1->arr)[2] * ((float *)m2->arr)[2]);
}

float	_mtx_dotf_1x4_1x4(t_mtx *m1, t_mtx *m2)
{
	float	*ma1;
	float	*ma2;

	ma1 = (float *)m1->arr;
	ma2 = (float *)m2->arr;
	return (ma1[0] * ma2[0] + ma1[1] * ma2[1]
		+ ma1[2] * ma2[2] + ma1[3] + ma2[3]);
}

float	mtx_dotf_1D_1D(t_mtx *m1, t_mtx *m2)
{
	if (!mtx_isvalid_broadcast_dot(m1, m2))
		return (0);
	else if (!((m1->shape[0] == 1) && (m2->shape[0] == 1))
		|| (m1->dtype != DTYPE_F))
	{
		fperror("mtx_dotf_1D_1D : mtx not 1D or not DTYPE_F");
		return (0);
	}
	return (_mtx_dotf_1D_1D(m1, m2));
}
