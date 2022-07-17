/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:07:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/12 18:57:47 by iamongeo         ###   ########.fr       */
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
	printf("[[%-49s]]\n", " ");
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26d%s\n", "ndims", mtx->ndims, FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26s%s\n", "dtype", (mtx->dtype == DTYPE_I)?"INT":"FLOAT", FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "FRMT_C"<"DATA_C"%3d"FRMT_C" x "DATA_C"%-3d"FRMT_C">%31s\n", "shape <n x m>",  mtx->shape[0], mtx->shape[1], FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "FRMT_C"("DATA_C"%3d"FRMT_C", "DATA_C"%-3d"FRMT_C" )%31s\n", "strides (r, c)", mtx->strides[0], mtx->strides[1], FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26p%s\n", "array at", _mtx_arr(mtx), FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26p%s\n", "swap at", mtx->swap, FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26s%s\n", "is transposed", mtx_istransposed(mtx)?"TRUE":"FALSE", FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26s%s\n", "is view", (mtx->is_view)?"TRUE":"FALSE", FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"	%-14s : "DATA_C"%-26zu%s\n", "offset", mtx->offset, FRAME_C"]]"FRAME_C);
	printf(FRAME_C"@@_________________________________________________@@\n"WHITE_C);
}
