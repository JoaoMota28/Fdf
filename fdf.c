/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:57 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/26 19:40:21 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	escape_click(int keycode, t_param *param)
{
	if (keycode == ESC_KEY)
		close_window(param, NULL);
	return (0);
}

int	x_click(t_param *param)
{
	close_window(param, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*img;
	t_param	*param;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		exit(1);
	}
	param = init_param();
	map = init_map(param);
	mlx = init_mlx(param, argv[1]);
	img = init_img(param);
	check_map_and_save(param, map, argv[1]);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->end);
	adjust_points(param);
	draw_map(param);
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->img, 0, 0);
	mlx_hook(mlx->window, 2, 1L << 0, escape_click, param);
	mlx_hook(mlx->window, 17, 0, x_click, param);
	mlx_loop(mlx->mlx);
	return (0);
}
