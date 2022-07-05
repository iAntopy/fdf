/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:07:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 19:46:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

#define TITLE_C YELLOW_BC
#define FRAME_C BLUE_BC
#define SUB_C CYAN_BC
#define DATA_C WHITE_BC
#define FRMT_C PURPLE_BC

void	mtx_display_info(t_mtx *mtx)
{
	if (!mtx)
		return ;
	printf(FRAME_C"@@_________[ "TITLE_C"Matrix info (%p)"FRAME_C" ]________@@\n", mtx);
	printf("[[\n");
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%d\n", "ndims", mtx->ndims);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%s\n", "dtype", (mtx->dtype == DTYPE_I)?"INT":"FLOAT");
	printf(FRAME_C"[["SUB_C"	%-14s : "FRMT_C"<"DATA_C"%d"FRMT_C" x "DATA_C"%d"FRMT_C">\n", "shape <n x m>",  mtx->shape[0], mtx->shape[1]);
	printf(FRAME_C"[["SUB_C"	%-14s : "FRMT_C"("DATA_C"%d"FRMT_C", "DATA_C"%d"FRMT_C")\n", "strides (r, c)", mtx->strides[0], mtx->strides[1]);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%p\n", "array at", mtx->arr);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%p\n", "swap at", mtx->swap);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%s\n", "is transposed", mtx_istransposed(mtx)?"TRUE":"FALSE");
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%s\n", "is view", (mtx->is_view)?"TRUE":"FALSE");
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%zu\n", "offset", mtx->offset);
	printf(FRAME_C"@@_________________________________________________@@\n"WHITE_C);
}
