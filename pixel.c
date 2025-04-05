/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:39:09 by jomanuel          #+#    #+#             */
/*   Updated: 2025/04/03 18:02:25 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *point)
{
	int	tmp_x;

	tmp_x = point->x;
	point->x = (tmp_x - point->y) * cos(0.523599);
	point->y = (tmp_x + point->y) * sin(0.523599) - point->z;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	adjust_points(t_param *param)
{
	t_point	*point;
	t_map	*map;
	int		i;
	int		j;
	int		scale;

	i = 0;
	map = param->map;
	scale = max(map->height / (HEIGHT / 100), map->width / (WIDTH / 100));
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			point = map->points[map->width * i + j];
			point->x = point->x * MULT / scale;
			point->y = point->y * MULT / scale;
			point->z = point->z * MULT / Z_SCALE;
			isometric(point);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_param *param, int x, int y, int color)
{
	int		offset;
	int		scr_x;
	int		scr_y;
	char	*dst;

	scr_x = x + WIDTH / 2;
	scr_y = y + HEIGHT / 5;
	if (scr_x < 0 || scr_x >= WIDTH || scr_y < 0 || scr_y >= HEIGHT)
		return ;
	else
	{
		offset = scr_y * param->img->l_len + scr_x * (param->img->bpp / 8);
		dst = param->img->addr + offset;
		*(unsigned int *)dst = color;
	}
}
