/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:08:14 by iamongeo          #+#    #+#             */
/*   Updated: 2023/05/02 05:22:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_clear(t_fdf *fdf, int exit_code)
{
//	printf("clear : entered\n");
	if (fdf->map.coords)
		mtx_clear(&fdf->map.coords);
	if (fdf->map.screen_coords)
		mtx_clear(&fdf->map.screen_coords);
	if (fdf->beacon.coords)
		mtx_clear(&fdf->beacon.coords);
	if (fdf->beacon.screen_coords)
		mtx_clear(&fdf->beacon.screen_coords);
	if (fdf->frame.coords)
		mtx_clear(&fdf->frame.coords);
	if (fdf->frame.screen_coords)
		mtx_clear(&fdf->frame.screen_coords);
//	printf("clear : coords cleared\n");
//	mlx_close(&fdf->mlx);82, 15
//	printf("clear : mlx cleared\n");
	return (exit_code);
}

int	on_close(void *fdf_p)
{
	exit(fdf_clear((t_fdf *)fdf_p, EXIT_SUCCESS));
}

void	draw_map(t_fdf *fdf, t_fmap *map, t_viewp *vp)
{
	float	*coord1;
	float	*coord2;
	int		x;
	int		y;
	int		coord1_i[2];
	int		coord2_i[2];
	int		max_draw_bounds[2];
	int		*bounderies[2];
	
	if (!map->coords || !map->screen_coords)
		return ;
//	printf("DRAWING MAP !\n");
//	if (map == &fdf->frame)
//		printf("WOWO !! This is frame !\n");
	bounderies[0] = vp->offset;
	max_draw_bounds[0] = vp->offset[0] + vp->w;
	max_draw_bounds[1] = vp->offset[1] + vp->h;
	bounderies[1] = max_draw_bounds;
//	ft_eprintf("bounderies : [%d, %d], [%d, %d]\n", vp->offset[0], vp->offset[1], max_draw_bounds[0], max_draw_bounds[1]);
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
				mlx_draw_line_z_shift(&fdf->mlx, coord1_i, coord2_i, bounderies);//, 0x00fff7);
			}
//			coord2 = (float *)mtx_index(map->coords, y * map->w + (x + 1), 0);
			if ((x + 1) < map->w)
			{
				coord2 = (float *)mtx_index(map->screen_coords, y * map->w + (x + 1), 0);
				coord2_i[0] = (int)coord2[0];
				coord2_i[1] = (int)coord2[1];
//				printf("draw map : coord2_i : (%d, %d)\n", coord2_i[0], coord2_i[1]);
//				printf("draw HORIZONTAL (x, y) to (x, y) : (%i, %i) (%i, %i) to (%i, %i) (%i, %i).\n", x, y, coord1_i[0], coord1_i[1], x, y + 1, coord2_i[0], coord2_i[1]);
				mlx_draw_line_z_shift(&fdf->mlx, coord1_i, coord2_i, bounderies);//, 0x00fff7);
			}
		}
	}
}



static void	scale_map_to_window(t_fmap *map)
{
	float	_maxs[3];
	t_mtx	maxs;
	t_mtx	view_xyz;
	float	max_coord;
//	float	ratio;

	maxs.arr = _maxs;
	mtx_shell(&maxs, 3, 1, DTYPE_F);
	
//	mtx_max(map->coords, ROWWISE, &maxs);
	mtx_select_col_range(map->coords, 0, 3, &view_xyz);
	mtx_max(&view_xyz, ROWWISE, &maxs);
	max_coord = _maxs[0];
	max_coord += (_maxs[1] - max_coord) * (_maxs[1] > max_coord);
	max_coord += (_maxs[2] - max_coord) * (_maxs[2] > max_coord);
	_mtx_imulf_pscalar(&maxs, 0.5);
	_mtx_isubf_line_r(&view_xyz, &maxs);
	_mtx_imulf_pscalar(&view_xyz, (SCN_HEIGHT * 1.2 / (2 * max_coord)));
///	if ((_maxs[0] / SCN_WIDTH) > (_maxs[1] / SCN_HEIGHT))
///		_mtx_imulf_pscalar(&view_xyz, (SCN_WIDTH * 0.8 / (2 * _maxs[0])));
//	else
//		_mtx_imulf_pscalar(&view_xyz, (SCN_HEIGHT * 0.8 / (2 *_maxs[1])));

//	printf("Post scaling official base coords : \n");
//	mtx_print(map->coords);
//	printf("scale map to win : ratio %f\n", ratio);
//	quat_iscale(map->transform, ratio);
//	printf("before ratio mult. scalars %p, scalars.arr %p\n", map->scalars, map->scalars->arr);
//	_mtx_imulf_pscalar(map->scalars, ratio);
//	map->__scalars_arr[0] = ratio;
//	map->__scalars_arr[1] = ratio;
//	map->__scalars_arr[2] = ratio;
//	printf("scalars after ratio mult\n");
//	mtx_print(map->scalars);
//	_mtx_imulf_line_r(map->coords, map->scalars);
//	printf("scale map to win : base model coords\n");
//	mtx_print(map->coords);
}

/*
static int	transform_and_scale_map_to_window(t_fmap *map)
{
//	const float	qv1[3] = {1, 0, 0};
//	const float	qv2[3] = {0, 1, 0};
	t_mtx		*mean;
	t_quat		*q;
//	t_quat		*q2;
//	t_quat		*q3;
	
	printf("transform and scale : entered \n");
//	map->x_transform = map->__qpool;
//	map->y_transform = map->__qpool + 1;
	map->transform = map->__qpool;
//	q1 = quat_create_empty(map->x_transform);
//	q2 = quat_create_empty(map->y_transform);
	q = quat_create_empty(map->transform);

//	_quat_update(q1, qv1, -ISO_X_THETA);
//	_quat_update(q2, qv2, ISO_Y_THETA);
	quat_add(q, -ISO_X_THETA, ISO_Y_THETA, 0);

//	quat_combine(q1, q2, q3);
	quat_display_info(q);
	printf("transform and scale : combine DONE \n");

	mean = mtx_mean(map->coords, ROWWISE, NULL);
	*(float *)mtx_index(mean, 3, 0) = 0.0f;
	printf("mtx coords pre sub\n");
	mtx_sub(map->coords, mean, map->coords);
	mtx_clear(&mean);
//	printf("mtx coords post sub\n");

	printf("transform and scale : translation set \n");
	scale_map_to_window(map);
//	_quat_translation_set(map->transform, SCN_MID_X, SCN_MID_Y, 0);
//	printf("transform and scale : clear done exit \n");
	return (0);
}
*/
/*
static int	update_map_no_cam(t_fdf *fdf)
{
	_quat_translation_set(fdf->map.transform, SCN_MID_X, SCN_MID_Y, 0);
	quat_display_info(fdf->map.transform);
	quat_rotate(fdf->map.coords, fdf->map.transform, fdf->map.screen_coords);
	mlx_set_bg_color(&fdf->mlx, fdf->bg_col);
	draw_map(fdf);
	mlx_render_buffer(&fdf->mlx);
	return (0);
}
*/
static int	update_map(t_fdf *fdf, int update_extras)
{
//	mlx_set_bg_color(&fdf->mlx, fdf->bg_col);
//	printf("update_map : entered\n");

//	printf("\nDisplay Cam 1 : \n");
	mlx_fill_color_region(&fdf->mlx, fdf->vp1.offset, fdf->vp1.limit, fdf->bg_col);
	viewport_apply_all_transforms(&fdf->map, &fdf->cam1, &fdf->vp1, fdf->map.screen_coords);
//	mtx_print(fdf->map.screen_coords);
	viewport_apply_all_transforms(&fdf->beacon, &fdf->cam1, &fdf->vp1, fdf->beacon.screen_coords);
//	viewport_apply_all_transforms(&fdf->frame, &fdf->cam1, &fdf->vp1, fdf->frame.screen_coords);
	draw_map(fdf, &fdf->map, &fdf->vp1);
	draw_map(fdf, &fdf->beacon, &fdf->vp1);
//	draw_map(fdf, &fdf->frame);
//	printf("update : frame screen coords through cam1 vp1 :\n");
//	mtx_print(fdf->frame.screen_coords);
	
	if (update_extras)
	{
		mlx_fill_color_region(&fdf->mlx, fdf->vp2.offset, fdf->vp2.limit, fdf->bg_col);
		viewport_apply_all_transforms(&fdf->map, &fdf->cam2, &fdf->vp2, fdf->map.screen_coords);
		viewport_apply_all_transforms(&fdf->beacon, &fdf->cam2, &fdf->vp2, fdf->beacon.screen_coords);
//		viewport_apply_all_transforms(&fdf->frame, &fdf->cam2, &fdf->vp2, fdf->frame.screen_coords);
/*
		printf("update : frame obj coords : \n");
		mtx_print(fdf->frame.coords);
		printf("update : frame obj screen coords through cam2 vp2 : %p\n", fdf->cam2.transform);
		mtx_display_info(fdf->frame.screen_coords);
		mtx_print(fdf->frame.screen_coords);
		printf("update : cam2 transform : \n");
		mtx_print(fdf->cam2.transform);
		printf("update : vp2 transform : \n");
		mtx_print(fdf->vp2.transform);
*/
		draw_map(fdf, &fdf->map, &fdf->vp2);
		draw_map(fdf, &fdf->beacon, &fdf->vp2);
//		draw_map(fdf, &fdf->frame);

	
		mlx_fill_color_region(&fdf->mlx, fdf->vp3.offset, fdf->vp3.limit, fdf->bg_col);
		viewport_apply_all_transforms(&fdf->map, &fdf->cam3, &fdf->vp3, fdf->map.screen_coords);
		viewport_apply_all_transforms(&fdf->beacon, &fdf->cam3, &fdf->vp3, fdf->beacon.screen_coords);
//		viewport_apply_all_transforms(&fdf->frame, &fdf->cam3, &fdf->vp3, fdf->frame.screen_coords);

		draw_map(fdf, &fdf->map, &fdf->vp3);
		draw_map(fdf, &fdf->beacon, &fdf->vp3);
//		draw_map(fdf, &fdf->frame);

//		printf("\nDisplay Cam 4 : \n");
		mlx_fill_color_region(&fdf->mlx, fdf->vp4.offset, fdf->vp4.limit, fdf->bg_col);
		viewport_apply_all_transforms(&fdf->map, &fdf->cam4, &fdf->vp4, fdf->map.screen_coords);
		viewport_apply_all_transforms(&fdf->beacon, &fdf->cam4, &fdf->vp4, fdf->beacon.screen_coords);
//		viewport_apply_all_transforms(&fdf->frame, &fdf->cam4, &fdf->vp4, fdf->frame.screen_coords);
		draw_map(fdf, &fdf->map, &fdf->vp4);
		draw_map(fdf, &fdf->beacon, &fdf->vp4);
//		draw_map(fdf, &fdf->frame);


	}
//	mtx_print(fdf->map.screen_coords);
	mlx_render_buffer(&fdf->mlx);
	return (0);
}

