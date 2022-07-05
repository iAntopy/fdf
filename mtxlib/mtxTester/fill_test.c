

#include "mtxlib.h"
#include <stdio.h>

int	main()
{
	int	arr[5] = {1, 2, 3, 4, 5};
	t_mtx	*mtx;
	int		value = 99;
	float	valuef;

	mtx = mtx_create_array(arr, 5, 1, DTYPE_I);
	printf("fill test : Post creation matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	mtx_fill(mtx, &value);
	printf("fill test : Post fill matrix :\n");
	mtx_print(mtx);
	mtx_clear(&mtx);

	printf("\nNEW array [FLOAT] :\n");
	valuef = M_PI;
	printf("valuef : %f\n", valuef);
	mtx = mtx_identity(10, NULL, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);
	printf("fill with PI !!!\n");
	mtx_fill(mtx, &valuef);
	mtx_print(mtx);
	mtx_clear(&mtx);
	return (0);
}
