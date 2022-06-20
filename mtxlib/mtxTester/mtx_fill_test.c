#include "mtxlib.h"

int	main()
{
	t_mtx	*mtx;

	mtx = mtx_create_empty(4, 4, DTYPE_I);
	mtx_print(mtx);
	
	mtx_clear(&mtx);
	return (0);
}
