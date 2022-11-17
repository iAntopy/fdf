/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 05:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 22:56:21 by iamongeo         ###   ########.fr       */
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
# include "keycodesdef.h"
# include "mtxlib.h"

# define FDF_ERROR(err) fdf_err((char *)__FUNCTION__, (char *)(err))
# define FDF_ERR_CLR_LST(err, l) fdf_e_clr_str_list((char *)__FUNCTION__, \
		(char *)(err), (t_lst *)(l))

typedef struct	s_fdf_map
{
	int		w;
	int		h;
	t_mtx	*coords;
}	t_fmap;


// FDF INIT
t_mtx	*fdf_map_loader(int fd);

// ERROR HANDLING

void	*fdf_err(char *ori, char *err);
void	*fdf_e_clr_str_list(char *ori, char *err, t_lst *lst);
void	clear_str_tab(char **tab);

#endif

