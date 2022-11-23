/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_index_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:52:22 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/21 20:00:33 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

int	*mlx_index_buffer(t_img *buff, int x, int y)
{
	char	*cpix;
	int		*pix;

	cpix = (buff->addr + (y * buff->line_len) + (x * buff->bytes_per_pxl));
	pix = (int *)cpix;
	return (pix);
}
