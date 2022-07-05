/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_dbl_buff_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:38:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/05 02:39:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlxadds.h"
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

#define USECS_PER_FRAME 50000

int	on_close(t_mlx *mlx)
{
	printf("CLOSE EVENT REGISTERED. CLOSING ...");
	if (mlx->screen_buff)
		mlx_destroy_image(mlx->mlx, mlx->screen_buff->img);
	if (mlx->off_buff)
		mlx_destroy_image(mlx->mlx, mlx->off_buff->img);
	mlx->screen_buff = NULL;
	mlx->off_buff = NULL;
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	return (0);
}

int	on_keypress(int keycode, t_mlx *mlx)
{
	static int	draw_count;
	static int	start[2] = {0, 0};
	static int	end[2] = {640 / 2, 480 / 2};

	printf("key %d has been pressed\n", keycode);
	if (keycode == 65307)
	{
		printf("escape has been pressed. CLOSING.");
		return (on_close(mlx));
	}
	else if (keycode == 's')
		mlx_swap_buffers(mlx);
	else if (keycode == 'd')
	{
		start[0] = draw_count % 640;
		printf("start (%d, %d), end (%d, %d)\n", start[0], start[1], end[0], end[1]);
		mlx_clear_buffer(mlx);
		mlx_set_bg_color(mlx, 0x0002066b);
		mlx_draw_line(mlx, start, end, 0x0002d452);
		draw_count += 20;
	}
	else if (keycode == 0xff0d)// ENTER keycode
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->screen_buff->img, 0, 0);
	return (0);
}

int	on_click(int button, int x, int y, t_mlx *mlx)
{
	printf("button %d clicked at (%d, %d)\n", button, x, y);
}

int	on_update(t_mlx *mlx)
{
//	static size_t	count;
	static char	fps_str[16];
	static size_t	chrono;
	static size_t	total_chrono;
	static int	start[2] = {0, 0};
	static int	end[2] = {640 / 2, 480 / 2};
	ssize_t		delta_t;
//	double	dt;
	
	delta_t = ft_timedelta_usec(NULL);
//	printf("delta_t : %zd, delta_t == 0 ? %s\n", delta_t, (delta_t == 0)?"TRUE":"FALSE");

	if (chrono > USECS_PER_FRAME && (total_chrono % 2000000 < 1000000))
	{
//		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_swap_buffers(mlx);
		printf("current screen buff ptr : %p\n", mlx->screen_buff);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->screen_buff, 0, 0);
		sprintf(fps_str, "fps : %zu", 1000000 / chrono);//delta_t);
		printf("fps_str : %s\n", fps_str);
//		mlx_string_put(mlx->mlx, mlx->win, 50, 20, 0x00ffffff, fps_str);
		mlx_draw_line(mlx, start, end, 0x0000ffff);
		chrono = 0;
//		mlx_string_put(mlx->mlx, mlx->win, 50, 20, 0x00ffffff, fps_str);
	}
//	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->screen_buff->img, 0, 0);
//	count++;
	total_chrono += delta_t;
	chrono += delta_t;
	return (0);
}

int	main()
{
	t_mlx	mlx;

	printf("Pre mlx init printf \n");
	mlx_init_dbl_buff_window(&mlx, 640, 480, "No that can't be true");
	printf("line_len : %d, bytes_per_pxl : %d\n", mlx.buff1.line_len, mlx.buff1.bytes_per_pxl);
	printf("Post mlx init printf \n");
	printf("screen_buff ptr : %p, off_buff : %p\n", mlx.screen_buff, mlx.off_buff);
	mlx_hook(mlx.win, ON_DESTROY, 0, on_close, &mlx);
//	mlx_hook(mlx.win, ON_MOUSEDOWN, 0, on_click, &mlx);
	mlx_key_hook(mlx.win, on_keypress, &mlx);
	mlx_mouse_hook(mlx.win, on_click, &mlx);
//	mlx_loop_hook(mlx.mlx, on_update, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
