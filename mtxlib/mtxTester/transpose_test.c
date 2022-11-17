#include "mtxlib.h"

int	init_arr[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

int	main()
{
	t_mtx	*mtx;

//	mtx = mtx_arange(5, -10, DTYPE_I);
	mtx = mtx_create_array(init_arr, 2, 5, DTYPE_I);
	if (!mtx)
		return (1);
	printf("Matrix created successfully\n");
	mtx_print(mtx);
	mtx_display_info(mtx);
	printf("First Transpose \n");	
	mtx_transpose(mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Second Transpose (Revert to original)\n");	
	mtx_transpose(mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);
	
	mtx_clear(&mtx);
	return (0);
}