/*
static int	init_cam_frame_obj(t_fmap *frame)
{
	static float	frame_array[8][4] = {	{-SCN_MID_X + 20, -SCN_MID_Y + 20, 0, 1},
						{-SCN_MID_X + 25, -SCN_MID_Y + 25, 400, 1},
						{SCN_MID_X - 25, -SCN_MID_Y + 25, 400, 1},
						{SCN_MID_X - 20, -SCN_MID_Y + 20, 0, 1},
						{-SCN_MID_X + 20, SCN_MID_Y - 20, 0, 1},
						{-SCN_MID_X + 25, SCN_MID_Y - 25, 400, 1},
						{SCN_MID_X - 25, SCN_MID_Y - 25, 400, 1},
						{SCN_MID_X - 20, SCN_MID_Y - 20, 0, 1}};
	static t_mtx	frame_coords;

	if (!frame)
		return (-1);
	fmap_init(frame, 4, 2);
	mtx_shell(&frame_coords, 8, 4, DTYPE_F);
	frame_coords.arr = frame_array;
	
	frame->coords = mtx_create_array(frame_array, 8, 4, DTYPE_F);
	frame->screen_coords = mtx_dup_empty(frame->coords, NULL, DTYPE_F);
	return (0);
}
*/
/*
static int	update_map(t_fdf *fdf)
{
	t_quat	final_transform;

	printf("update map : entered. fdf %p, coords %p, screen_coords %p, scalars %p\n", fdf, fdf->map.coords, fdf->map.screen_coords, fdf->map.scalars);
	quat_create_empty(&final_transform);
//	quat_combine(fdf->map.transform, fdf->cam.transform, &final_transform);
//	_mtx_mulf_line_r(fdf->map.coords, fdf->map.scalars, fdf->map.screen_coords);
	printf("update_map : final transform info\n");
	quat_display_info(&final_transform);
//	printf("update map : scaling DONE\n");

//	printf("update map : irotate screen_coords with map transform\n");
	quat_rotate(fdf->map.coords, &final_transform, fdf->map.screen_coords);
//	printf("update map : irotate screen_coords with cam transform\n");
//	quat_irotate(fdf->map.screen_coords, fdf->cam.transform);
	
//	mtx_print(fdf->map.coords);
//	mtx_print(fdf->map.screen_coords);

	mlx_set_bg_color(&fdf->mlx, fdf->bg_col);
//	printf("update map : rotation DONE\n");
//	mtx_print(fdf->map.coords);
//	mtx_print(fdf->map.screen_coords);
	draw_map(fdf);
//	printf("update map : map drawn DONE\n");
//	mlx_get_info(&fdf->mlx);
//	printf("update map : trying to render mlx\n");
	mlx_render_buffer(&fdf->mlx);
	printf("update map : mlx win ptr after render buff : %p\n", fdf->mlx.win);
//	printf("update map : buffer rendered\n");

	return (0);	
}
*/
/*
int	on_scale_z_up(t_fdf *fdf)
{
	fdf->map.__scalars_arr[2] = 1.05f;
	_mtx_imulf_line_r(fdf->map.coords, fdf->map.scalars);//, fdf->map.screen_coords);
//	quat_iscale_xyz(fdf->map.transform, 1.0f, 1.0f, 1.05f);
//	update_map_no_cam(fdf);
	return (0);
}

int	on_scale_z_down(t_fdf *fdf)
{
	fdf->map.__scalars_arr[2] = 0.95f;
	_mtx_imulf_line_r(fdf->map.coords, fdf->map.scalars);//, fdf->map.screen_coords);
//	quat_iscale_xyz(fdf->map.transform, 1.0f, 1.0f, 0.95f);
//	update_map_no_cam(fdf);
	return (0);
}

int	on_rotate_y(t_fdf *fdf, float delta)
{
//	printf("rotate left : entered\n");
	quat_add(fdf->map.transform, 0, delta, 0);
//	quat_twist(fdf->map.y_transform, 0.1);
//	quat_combine(fdf->map.y_transform, fdf->map.x_transform, fdf->map.transform);
//	update_map_no_cam(fdf);
	return (0);
}

int	on_rotate_x(t_fdf *fdf, float delta)
{
//	printf("rotate up : entered\n");
//	quat_twist(fdf->map.x_transform, 0.1);
	quat_add(fdf->map.transform, delta, 0, 0);
//	quat_combine(fdf->map.y_transform, fdf->map.x_transform, fdf->map.transform);
//	update_map_no_cam(fdf);
	return (0);
}
*/
void	pause_anime_on_off(t_fdf *fdf)
{
	fdf->is_animation_active = !fdf->is_animation_active;
}

