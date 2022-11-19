/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:08:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/18 22:08:12 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_clear(t_fdf *fdf, int exit_code)
{
	printf("clear : entered\n");
	if (fdf->map.coords)
		mtx_clear(&fdf->map.coords);
	printf("clear : coords cleared\n");
//	mlx_close(&fdf->mlx);82, 15
//	printf("clear : mlx cleared\n");
	return (exit_code);
}

int	on_close(void *fdf_p)
{
	exit(fdf_clear((t_fdf *)fdf_p, EXIT_SUCCESS));
}

void	draw_map(t_fdf *fdf)
{
	t_fmap	*map;
	float	*coord1;
	float	*coord2;
	int		x;
	int		y;
	int		coord1_i[2];
	int		coord2_i[2];

	map = &fdf->map;
	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			printf("(x, y) : (%i, %i)\n", x, y);
			coord1 = (float *)mtx_index(map->coords, y * map->w + x, 0);
			coord1_i[0] = (int)coord1[0];
			coord1_i[1] = (int)coord1[1];
			coord2 = (float *)mtx_index(map->coords, (y + 1) * map->w + x, 0);
			if (coord2 && (y + 1) < map->h)
			{
				coord2_i[0] = (int)coord2[0];
				coord2_i[1] = (int)coord2[1];
		//		printf("draw (x, y) to (x, y) : (%i, %i) to (%i, %i)\n", x, y, x, y + 1);
				mlx_draw_line(&fdf->mlx, coord1_i, coord2_i, 0x00fff7);
			}
			coord2 = (float *)mtx_index(map->coords, y * map->w + (x + 1), 0);
			if (coord2 && (x + 1) < map->w)
			{
				coord2_i[0] = (int)coord2[0];
				coord2_i[1] = (int)coord2[1];
			//	printf("draw (x, y) to (x, y) : (%i, %i) to (%i, %i)\n", x, y, x + 1, y);
				mlx_draw_line(&fdf->mlx, coord1_i, coord2_i, 0x00fff7);
			}
		}
	}
}

static void	scale_map_to_window(t_fmap *map)
{
	float	_arr[4];
	t_mtx	mins;
	t_mtx	view_xyz;
	float	ratio;

	mins.arr = _arr;
	mtx_shell(&mins, 4, 1, DTYPE_F);
	
	mtx_min(map->coords, ROWWISE, &mins);
	mtx_select_col_range(map->coords, 0, 3, &view_xyz);
	if ((_arr[0] / SCN_WIDTH) < (_arr[1] / SCN_HEIGHT))
	{
		ratio = SCN_MID_X * 0.8;
		_mtx_idivf_pscalar(&view_xyz, -_arr[0]);
	}
	else
	{
		ratio = SCN_MID_Y * 0.8;
		_mtx_idivf_pscalar(&view_xyz, -_arr[1]);
	}
//	mtx_print(map->coords);
//	printf("scale map to win : ratio %f\n", ratio);
	quat_iscale(&map->transform, ratio);
}

static int	transform_and_scale_map_to_window(t_fmap *map)
{
	const float	qv1[3] = {0, 1, 0};
	const float	qv2[3] = {1, 0, 0};
	t_mtx		*mean;
	t_quat		*q1;
	t_quat		q2;

	printf("transform and scale : entered \n");
	q1 = quat_create_empty(&map->transform);
	quat_create_empty(&q2);
	_quat_update(q1, qv1, ISO_Y_THETA);
	_quat_update(&q2, qv2, ISO_X_THETA);
	quat_combine(q1, q1, &q2);
	printf("transform and scale : combine DONE \n");

	mean = mtx_mean(map->coords, ROWWISE, NULL);
	*(float *)mtx_index(mean, 3, 0) = 0.0f;
	printf("mtx coords pre sub\n");
	mtx_print(map->coords);
	mtx_sub(map->coords, mean, map->coords);
	printf("mtx coords post sub\n");
	mtx_print(map->coords);
	printf("transform and scale : translation set \n");
	quat_display_info(q1);
	scale_map_to_window(map);
	_quat_translation_set(&map->transform, SCN_MID_X, SCN_MID_Y, 0);
	mtx_print(map->coords);
	quat_display_info(&map->transform);
	quat_irotate(map->coords, &map->transform);

	mtx_print(map->coords);
	mtx_clear(&mean);

	printf("transform and scale : clear done exit \n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2)
		return (1);

	if (fdf_load_map(argv[1], &fdf.map) < 0)
		return (2);
//	return (0);
	if (mlx_init_double_buff_window(&fdf.mlx, 
			SCN_WIDTH, SCN_HEIGHT, WIN_TITLE) < 0)
		return (fdf_clear(&fdf, 3));
	
	transform_and_scale_map_to_window(&fdf.map);
	mlx_set_bg_color(&fdf.mlx, 0x1f21a1);
	draw_map(&fdf);
	mlx_render_buffer(&fdf.mlx);
	mlx_hook(fdf.mlx.win, ON_DESTROY, 0, on_close, &fdf.mlx);
	mlx_loop(&fdf.mlx);	
	printf("mlx loop dead\n");
	return (fdf_clear(&fdf, EXIT_SUCCESS));
}
