/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 05:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/25 18:42:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define XK_MISCELLANY
# define XK_LATIN1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# include "mlx.h"
# include "mlxadds.h"
# include "keycodes.h"
# include "mtxlib.h"

# define FDF_ERROR(err) fdf_err((char *)__FUNCTION__, (char *)(err))
# define FDF_ERR_CLR_LST(err, l) fdf_e_clr_str_list((char *)__FUNCTION__, \
		(char *)(err), (t_lst *)(l))

# define SCN_WIDTH 840
# define SCN_HEIGHT 680
# define SCN_MID_X (SCN_WIDTH / 2)
# define SCN_MID_Y (SCN_HEIGHT / 2)

# define WIN_TITLE "Fil de Fer"
# define ISO_Y_THETA 0.785398163397f
//# define ISO_X_THETA 0.785398163397
# define ISO_X_THETA 0.61547970867f

//# define BG_COL 0x31176e
# define BG_COL 0x0b1c5e
# define BG_COL2 0x423f3a

typedef struct	s_fdf_map
{
	int		w;
	int		h;
	t_mtx	*coords;
	t_mtx	*screen_coords;
	t_mtx	*scalars;

	t_quat	*transform;
	t_quat	*y_transform;
	t_quat	*x_transform;
	t_quat	__qpool[3];
	t_mtx	__scalars;
	float	__scalars_arr[4];

}	t_fmap;

typedef struct	s_fdf_orthogonal_camera
{
	t_mtx	*pos;
	float	thetas[3];
	t_mtx	*transform;
	t_quat	*rot;
	t_mtx	*base_projection;
//	t_quat	*x_transform;
//	t_quat	*y_transform;
//	t_quat	*z_transform;
	t_mtx	__mtx_pool[3];
	t_quat	__qpool[1];
	float	__pos_arr[4];
	float	__base_arr[16];
	float	__transform_arr[16];
	float	ortho_ratio_x;
	float	ortho_ratio_y;
	float	ortho_ratio_z;
}	t_camo;

typedef struct	s_viewport
{
	t_mlx	*mlx;
	int		ox;
	int		oy;
	int		w;
	int		h;
	float	rev_ortho_ratio_x;
	float	rev_ortho_ratio_y;
	float	rev_ortho_ratio_z;
}

typedef struct	s_fdf_data
{
	t_mlx	mlx;
	t_fmap	map;
	t_camo	cam;
	int	bg_col;
	char	is_animation_active;
	char	is_cam_ctrl_active;
}	t_fdf;

// FDF INIT
int	fdf_load_map(char *map_name, t_fmap *map);
void	mlx_draw_line_z_shift(t_mlx *mlx, int start[3], int end[3]);

// FDF SWITCHS
int	fdf_modelmode_key_switch(int key, void *fdf_p);
int	fdf_cammode_key_switch(int key, void *fdf_p);

// CAMERA CONTROLS
int	camo_init(t_camo *cam, const float *init_pos, const float *init_thetas);
int	camo_update(t_camo *cam);
void	camo_move(t_camo *cam, float dx, float dy, float dz);
void	camo_set_position(t_camo *cam, float x, float y, float z);
void	camo_rotate(t_camo *cam, float rll, float ptc, float yaw);
void	camo_translate(t_camo *cam, float dx, float dy, float dz);
void	camo_set_rotation(t_camo *cam, float rll, float ptc, float yaw);
void	camo_look_at(t_camo *cam, t_mtx *pos);
void	camo_look_at_coord(t_camo *cam, float x, float y, float z);
void	camo_apply_transform(t_camo *cam, t_fmap *model, t_mtx *b, t_mtx *s);

// ERROR HANDLING

void	*fdf_err(char *ori, char *err);
void	*fdf_e_clr_str_list(char *ori, char *err, t_lst *lst);
void	clear_str_tab(char **tab);

#endif