static void	switch_ctrl_mode(t_fdf *fdf)
{
	printf("SWITCHING CONTROL MODE !");
	fdf->is_cam_ctrl_active = !fdf->is_cam_ctrl_active;
	if (fdf->is_cam_ctrl_active)
	{
		fdf->bg_col = BG_COL2;
//		mlx_key_hook(fdf->mlx.win, fdf_cammode_key_switch, fdf);
	}
	else
	{
		fdf->bg_col = BG_COL;
//		mlx_key_hook(fdf->mlx.win, fdf_modelmode_key_switch, fdf);
	}
//	update_map_no_cam(fdf);
	update_map(fdf, 1);
}
/*
int	fdf_modelmode_key_switch(int key, void *fdf_p)
{
	t_fdf	*fdf;
	
	printf("MODEL MODE KEY SWITCH : keycode %d \n", key);
	fdf = (t_fdf *)fdf_p;
	if (key == KC_Up)
		fmap_scale(&fdf->map, 1, 1, 1.05f);
//		on_scale_z_up(fdf);
	else if (key == KC_Down)
		fmap_scale(&fdf->map, 1, 1, 0.95f);
//		on_scale_z_down(fdf);
	else if (key == KC_a || key == KC_A)
		fmap_rotate(&fdf->map, 0, 0.1f, 0);
//		on_rotate_y(fdf, 0.1);
	else if (key == KC_d || key == KC_D)
		fmap_rotate(&fdf->map, 0, -0.1f, 0);
//		on_rotate_y(fdf, -0.1);
	else if (key == KC_w || key == KC_W)
		fmap_rotate(&fdf->map, -0.1f, 0, 0);
//		on_rotate_x(fdf, -0.1);
	else if (key == KC_s || key == KC_S)
		fmap_rotate(&fdf->map, 0.1f, 0, 0);
//		on_rotate_x(fdf, 0.1);
	else if (key == KC_q || key == KC_Q)
		fmap_rotate(&fdf->map, 0, 0, -0.1f);
//		on_rotate_x(fdf, -0.1);
	else if (key == KC_e || key == KC_E)
		fmap_rotate(&fdf->map, 0, 0, 0.1f);
//		on_rotate_x(fdf, 0.1);
	else if (key == KC_Delete)
		pause_anime_on_off(fdf);
	else if (key == KC_Return)
		;
	else if (key == KC_Space)
		switch_ctrl_mode(fdf);
	else if (key == KC_Escape)
		on_close(fdf);
	else
		return (1);
	update_map(fdf, 1);
	return (0);
}

int	fdf_cammode_key_switch(int key, void *fdf_p)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_p;
	printf("CAM MODE KEY SWITCH : keycode %d\n", key);
//	if (key == KC_w || key == KC_W)
//		camo_rotate(&fdf->cam1, -0.05, 0, 0);
//	else if (key == KC_s || key == KC_S)
//		camo_rotate(&fdf->cam1, 0.05, 0, 0);
//	else if (key == KC_a || key == KC_A)
//		camo_rotate(&fdf->cam1, 0, 0.05, 0);
//	else if (key == KC_d || key == KC_D)
//		camo_rotate(&fdf->cam1, 0, -0.05, 0);
	if (key == KC_q || key == KC_Q)
		camo_rotate(&fdf->cam1, 0, 0, 0.05);
	else if (key == KC_e || key == KC_E)
		camo_rotate(&fdf->cam1, 0, 0, -0.05);
	else if (key == KC_PageUp)
		camo_move(&fdf->cam1, 0, -20, 0);
	else if (key == KC_PageDown)
		camo_move(&fdf->cam1, 0, 20, 0);
	else if (key == KC_a || key == KC_A)//KC_Left)
		camo_move(&fdf->cam1, -20, 0, 0);
	else if (key == KC_d || key == KC_D)//KC_Right)
		camo_move(&fdf->cam1, 20, 0, 0);
	else if (key == KC_w || key == KC_W)//key == KC_Up)
		camo_move(&fdf->cam1, 0, 0, 20);
	else if (key == KC_s || key == KC_S)//KC_Down)
		camo_move(&fdf->cam1, 0, 0, -20);
	else if (key == KC_Home)
		camo_zoom(&fdf->cam1, 0.9);
	else if (key == KC_End)
		camo_zoom(&fdf->cam1, 1.1);
	else if (key == KC_Delete)
		pause_anime_on_off(fdf);
	else if (key == KC_Space)
		switch_ctrl_mode(fdf);
	else if (key == KC_Escape)
		on_close(fdf);
//	camo_update(&fdf->cam1);
//	fmap_set_position(&fdf->frame, fdf->cam1.__pos_arr[0],  fdf->cam1.__pos_arr[1], fdf->cam1.__pos_arr[2]);
//	fmap_set_rotation(&fdf->frame, fdf->cam1.thetas[0],  fdf->cam1.thetas[1], fdf->cam1.thetas[2]);
		
	update_map(fdf, 0);
	return (0);
}
*/

