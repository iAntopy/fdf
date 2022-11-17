/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_transform_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 03:28:01 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 05:00:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

float	cube_verts[8][4] = {	
				{0, 0, 0, 1},
				{1, 0, 0, 1},
				{1, 1, 0, 1},
				{0, 1, 0, 1},
				{0, 0, 1, 1},
				{1, 0, 1, 1},
				{1, 1, 1, 1},
				{0, 1, 1, 1}	};



int	main(void)
{
	t_mtx		*cube;
	t_mtx		*eye;
	t_mtx		*temp_row;
	t_mtx		*last_col;
	t_mtx		*cube_transform;
	t_mtx		*cube_translation;
	t_mtx		*rot_mat;
	t_mtx		*world_cube;


	cube = mtx_create_array(cube_verts, 8, 4, DTYPE_F);
	temp_row = mtx_mean(cube, ROWWISE, NULL);

	_mtx_isubf_line_r(cube, temp_row);

	printf("Cube around origin : \n");
	mtx_print(cube);
	mtx_display_info(cube);
	
	last_col = mtx_select_col(cube, 3);
	_mtx_iaddf_pscalar(last_col, 1.0f);
	printf("Cube around with all ones in 4th col : \n");
	mtx_print(cube);
	mtx_display_info(cube);


	const int	slc[4] = {3, 0, 4, 3};
	eye = mtx_identity(4, NULL, DTYPE_F);
	rot_mat = mtx_get_rotmat_4x4(M_PI / 4, 0, 0, NULL);
	printf("Rotation matrix 45 degrees :\n");
	mtx_print(rot_mat);

	cube_transform = mtx_dot(eye, rot_mat, NULL);
	cube_translation = mtx_slice_view(cube_transform, slc);

	_mtx_iaddf_pscalar(cube_translation, 100.5f);
	printf("cube_transform post rotation : \n");
	mtx_print(cube_transform);

	printf("create world_cube and apply transform\n");
	mtx_dup_empty(cube, &world_cube, DTYPE_F);
	__mtx_dotf_nx4_4x4(8, cube->arr, cube_transform->arr, world_cube->arr);
	printf("cube after applied transform\n");
	mtx_print(world_cube);


	mtx_clear_list(6, cube, temp_row, eye, last_col, cube_transform, cube_translation, world_cube);
	return (0);
}
