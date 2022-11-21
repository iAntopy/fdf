/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:08:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/21 03:48:52 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_clear(t_fdf *fdf, int exit_code)
{
	printf("clear : entered\n");
	if (fdf->map.coords)
		mtx_clear(&fdf->map.coords);
	if (fdf->map.screen_coords)
		mtx_clear(&fdf->map.screen_coords);
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
//			printf("(x, y) : (%i, %i)\n", x, y);
			coord1 = (float *)mtx_index(map->screen_coords, y * map->w + x, 0);
			coord1_i[0] = (int)coord1[0];
			coord1_i[1] = (int)coord1[1];
//			coord2 = (float *)mtx_index(map->coords, (y + 1) * map->w + x, 0);
			if ((y + 1) < map->h)
			{
				coord2 = (float *)mtx_index(map->screen_coords, (y + 1) * map->w + x, 0);
				coord2_i[0] = (int)coord2[0];
				coord2_i[1] = (int)coord2[1];
//				printf("draw VERTICAL (x, y) to (x, y) : (%i, %i) (%i, %i) to (%i, %i) (%i, %i).\n", x, y, coord1_i[0], coord1_i[1], x, y + 1, coord2_i[0], coord2_i[1]);
				mlx_draw_line(&fdf->mlx, coord1_i, coord2_i, 0x00fff7);
			}
//			coord2 = (float *)mtx_index(map->coords, y * map->w + (x + 1), 0);
			if ((x + 1) < map->w)
			{
				coord2 = (float *)mtx_index(map->screen_coords, y * map->w + (x + 1), 0);
				coord2_i[0] = (int)coord2[0];
				coord2_i[1] = (int)coord2[1];
//				printf("draw map : coord2_i : (%d, %d)\n", coord2_i[0], coord2_i[1]);
//				printf("draw HORIZONTAL (x, y) to (x, y) : (%i, %i) (%i, %i) to (%i, %i) (%i, %i).\n", x, y, coord1_i[0], coord1_i[1], x, y + 1, coord2_i[0], coord2_i[1]);
				mlx_draw_line(&fdf->mlx, coord1_i, coord2_i, 0x00fff7);
			}
		}
	}
}

static void	scale_map_to_window(t_fmap *map)
{
	float	_arr[4];
	t_mtx	maxs;
	t_mtx	view_xyz;
	float	ratio;

	maxs.arr = _arr;
	mtx_shell(&maxs, 4, 1, DTYPE_F);
	
	mtx_max(map->coords, ROWWISE, &maxs);
	mtx_select_col_range(map->coords, 0, 3, &view_xyz);
	if ((_arr[0] / SCN_WIDTH) < (_arr[1] / SCN_HEIGHT))
	{
		ratio = SCN_MID_X * 0.5;
		_mtx_idivf_pscalar(&view_xyz, _arr[0]);
//		_mtx_imulf_pscalar(&view_xyz, ratio);
	}
	else
	{
		ratio = SCN_MID_Y * 0.5;
		_mtx_idivf_pscalar(&view_xyz, _arr[1]);
//		_mtx_imulf_pscalar(&view_xyz, ratio);
	}
//	mtx_print(map->coords);
//	printf("scale map to win : ratio %f\n", ratio);
//	quat_iscale(map->transform, ratio);
//	printf("before ratio mult. scalars %p, scalars.arr %p\n", map->scalars, map->scalars->arr);
//	_mtx_imulf_pscalar(map->scalars, ratio);
	map->__scalars_arr[0] = ratio;
	map->__scalars_arr[1] = ratio;
	map->__scalars_arr[2] = ratio;
//	printf("scalars after ratio mult\n");
	mtx_print(map->scalars);
}

static int	transform_and_scale_map_to_window(t_fmap *map)
{
	const float	qv1[3] = {1, 0, 0};
	const float	qv2[3] = {0, 1, 0};
	t_mtx		*mean;
	t_quat		*q1;
	t_quat		*q2;
	t_quat		*q3;
	
	printf("transform and scale : entered \n");
	map->x_transform = map->__qpool;
	map->y_transform = map->__qpool + 1;
	map->transform = map->__qpool + 2;
	q1 = quat_create_empty(map->x_transform);
	q2 = quat_create_empty(map->y_transform);
	q3 = quat_create_empty(map->transform);

	_quat_update(q1, qv1, -ISO_X_THETA);
	_quat_update(q2, qv2, ISO_Y_THETA);

	quat_combine(q1, q2, q3);
	quat_display_info(q1);
	printf("transform and scale : combine DONE \n");

	mean = mtx_mean(map->coords, ROWWISE, NULL);
	*(float *)mtx_index(mean, 3, 0) = 0.0f;
	printf("mtx coords pre sub\n");
	mtx_sub(map->coords, mean, map->coords);
	mtx_clear(&mean);
//	printf("mtx coords post sub\n");

	printf("transform and scale : translation set \n");
	scale_map_to_window(map);
	_quat_translation_set(map->transform, SCN_MID_X, SCN_MID_Y, 0);
//	printf("transform and scale : clear done exit \n");
	return (0);
}