int	on_keyup(int key, t_fdf *fdf_p)
{
	if (key == KC_q || key == KC_Q)
		fdf_p->pkeys.q = 0;
	else if (key == KC_e || key == KC_E)
		fdf_p->pkeys.e = 0;
	else if (key == KC_w || key == KC_W)
		fdf_p->pkeys.w = 0;
	else if (key == KC_a || key == KC_A)
		fdf_p->pkeys.a = 0;
	else if (key == KC_s || key == KC_S)
		fdf_p->pkeys.s = 0;
	else if (key == KC_d || key == KC_D)
		fdf_p->pkeys.d = 0;
	else if (key == KC_Up)
		fdf_p->pkeys.up = 0;
	else if (key == KC_Down)
		fdf_p->pkeys.down = 0;
	else if (key == KC_Shift_L)
		fdf_p->pkeys.shift = 0;
	else if (key == KC_Control_L)
		fdf_p->pkeys.ctrl = 0;
	else if (key == KC_Left)
		fdf_p->pkeys.left = 0;
	else if (key == KC_Right)
		fdf_p->pkeys.right = 0;
	return (0);
}

int	on_keydown(int key, t_fdf *fdf_p)
{
//	ft_printf("key : %d\n", key);
	if (key == KC_q || key == KC_Q)
		fdf_p->pkeys.q = 1;
	else if (key == KC_e || key == KC_E)
		fdf_p->pkeys.e = 1;
	else if (key == KC_w || key == KC_W)
		fdf_p->pkeys.w = 1;
	else if (key == KC_a || key == KC_A)
		fdf_p->pkeys.a = 1;
	else if (key == KC_s || key == KC_S)
		fdf_p->pkeys.s = 1;
	else if (key == KC_d || key == KC_D)
		fdf_p->pkeys.d = 1;
	else if (key == KC_Up)
		fdf_p->pkeys.up = 1;
	else if (key == KC_Down)
		fdf_p->pkeys.down = 1;
	else if (key == KC_Shift_L)
		fdf_p->pkeys.shift = 1;
	else if (key == KC_Control_L)
		fdf_p->pkeys.ctrl = 1;
	else if (key == KC_Left)
		fdf_p->pkeys.left = 1;
	else if (key == KC_Right)
		fdf_p->pkeys.right = 1;
	else if (key == KC_Escape)
		on_close(fdf_p);
	else if (key == KC_Space)
		switch_ctrl_mode(fdf_p);
	else if (key == KC_Delete)
		pause_anime_on_off(fdf_p);
//	printf("keys pressed : w %d, a %d, s %d, d %d, q %d, e %d, shft %d, ctrl %d\n",
//		fdf_p->pkeys.w, fdf_p->pkeys.a, fdf_p->pkeys.s, fdf_p->pkeys.d,
//		fdf_p->pkeys.q, fdf_p->pkeys.e, fdf_p->pkeys.shift, fdf_p->pkeys.ctrl);
	return (0);
}

