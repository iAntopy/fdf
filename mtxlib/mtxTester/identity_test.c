
#include "mtxlib.h"

int	main()
{
	t_mtx	*mtx;
	t_mtx	*res;
	float	v;

	v = 2;
	mtx = mtx_identity(5, NULL, DTYPE_F);
	printf("eye test : Post creation identity matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	res = mtx_dup_empty(mtx, NULL, DTYPE_F);
	printf("output array : \n");
	mtx_print(res);

	_mtx_mulf_pscalar(mtx, v, res);
	printf("eye test : Post mul matrix :\n");
	mtx_print(res);
	mtx_clear(&mtx);
	mtx_clear(&res);

	return (0);
}
