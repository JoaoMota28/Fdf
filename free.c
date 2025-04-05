/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:18:51 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/26 17:59:47 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = map->height * map->width;
	if (map->points != NULL)
	{
		while (i > 0)
			free(map->points[--i]);
	}
	free(map->points);
	free(map);
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
}

void	free_img(t_img *img, t_mlx *mlx)
{
	if (img->addr != NULL)
		mlx_destroy_image(mlx->mlx, img->img);
	free(img);
}

int	close_window(t_param *param, char *msg)
{
	if (param->img)
		free_img(param->img, param->mlx);
	if (param->map)
		free_map(param->map);
	if (param->mlx)
		free_mlx(param->mlx);
	if (param)
		free(param);
	if (msg != NULL)
	{
		ft_putstr_fd(msg, 2);
		exit(1);
		return (1);
	}
	exit(0);
	return (0);
}