int	on_update(void *fdf_p)
{
	static size_t	delta_time;
	t_fdf			*fdf;

	fdf = (t_fdf *)fdf_p;
	delta_time += ft_deltatime_usec();
//	usleep(30000);
	if (delta_time < 30000)
		return (0);
	delta_time = 0;
	if (fdf->is_cam_ctrl_active)
	{
		if (fdf->pkeys.a)
			camo_move(&fdf->cam1, -10.0f, 0, 0);
		if (fdf->pkeys.d)
			camo_move(&fdf->cam1, 10.0f, 0, 0);
		if (fdf->pkeys.w)
			camo_move(&fdf->cam1, 0, 0, 10.0f);
		if (fdf->pkeys.s)
			camo_move(&fdf->cam1, 0, 0, -10.0f);
		if (fdf->pkeys.q)
			camo_rotate(&fdf->cam1, 0, 0, 0.02f);
		if (fdf->pkeys.e)
			camo_rotate(&fdf->cam1, 0, 0, -0.02f);
		if (fdf->pkeys.left)
			camo_rotate(&fdf->cam1, 0, 0.02f, 0);
		if (fdf->pkeys.right)
			camo_rotate(&fdf->cam1, 0, -0.02f, 0);
		if (fdf->pkeys.up)
			camo_rotate(&fdf->cam1, -0.02f, 0, 0);
		if (fdf->pkeys.down)
			camo_rotate(&fdf->cam1, 0.02f, 0, 0);
		if (fdf->pkeys.shift)
			camo_move(&fdf->cam1, 0, -10.0f, 0);
		if (fdf->pkeys.ctrl)
			camo_move(&fdf->cam1, 0, 10.0f, 0);

	}
	else
	{
		if (fdf->pkeys.shift)
		{
			if (fdf->pkeys.a)
				fmap_move(&fdf->map, 10, 0, 0);
			if (fdf->pkeys.d)
				fmap_move(&fdf->map, -10, 0, 0);
			if (fdf->pkeys.w)
				fmap_move(&fdf->map, 0, 0, 10);
			if (fdf->pkeys.s)
				fmap_move(&fdf->map, 0, 0, -10);
			if (fdf->pkeys.q)
				fmap_move(&fdf->map, 0, -10, 0);
			if (fdf->pkeys.e)
				fmap_move(&fdf->map, 0, 10, 0);
		}
		else
		{
			if (fdf->pkeys.a)
				fmap_rotate(&fdf->map, 0, 0.1f, 0);
			if (fdf->pkeys.d)
				fmap_rotate(&fdf->map, 0, -0.1f, 0);
			if (fdf->pkeys.w)
				fmap_rotate(&fdf->map, -0.1f, 0, 0);
			if (fdf->pkeys.s)
				fmap_rotate(&fdf->map, 0.1f, 0, 0);
			if (fdf->pkeys.q)
				fmap_rotate(&fdf->map, 0, 0, -0.1f);
			if (fdf->pkeys.e)
				fmap_rotate(&fdf->map, 0, 0, 0.1f);
		}
		if (fdf->pkeys.up)
			fmap_scale(&fdf->map, 1, 1, 1.05f);
		if (fdf->pkeys.down)
			fmap_scale(&fdf->map, 1, 1, 0.95f);
	/*
		if (key == KC_Up)
			fmap_scale(&fdf->map, 1, 1, 1.05f);
		else if (key == KC_Down)
			fmap_scale(&fdf->map, 1, 1, 0.95f);
		else if (key == KC_a || key == KC_A)
			fmap_rotate(&fdf->map, 0, 0.1f, 0);
		else if (key == KC_d || key == KC_D)
			fmap_rotate(&fdf->map, 0, -0.1f, 0);
		else if (key == KC_w || key == KC_W)
			fmap_rotate(&fdf->map, -0.1f, 0, 0);
		else if (key == KC_s || key == KC_S)
			fmap_rotate(&fdf->map, 0.1f, 0, 0);
		else if (key == KC_q || key == KC_Q)
			fmap_rotate(&fdf->map, 0, 0, -0.1f);
		else if (key == KC_e || key == KC_E)
			fmap_rotate(&fdf->map, 0, 0, 0.1f);
	*/
	}
	if (fdf->is_animation_active)
	{
		fmap_rotate(&fdf->map, 0, 0.01f, 0);
//		camo_rotate(&fdf->cam2, 0.01f, 0, 0);
//		update_map(fdf, 1);
//		on_rotate_y(fdf, 0.01);
//		update_map_no_cam(fdf);
	}	
	update_map(fdf, 1);
	return (0);
}

