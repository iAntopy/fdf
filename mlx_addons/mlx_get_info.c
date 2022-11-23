/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:24:28 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/20 21:31:48 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_get_info(t_mlx *mlx)
{
	printf("@@______________( mlx info (%p))______________@@\n", mlx);
	printf("@@	- conn ptr :		%p\n", mlx->conn);
	printf("@@	- win ptr :		%p\n", mlx->win);
	printf("@@	- width, height :	<%d, %d>\n", mlx->width,
		mlx->height);
	printf("@@	- nb_pix :		%zu\n", mlx->nb_pix);
	printf("@@	- buff size :		%zu\n", mlx->buff_size);
	printf("@@	- screen_buff ptr:	%p\n", mlx->scn_buff->img);
	printf("@@	- draw_buff ptr:	%p\n", mlx->off_buff->img);
	printf("@@____________________.o@o.___________________@@\n\n");
}
