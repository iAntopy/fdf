/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:08:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 22:58:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_clear(t_fdf *fdf, int exit_code)
{
	printf("clear : entered\n");
	if (fdf->map.coords)
		mtx_clear(&fdf->map.coords);
	printf("clear : coords cleared\n");
//	mlx_close(&fdf->mlx);
//	printf("clear : mlx cleared\n");
	return (exit_code);
}


static void	scale_map_to_window(t_fmap *map)
{
	float	_arr[8];
	t_mtx	mins;
	t_mtx	maxs;
	t_mtx	view_xyz;
	float	ratio;

	mins.arr = _arr;
	maxs.arr = _arr + 4;
	mtx_shell(&mins, 4, 1, DTYPE_F);
	mtx_shell(&maxs, 4, 1, DTYPE_F);
	
	mtx_min(map->coords, ROWWISE, &mins);
	mtx_max(map->coords, ROWWISE, &maxs);
//	_arr[8] = _arr[4] - _arr[0];
//	_arr[9] = _arr[5] - _arr[1];
	mtx_select_col_range(map->coords, 0, 3, &view_xyz);
	if ((_arr[0] / SCN_WIDTH) > (_arr[1] / SCN_HEIGHT))
	{
		ratio = SCN_MID_X * 0.8;
		_mtx_idivf_pscalar(&view_xyz, _arr[0]);
	}
	else
	{
		ratio = SCN_MID_Y * 0.8;
		_mtx_idivf_pscalar(&view_xyz, _arr[1]);
	}
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
	quat_combine(q1, &q2, q1);
	printf("transform and scale : combine DONE \n");

	mean = mtx_mean(map->coords, ROWWISE, NULL);
	*(float *)mtx_index(mean, 3, 0) = 0.0f;
	mtx_sub(map->coords, mean, map->coords);
	printf("transform and scale : translation set \n");
	quat_display_info(q1);
	quat_irotate(map->coords, &map->transform);
//	mtx_inormalize(map->coords);
	scale_map_to_window(map);
	_quat_translation_set(&map->transform, SCN_MID_X, SCN_MID_Y, 0);
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
//	if (mlx_init_double_buff_window(&fdf.mlx, 
//			SCN_WIDTH, SCN_HEIGHT, WIN_TITLE) < 0)
//		return (fdf_clear(&fdf, 3));
	
	mtx_print(fdf.map.coords);
	transform_and_scale_map_to_window(&fdf.map);
//	mlx_loop(&fdf.mlx);	
	return (fdf_clear(&fdf, EXIT_SUCCESS));
}