#define YL "\033[11;33m"
#define CY "\033[1;36m"
#define WT "\033[1;37m"
#define RS "\033[0;37m"
void	print_controls(void)
{
	ft_printf(WT"()"CY"-------------------------------( *** )------------------------------"WT"()\n");
	ft_printf(
 " ||"YL"       _|_|_|_|  _|_|_|    _|_|_|_|                                 "WT"||\n\
  ||"YL"      _|        _|   _|   _|                                        "WT"||\n\
   ||"YL"     _|_|_|    _|    _|  _|_|_|                                     "WT"||\n\
  ||"YL"      _|        _|   _|   _|                                        "WT"||\n\
 ||"YL"       _|        _|_|_|    _|      "WT"- A Multi-Perspective Visualizer "WT"||\n");
	ft_printf(WT"()"CY"-------------------------------( *** )------------------------------"WT"()\n"RS);

	ft_printf(WT"||"YL" + \tThis program is a multi-perspective map visualizer.\n");
	ft_printf(WT"||"YL" + It takes .fdf files (exemples in maps/) and displays them in a 4 quadrant window.\n");
	ft_printf(WT"||"YL" + The 2 top quadrants show the loaded map with perspective projections.\n");
	ft_printf(WT"||"YL" + The bottom ones show the map with orthographic projections.\n");
	ft_printf(WT"||"YL" + Each quadrant displays THE SAME model, only from different positions/orientations.\n");
	ft_printf(WT"||"YL" +\n") ;
	ft_printf(WT"||"YL" + \tThe models displayed are the result of the full set of transformations\n");
	ft_printf(WT"||"YL" + from model transform -> camera transform -> viewport transform and each\n"); 
	ft_printf(WT"||"YL" + stage is fully customizable, while model/camera transforms are interactable\n");
	ft_printf(WT"||"YL" + with in real time.\n");
	ft_printf(WT"||"YL" +\n") ;
	ft_printf(WT"||"YL" + \tOptionally, a 2nd map file can be passed as argument so that both are drawn\n");
	ft_printf(WT"||"YL" + on screen (beacon.fdf strongly suggested). Seeing a second model on screen helps\n") ;
	ft_printf(WT"||"YL" + anchor a point of spacial reference so that the movements applied to the first \n") ;
	ft_printf(WT"||"YL" + one are easier to understand in contexte.\n") ;
	ft_printf(WT"||"YL" +\n") ;
	ft_printf(WT"||"YL" + \tNow it's your time to take control. The visualizer operates in 2 distinct modes.\n");
	ft_printf(WT"||"YL" + Switch between modes by pressing the SPACEBAR. Stop animation with DELETE.\n");
	ft_printf(WT"||"YL" +\n") ;
	ft_printf(WT"||"YL" + \t1. Model control (where X is left, Y is up, Z is forward) :\n");
	ft_printf(WT"||"YL" + \t\t         A | D   : Rotate the model around the Y axis\n");
	ft_printf(WT"||"YL" + \t\t         W | S   : Rotate the model around the X axis\n");
	ft_printf(WT"||"YL" + \t\t         Q | E   : Rotate the model around the Z axis\n");
	ft_printf(WT"||"YL" + \t\t SHIFT + A | D   : Move the model along the X axis\n");
	ft_printf(WT"||"YL" + \t\t SHIFT + W | S   : Move the model along the Z axis\n");
	ft_printf(WT"||"YL" + \t\t SHIFT + Q | E   : Move the model along the Y axis\n");
	ft_printf(WT"||"YL" + \t\t Arrows UP | DN  : Stretch the model in the Z direction relative to itself.\n");
	ft_printf(WT"||"YL" +\n") ;
	ft_printf(WT"||"YL" + \t2. Camera control (relative to current orientation, applied to quadrant 1) :\n");
	ft_printf(WT"||"YL" + \t\t         A | D   : Strafe the camera left, right\n");
	ft_printf(WT"||"YL" + \t\t         W | S   : Move the camera forwards and backwards\n");
	ft_printf(WT"||"YL" + \t\t     SHIFT | CTRL: Move the camera forwards and backwards\n");
	ft_printf(WT"||"YL" + \t\t         Q | E   : Rotate the camera around its relative Z axis (Tilt)\n");
	ft_printf(WT"||"YL" + \t\t       LFT | RGT : Rotate the camera around its relative Y axis\n");
	ft_printf(WT"||"YL" + \t\t        UP | DN  : Rotate the camera around its relative X axis\n");
	ft_printf(WT"||"YL" +\n") ;
	ft_printf(WT"||"YL" + \tMouse (Camera mode only) :\n");
	ft_printf(WT"||"YL" + \t\t        CLICK + MOVE : Rotates the camera around the X and Y axies.\n");
	ft_printf(WT"||"YL" + \n");
	ft_printf(WT"||"YL" + \tOthers :\n");
	ft_printf(WT"||"YL" + \t\t        SPACEBAR : Switch control modes.\n");
	ft_printf(WT"||"YL" + \t\t        DELETE   : Switch animation on/off.\n");
	ft_printf(WT"||"YL" + \n");
	ft_printf(WT"()"CY"-------------------------------( *** )------------------------------"WT"()\n\n"RS);
}

