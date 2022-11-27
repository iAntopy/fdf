/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_bg_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:31:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/26 16:42:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_set_bg_color(t_mlx *mlx, int col)
{
	size_t	*b;
	int		*p;
	size_t	total_bytes;
	size_t	xl;

	p = (int *)&xl;
	*p = col;
	*(p + 1) = col;
	b = (size_t *)mlx->off_buff->addr;
	total_bytes = mlx->buff_size;
	while (total_bytes >= sizeof(size_t))
	{
		*(b++) = xl;
		total_bytes -= sizeof(size_t);
	}
	p = (int *)b;
	while (total_bytes >= sizeof(int))
	{
		*(p++) = col;
		total_bytes -= sizeof(int);
	}
}

// start, end in x, y coords.
void	mlx_fill_color_region(t_mlx *mlx, int start[2], int end[2], int col)
{
	t_img	*img;
	int	limits[4];
	void	*buff_p[2];
	int	y;
	int	row_size;

	if (!mlx || !start || !end || end[0] <= start[0] || end[1] <= start[1])
		return ;
	limits[0] = start[0] - start[0] * (start[0] < 0);
	limits[1] = start[1] - start[1] * (start[1] < 0);
	limits[2] = end[0] - (end[0] - mlx->width) * (end[0] > mlx->width);
	limits[3] = end[1] - (end[1] - mlx->width) * (end[1] > mlx->width);
	img = mlx->off_buff;
	buff_p[0] = img->addr + limits[0] * img->bytes_per_pxl;
	y = limits[1] - 1;
	while (++y < limits[3])
	{
		buff_p[1] = buff_p[0] + (img->line_len * y);
		row_size = (limits[2] - limits[0]) * img->bytes_per_pxl;
		while (row_size)
		{
			*(int *)buff_p[1] = col;
			buff_p[1] += img->bytes_per_pxl;
			row_size -= img->bytes_per_pxl;
		}
	}
}
