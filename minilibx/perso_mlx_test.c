/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso_mlx_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:57:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/20 05:31:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

typedef struct s_mlx_context
{
	void	*mlx;
	void	*win;
}	t_mlx;

int	close_window(t_mlx *mlx)
{
	printf("DESTROYING WINDOW ! GOODBYE !\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	display_keycode(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		close_window(mlx);
	printf("keycode : %d\n", keycode);
}

int	main()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "I can't believe it's minilibx !");
	mlx_hook(mlx.win, 2, (1L<<0), display_keycode, &mlx);
	mlx_hook(mlx.win, 10, (1L<<5), close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
