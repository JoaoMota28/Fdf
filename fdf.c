/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:57 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/22 10:43:33 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map()
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	//Terminate if memory allocation fails
	map->height = 0;
	map->width = 0;
	map->map_coords = NULL;
	map->map_color = NULL;
	return (map);
}

t_mlx	*init_mlx(char *map)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	// Terminate if memory allocation fails
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, map);
	return (mlx);
}

void	free_map(t_map *map)
{
	free(map->map_color);
	free(map->map_coords);
	free(map);
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}

t_param	*init_param(t_map *map, t_mlx *mlx)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	param->map = map;
	param->mlx = mlx;
	return (param);
}

int	close_window(t_param *param)
{
	free_map(param->map);
	free_mlx(param->mlx);
	free(param);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_param	*param;

	if (argc != 2)
		exit(1); //terminate with error message
	map = init_map();
	mlx = init_mlx(argv[1]);
	param = init_param(map, mlx);
	check_map_and_save(map, argv[1]);
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			printf("%i,%i ", map->map_coords[map->width * i + j], map->map_color[map->width * i + j]);
		}
		printf("\n");
	}
	mlx_hook(mlx->window, 17, 0, close_window, param);
	mlx_loop(mlx->mlx);
	return (0);
}