int	main(int argc, char **argv)
{
//	static const float	init_cam_pos[3] = {SCN_MID_X, SCN_MID_Y, 0};
	static const float	init_cam_dimentions[2] = {SCN_WIDTH, SCN_HEIGHT};
	static const float	init_cam_farnear[2] = {0.01, 400};
	
	static const float	init_cam1_pos[3] = {0, 0, -1200};
	static const float	init_cam1_thetas[3] = {0, 0, 0};
	
	static const float	init_cam2_pos[3] = {0, 0, 1000};
	static const float	init_cam2_thetas[3] = {M_PI, 0, 0};
	
	static const float	init_cam3_pos[3] = {0, 0, 0};
	static const float	init_cam3_thetas[3] = {0, -M_PI / 2, 0};
	
	static const float	init_cam4_pos[3] = {0, 0, 0};
	static const float	init_cam4_thetas[3] = {M_PI / 2, 0, 0};
	
	static const int	init_viewport_offset1[2] = {12, 12};
	static const int	init_viewport_offset2[2] = {SCN_MID_X + 6, 12};
	static const int	init_viewport_offset3[2] = {12, SCN_MID_Y + 6};
	static const int	init_viewport_offset4[2] = {SCN_MID_X + 6, SCN_MID_Y + 6};
	static const int	init_viewport_size[2] = {SCN_MID_X - 18, SCN_MID_Y - 18};
	t_fdf	fdf;

	if (argc < 2)
		return (1);
	ft_memclear(&fdf, sizeof(t_fdf));
	if (fdf_load_map(argv[1], &fdf.map) < 0)
		return (2);
	if (argc == 3 && fdf_load_map(argv[2], &fdf.beacon))
		return (fdf_clear(&fdf, 2));
//	init_cam_frame_obj(&fdf.frame);
	if (!mlx_init_double_buff_window(&fdf.mlx, 
			SCN_WIDTH, SCN_HEIGHT, WIN_TITLE))
		return (fdf_clear(&fdf, 3));
	
//	printf("map loaded and mlx init\n");

	scale_map_to_window(&fdf.map);
//	scale_map_to_window(&fdf.beacon);
	fmap_scale(&fdf.beacon, 10, 10, 10);
	fmap_set_rotation(&fdf.map, ISO_X_THETA, ISO_Y_THETA, 0);
	fmap_set_rotation(&fdf.beacon, M_PI / 2, 0, 0);
//	fmap_set_position(&fdf.map, 0, 0, 100);
	fmap_set_position(&fdf.beacon, 200, 0, 200);
//	fmap_set_scale(&fdf.beacon, 10, 10, 10);


//	printf("transform DONE\n");
	fdf.is_animation_active = 1;
	fdf.bg_col = BG_COL;
//	printf("fdf main : starting cam inits\n");
	camo_init(&fdf.cam1, init_cam1_pos, init_cam_dimentions, init_cam_farnear, init_cam1_thetas, CAM_PERSPECTIVE);
	camo_init(&fdf.cam2, init_cam2_pos, init_cam_dimentions, init_cam_farnear, init_cam2_thetas, CAM_PERSPECTIVE);
	camo_init(&fdf.cam3, init_cam3_pos, init_cam_dimentions, init_cam_farnear, init_cam3_thetas, CAM_ORTHO);
	camo_init(&fdf.cam4, init_cam4_pos, init_cam_dimentions, init_cam_farnear, init_cam4_thetas, CAM_ORTHO);
	viewport_init(&fdf.vp1, init_viewport_offset1, init_viewport_size);
	viewport_init(&fdf.vp2, init_viewport_offset2, init_viewport_size);
	viewport_init(&fdf.vp3, init_viewport_offset3, init_viewport_size);
	viewport_init(&fdf.vp4, init_viewport_offset4, init_viewport_size);
//	printf("hook onclose DONE\n");
//	camo_rotate(&fdf.cam1, ISO_X_THETA, ISO_Y_THETA, 0);
//	camo_set_offset(&fdf.cam1, 0, 0, 0);
	
//	update_map(&fdf, 1);
//	update_map_no_cam(&fdf);
	print_controls();

//	mlx_key_hook(fdf.mlx.win, fdf_modelmode_key_switch, &fdf);
	mlx_hook(fdf.mlx.win, ON_DESTROY, 0, on_close, &fdf.mlx);
	mlx_hook(fdf.mlx.win, ON_KEYUP, (1L<<1), on_keyup, &fdf);
	mlx_hook(fdf.mlx.win, ON_KEYDOWN, (1L<<0), on_keydown, &fdf);
	mlx_hook(fdf.mlx.win, ON_MOUSEUP, (1L << 3), on_mouse_release, &fdf);
	mlx_hook(fdf.mlx.win, ON_MOUSEDOWN, (1L << 2), on_mouse_press, &fdf);
	mlx_hook(fdf.mlx.win, ON_MOUSEMOVE, (1L << 6), on_mouse_drag, &fdf);
	
	mlx_loop_hook(fdf.mlx.conn, on_update, &fdf);	
	mlx_loop(fdf.mlx.conn);	
	
	return (fdf_clear(&fdf, EXIT_SUCCESS));
}
