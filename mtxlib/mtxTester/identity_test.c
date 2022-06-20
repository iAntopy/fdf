
#include "mtxlib.h"

int	main()
{
	t_mtx	*mtx;
	int	value = 99;

	mtx = mtx_identity(5, DTYPE_I);
	printf("eye test : Post creation identity matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);
//	printf("eye test : Post fill matrix :\n");
//	mtx_print(mtx);
	mtx_clear(&mtx);

	return (0);
}
