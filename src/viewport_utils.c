/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:31:54 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/25 00:51:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	viewport_init(t_viewp *vp, t_mlx *mlx, const int pos[2], const int size[2])
{
	if (!vp || !mlx)
		return (-1);
	vp->ox = pos[0];
	vp->oy = pos[1];
	vp->w = size[0];
	vp->h = size[1];
	return (0);
}

int	viewport_draw_obj(t_viewp *vp, t_mlx *mlx, t_mtx *scoords)
{
	
}
