/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:53 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/22 10:43:51 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1080
# define WIDTH 1920

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
# include "minilibx-linux/mlx.h"

typedef struct s_map
{
	int	height;
	int	width;
	int	*map_coords;
	int *map_color;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef	struct s_param
{
	t_map	*map;
	t_mlx	*mlx;
}	t_param;

int	check_name(char *file);
int check_map(char *file);
int	get_width(t_map *map, char *file);
int	get_height(t_map *map, char *file);
int check_map_and_save(t_map *map, char *file);

#endif