/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 05:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/21 02:26:59 by iamongeo         ###   ########.fr       */
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
# define ISO_Y_THETA 0.785398163397
//# define ISO_X_THETA 0.785398163397
# define ISO_X_THETA 0.61547970867

# define BG_COL 0x31176e

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

typedef struct	s_fdf_data
{
	t_mlx	mlx;
	t_fmap	map;
}	t_fdf;

// FDF INIT
int	fdf_load_map(char *map_name, t_fmap *map);

// ERROR HANDLING

void	*fdf_err(char *ori, char *err);
void	*fdf_e_clr_str_list(char *ori, char *err, t_lst *lst);
void	clear_str_tab(char **tab);

#endif

