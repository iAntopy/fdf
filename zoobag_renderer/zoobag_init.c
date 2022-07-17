/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoobag_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:12 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/14 17:42:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoobag.h"

static	__init_registers_and_zobj_vars(t_zb *zb)
{
	zb->lowest_free_zobj = 0;
	zb->zobjs_count = 0;
	ft_memclear(zb->zobj_arr, MAX_ZOBJS * sizeof(t_zobj *));

	zb->eye.arr = zb->__farr_eye;
	mtx_shell(&(zb->eye));
	quat_create_empty(&(zb->qr1));
	quat_create_empty(&(zb->qr2));
	quat_create_empty(&(zb->qr3));
	quat_create_empty(&(zb->qr4));

	zb->mtx_reg.arr = (float *)zb->__farr_reg_coords;
	mtx_shell(&(zb->mtx_reg), MAX_REG_COORDS, 4, DTYPE_F);

}

// initializes zoobag renderer including minilibx context and window, and all
// zoobag_renderer utils and tools. Pass t_zb stack declared variable in main
// to this function to initialize. Then pass the zb variable to function calls 
// and hook functions to 
int	zb_init_core(t_zb *zb, int wdims[2], char *wtitle)
{
	mlx_init_double_buff_window(&zb->mlx, wdims[0], wdims[1], wtitle);
	__init_registers_and_zobj_var(zb)
}

int	zb_close_core(t_zb *zb, int wdims[2], char *wtitle)
{
		
}
