
#include "mtxlib.h"

int	main()
{
	t_mtx	*mtx;
	t_mtx	*mtx2;


	mtx = mtx_linspace(0, 10, 20, 1);
	mtx2 = mtx_linspace(0, 2 * M_PI, 8, 1);
	if (!mtx)
		return (1);
	mtx_print(mtx);
	mtx_display_info(mtx);
	mtx_print(mtx2);
	mtx_display_info(mtx2);
	mtx_clear(&mtx);
	mtx_clear(&mtx2);
	return (0);
}
