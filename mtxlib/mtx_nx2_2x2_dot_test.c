
#include "mtxlib.h"

int ARR_2X2[2][2] = 	{{2, 0},
			 {0, 2}};

int ARR_NX2[5][2] = 	{{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5}};

int	main()
{
	t_mtx	*m1;
	t_mtx	*m2;

	m1 = mtx_create_nx2_i(5, ARR_NX2);
	m2 = mtx_create_2x2_i(ARR_2X2);

	mtx_clear(m1);
	mtx_clear(m2);

	return (0);
}
