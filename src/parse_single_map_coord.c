/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_map_coord.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:02:59 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/21 20:01:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtx	*fdf_parse_single_map_coord(t_mtx *coords, int row, int col, char *str)
{
	char	**split_coord;
	int		height;
	float	color;

	color = 0xffffffff;
	if (!str || !str[0])
		return (NULL);
	if (ft_strchr(str, 'x'))
	{
		icolor = (float)ft_atoi_base(ft_strchr(str, 'x') + 1, 16, X_BASE);
		height = ft_atoi(str);
		mtx_index(coords, );
		
	}
	icolor = get_

	return (coords);
}