static int	update_map(t_fdf *fdf)
{
	printf("update map : entered. fdf %p, coords %p, screen_coords %p, scalars %p\n", fdf, fdf->map.coords, fdf->map.screen_coords, fdf->map.scalars);
	_mtx_mulf_line_r(fdf->map.coords, fdf->map.scalars, fdf->map.screen_coords);
//	quat_display_info(fdf->map.transform);
	printf("update map : scaling DONE\n");

	quat_irotate(fdf->map.screen_coords, fdf->map.transform);
	mlx_set_bg_color(&fdf->mlx, BG_COL);
	printf("update map : rotation DONE\n");
//	mtx_print(fdf->map.coords);
//	mtx_print(fdf->map.screen_coords);
	draw_map(fdf);
//	printf("update map : map drawn DONE\n");
//	mlx_get_info(&fdf->mlx);
//	printf("update map : trying to render mlx\n");
	mlx_render_buffer(&fdf->mlx);
	printf("update map : buffer rendered\n");

	return (0);	
}

int	on_scale_z_up(t_fdf *fdf)
{
	fdf->map.__scalars_arr[2] *= 1.05;
//	quat_iscale_xyz(fdf->map.transform, 1.0f, 1.0f, 1.05f);
	update_map(fdf);
	return (0);
}

int	on_scale_z_down(t_fdf *fdf)
{
	fdf->map.__scalars_arr[2] *= 0.95f;
//	quat_iscale_xyz(fdf->map.transform, 1.0f, 1.0f, 0.95f);
	update_map(fdf);
	return (0);
}

int	on_rotate_left(t_fdf *fdf)
{
	printf("rotate left : entered\n");
	quat_add(fdf->map.transform, 0, 0.1, 0);
//	quat_twist(fdf->map.y_transform, 0.1);
//	quat_combine(fdf->map.y_transform, fdf->map.x_transform, fdf->map.transform);
	update_map(fdf);
	return (0);
}

int	on_rotate_right(t_fdf *fdf)
{
	printf("rotate right : entered\n");
	quat_add(fdf->map.transform, 0, -0.1, 0);
//	quat_twist(fdf->map.y_transform, -0.1);
//	quat_combine(fdf->map.y_transform, fdf->map.x_transform, fdf->map.transform);
	update_map(fdf);
	return (0);
}

int	on_rotate_up(t_fdf *fdf)
{
	printf("rotate up : entered\n");
//	quat_twist(fdf->map.x_transform, 0.1);
	quat_add(fdf->map.transform, -0.1, 0, 0);
//	quat_combine(fdf->map.y_transform, fdf->map.x_transform, fdf->map.transform);
	update_map(fdf);
	return (0);
}

int	on_rotate_down(t_fdf *fdf)
{
	printf("rotate down : entered\n");
	quat_add(fdf->map.transform, 0.1, 0, 0);
//	quat_twist(fdf->map.x_transform, -0.1);
//	quat_combine(fdf->map.y_transform, fdf->map.x_transform, fdf->map.transform);
	update_map(fdf);
	return (0);
}

static int	fdf_key_switch(int key, void *fdf_p)
{
	t_fdf	*fdf;
	
	printf("KEY SWITCH ENTERED : keycode %d \n", key);
	printf("KEY SWITCH ENTERED : codes W, A, S, D : %d, %d, %d, %d\n", KC_W, KC_A, KC_S, KC_D);
	fdf = (t_fdf *)fdf_p;
	if (key == KC_Up)
		on_scale_z_up(fdf);
	else if (key == KC_Down)
		on_scale_z_down(fdf);
	else if (key == KC_a)
		on_rotate_left(fdf);
	else if (key == KC_d)
		on_rotate_right(fdf);
	else if (key == KC_w)
		on_rotate_up(fdf);
	else if (key == KC_s)
		on_rotate_down(fdf);
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
	if (!mlx_init_double_buff_window(&fdf.mlx, 
			SCN_WIDTH, SCN_HEIGHT, WIN_TITLE))
		return (fdf_clear(&fdf, 3));
	
	printf("map loaded and mlx init\n");
	transform_and_scale_map_to_window(&fdf.map);
//	printf("transform DONE\n");
	mlx_key_hook(fdf.mlx.win, fdf_key_switch, &fdf);
	mlx_hook(fdf.mlx.win, ON_DESTROY, 0, on_close, &fdf.mlx);
	printf("hook onclose DONE\n");
	update_map(&fdf);
	mlx_loop(fdf.mlx.conn);	
	printf("mlx loop dead\n");
	return (fdf_clear(&fdf, EXIT_SUCCESS));
}
