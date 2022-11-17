#include "mtxlib.h"

float	square_mtx[4][4] = {{0,0,0,0}, {0,1,0,0}, {1,1,0,0}, {1,0,0,0}};
//   (0,1 .____.(1,1)
//	  |    |
//   (0,0)!____!(1,0)

int	main()
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*out;

	mtx = mtx_create_array(square_mtx, 4, 4, DTYPE_F);
	eye = mtx_identity(4, DTYPE_F);
	out = mtx_create_empty(4, 4, DTYPE_F);

	printf("\nALL ARRAYS CREATED WITH SUCCESS\n");

	printf("Square coords :\n");
	mtx_print(mtx);
	printf("identity matrix :\n");
	mtx_print(eye);
	
	printf("init empty out : \n");
	mtx_print(out);

	_mtx_dotf_4x4_4x4(mtx->arr, eye->arr, out->arr);

	printf("RESULTS out : \n");
	mtx_print(out);

	mtx_clear(&mtx);
	mtx_clear(&eye);
	mtx_clear(&out);

	return (0);
}
