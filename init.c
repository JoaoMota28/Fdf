/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:17:15 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/26 18:00:34 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(t_param *param)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		close_window(param, "Error: Failed memory allocation.\n");
	map->height = 0;
	map->width = 0;
	map->points = NULL;
	param->map = map;
	return (map);
}

t_mlx	*init_mlx(t_param *param, char *map)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		close_window(param, "Error: Failed memory allocation.\n");
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, map);
	param->mlx = mlx;
	return (mlx);
}

t_img	*init_img(t_param *param)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		close_window(param, "Error: Failed memory allocation.\n");
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->l_len = 0;
	img->end = 0;
	param->img = img;
	return (img);
}

t_param	*init_param(void)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		close_window(param, "Error: Failed memory allocation.\n");
	param->map = NULL;
	param->mlx = NULL;
	param->img = NULL;
	return (param);
}
