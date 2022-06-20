#include "mtxlib.h"

int	mtx_index_is_inbound(t_mtx *mtx, int row, int col)
{
	return (row >= 0 && col >= 0
		&& row < mtx->shape[0] && col < mtx->shape[1]);
}

void	*_mtx_idx(t_mtx *mtx, int row, int col)
{
	return (mtx->arr + (mtx->strides[0] * row) + (mtx->strides[1] * col));
}

void	*mtx_index(t_mtx *mtx, int row, int col)
{
	if (row < 0 || col < 0 || row >= mtx->shape[0] || col >= mtx->shape[1])
		return (fperror("mtx_index : index out of bounds\n"));
	return (_mtx_idx(mtx, row, col));
}
