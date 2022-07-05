#include "mtxlib.h"

float	arr[4][4] = {{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3}};

int	main()
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*out;
	ssize_t	total_time;
	int	iters = 1000000;
	double	t_time = 1;
	int	i;

	eye = mtx_identity(4, NULL, DTYPE_F);
	mtx = mtx_create_array(arr, 4, 4, DTYPE_F);
	out = mtx_create_empty(4, 4, DTYPE_F);
	_mtx_imulf_pscalar(eye, 2);

	i = -1;
	ft_timedelta_usec(NULL);
	while (++i < iters)
		__mtx_dotf_nx4_4x4(4, mtx->arr, eye->arr, out->arr);
	total_time = ft_timedelta_usec(NULL);//("executing mtx_dotf_4x4_4x4");
	printf("Total exec time for %d iterations : %zd\n", iters, total_time);
	t_time *= total_time;
	t_time /= iters;
	printf("Each iterations took %lf usec\n", t_time);

	printf("init matrix : \n");
	mtx_print(mtx);
//	mtx_display_info(mtx);
	printf("identity x2 matrix : \n");
	mtx_print(eye);
//	mtx_display_info(eye);
	printf("mtx dot eye : \n");
	mtx_print(out);
//	mtx_display_info(out);


	mtx_clear_list(3, mtx, eye, out);
	return (0);
}
