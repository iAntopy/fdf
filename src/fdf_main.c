/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:08:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 06:19:08 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_clear(t_fdf *fdf, int exit_code)
{
	fmap_clear(&fdf->fmap);
	mlx_clear(&fdf->mlx);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2)
		return (1);

	if (fdf_load_map(argv[1], &fdf.map) < 0)
		return (2);
	if (mlx_init_double_buffer_window(&fdf.mlx, SCN_WIDTH, SCN_HEIGHT, "Fil de Fer") < 0)
		return (fdf_clear(&fdf, 3));
	
	return (fdf_clear(&fdf, EXIT_SUCCESS));
}
