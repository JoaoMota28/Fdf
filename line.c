/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:19:44 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/26 18:32:39 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slope_less_than_one(t_param *param, int dx, int dy, t_point *a)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	my_mlx_pixel_put(param, a->x, a->y, a->color);
	while (++i < abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		my_mlx_pixel_put(param, a->x, a->y, a->color);
	}
}

void	slope_more_than_one(t_param *param, int dx, int dy, t_point *a)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dx) - abs(dy);
	my_mlx_pixel_put(param, a->x, a->y, a->color);
	while (++i < abs(dy))
	{
		if (dy > 0)
			a->y += 1;
		else
			a->y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				a->x += 1;
			else
				a->x -= 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		my_mlx_pixel_put(param, a->x, a->y, a->color);
	}
}

void	draw_line(t_param *param, t_point *point1, t_point *point2)
{
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = point2->x - point1->x;
	dy = point2->y - point1->y;
	x = point1->x;
	y = point1->y;
	if (abs(dx) > abs(dy))
		slope_less_than_one(param, dx, dy, point1);
	else
		slope_more_than_one(param, dx, dy, point1);
	point1->x = x;
	point1->y = y;
}

void	draw_map(t_param *param)
{
	int		i;
	int		j;
	int		val;
	t_point	**p_arr;

	i = 0;
	p_arr = param->map->points;
	while (i < param->map->height)
	{
		j = 0;
		while (j < param->map->width)
		{
			val = param->map->width;
			if (j < param->map->width - 1)
				draw_line(param, p_arr[i * val + j], p_arr[i * val + j + 1]);
			if (i < param->map->height - 1)
				draw_line(param, p_arr[i * val + j], p_arr[(i + 1) * val + j]);
			j++;
		}
		i++;
	}
}
