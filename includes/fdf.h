/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 05:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/18 22:05:40 by iamongeo         ###   ########.fr       */
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
# include "keycodesdef.h"
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

typedef struct	s_fdf_map
{
	int		w;
	int		h;
	t_mtx	*coords;
	t_quat	transform;
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

