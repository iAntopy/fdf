
#include "mtxlib.h"

void	mtx_display_info(t_mtx *mtx)
{
	if (!mtx)
		return ;
	printf("@@_________ Matrix info (%p) ________@@\n", mtx);
	printf("[[\n");
	printf("[[	ndims : %d\n", mtx->ndims);
	printf("[[	dtype : %s\n", (mtx->dtype == DTYPE_I)?"INT":"FLOAT");
	printf("[[	shape : <%d x %d>\n", mtx->shape[0], mtx->shape[1]);
	printf("[[	strides: r %d, c %d\n", mtx->strides[0], mtx->strides[1]);
	printf("[[	array at : %p\n", mtx->arr);
	printf("[[	swap at : %p\n", mtx->swap);
	printf("[[	is transposed : %s\n", (mtx->strides[0] < mtx->strides[1])?"TRUE":"FALSE");
	printf("[[	is view : %s\n", (mtx->is_view)?"TRUE":"FALSE");
	printf("@@_______________________________________________@@\n");
}
