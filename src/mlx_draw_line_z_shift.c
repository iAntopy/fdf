/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line_z_shift.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:55:29 by iamongeo          #+#    #+#             */
/*   Updated: 2023/05/02 05:20:16 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
/*
static int	pixel_is_inbound(t_mlx *mlx, int x, int y, int z)
{
	return ((x >= 0) && (y >=0) && (x < mlx->width) && (y < mlx->height)
		&& (z >= 0));
}

static int	pixel_is_bg_color(t_mlx *mlx, int x, int y)
{
	int	*pix;

	pix = mlx_index_buffer(mlx->off_buff, x, y);
	return (*pix == BG_COL || *pix == BG_COL2);
}
*/
static void	swap_limits(int *lims[2], int ds[2])
{
	int	*temp;

	temp = lims[0];
	lims[0] = lims[1];
	lims[1] = temp;
	ds[0] = -ds[0]; 
	ds[1] = -ds[1];
}

static int	z_color_shift(int dx, int dy, int ds[3])
{
	float	ratio;
//	float	partial_cols[3];
	int	col;

//	col = 0x00ffffff;
	col = 0;
	ratio = 0;
	if (ds[0] && ds[1])
		ratio = ((float)dx / ds[0] + (float)dy / ds[1]) / 2;
	if (ratio < 0)
		ratio = 0;
	else if (ratio >= 1)
		ratio = 1.0f;
	if (ds[2] < 0)
	{
//		partial_cols[0] = ratio;//* (1.0f - ratio);
//		partial_cols[1] = partial_cols[0];
//		partial_cols[2] = 245.0f;
		col += (int)(0xff * (1.0f - ratio)) << 16;
		col += (int)(0xff * (1.0f - ratio)) << 8;
	}
	else
	{
//		partial_cols[0] = 245.0f;
//		partial_cols[1] = ratio;//* (1.0f - ratio);
//		partial_cols[2] = partial_cols[1];
		col += (int)(0xff * (1.0f - ratio)) << 8;
		col += (int)(0xff * (1.0f - ratio));
	}
//	col = (int)partial_cols[0];
//	col <<= 8;
//	col += (int)partial_cols[1];
///	col <<= 8;
//	col += (int)partial_cols[2];
	return (col);
}

static void	draw_line_low(t_mlx *mlx, int *lims[2], int ds[3], int *bounds[2])
{
	int	D;
	int	yi;
	int	dy_min_dx;
	int	x;
	int	y;

	x = lims[0][0] - 1;
	y = lims[0][1];
	yi = 1 - (2 * (ds[1] < 0));
	ds[1] *= yi;
	D = (2 * ds[1]) - ds[0];
	dy_min_dx = ds[1] - ds[0];
	while (++x < lims[1][0])// && bounds[0][0] < x < bounds[1][0] && bounds[0][1] < y < bounds[1][1])
	{
//		if (pixel_is_inbound(mlx, x, y, (int)((float)x - lims[0][0]) / ds[0] * ds[2] + lims[0][2]) && pixel_is_bg_color(mlx, x, y))
		if ((bounds[0][0] < x && x < bounds[1][0]) && (bounds[0][1] < y && y < bounds[1][1]))//pixel_is_inbound(mlx, x, y, 1) )//&& pixel_is_bg_color(mlx, x, y))
//		if (pixel_is_inbound(mlx, x, y))			// TODO : MOVE CLIPPING OUTSIDE DRAW CALL.
			mlx_buff_put_pixel(mlx->off_buff, x, y,
				z_color_shift(x - lims[0][0], y - lims[0][1], ds));
		if (D > 0)
		{
			y += yi;
			D += 2 * dy_min_dx;
		}
		else
			D += 2 * ds[1];
	}
}

static void	draw_line_high(t_mlx *mlx, int *lims[2], int ds[3], int *bounds[2])
{
	int	D;
	int	xi;
	int	dx_min_dy;
	int	x;
	int	y;

	y = lims[0][1] - 1;
	x = lims[0][0];
	xi = 1 - (2 * (ds[0] < 0));
	ds[0] *= xi;
	D = (2 * ds[0]) - ds[1];
	dx_min_dy = ds[0] - ds[1];
	while (++y < lims[1][1])
	{
//		if (pixel_is_inbound(mlx, x, y, (int)((float)y - lims[0][1]) / ds[1] * ds[2] + lims[0][2]) && pixel_is_bg_color(mlx, x, y))
		if ((bounds[0][0] < x && x < bounds[1][0]) && (bounds[0][1] < y && y < bounds[1][1]))//pixel_is_inbound(mlx, x, y, 1)// && pixel_is_bg_color(mlx, x, y))
			mlx_buff_put_pixel(mlx->off_buff, x, y,
				z_color_shift(x - lims[0][0], y - lims[0][1], ds));
		if (D > 0)
		{
			x += xi;
			D += 2 * dx_min_dy;
		}
		else
			D += 2 * ds[0];
	}
}

// scn_bounderies as [[min x lim, min y lim], [max x lim, max y lim]]
void	mlx_draw_line_z_shift(t_mlx *mlx, int start[3], int end[3], int *scn_bounderies[2])
{
	int	deltas[3];
	int	*limits[2];

	deltas[0] = end[0] - start[0];
	deltas[1] = end[1] - start[1];
	deltas[2] = end[2] - start[2];
	limits[0] = start;
	limits[1] = end;
	if (abs(deltas[1]) < abs(deltas[0]))
	{
//		printf("draw line dx > dy, swap : %d\n", (start[0] > end[0]));
		if (start[0] > end[0])
		{
			swap_limits(limits, deltas);
//			printf("SWAP!\n");
		}
//		printf("draw line low : from (%i, %i) to delta (%i, %i), color %d\n", *limits[0], *limits[1], deltas[0], deltas[1], color);
		draw_line_low(mlx, limits, deltas, scn_bounderies);
	}
	else
	{
//		printf("draw line dy > dx, swap : %d\n", (start[1] > end[1]));
		if (start[1] > end[1])
		{
			swap_limits(limits, deltas);
//			printf("SWAP!\n");
		}
		draw_line_high(mlx, limits, deltas, scn_bounderies);
	}
}
