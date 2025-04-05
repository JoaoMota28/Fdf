/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:53 by jomanuel          #+#    #+#             */
/*   Updated: 2025/04/03 16:00:59 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1080
# define WIDTH 1920
# define ESC_KEY 65307
# define MULT 50
# define Z_SCALE 5

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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	**points;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		end;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_param
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*img;
}	t_param;

t_param			*init_param(void);
t_map			*init_map(t_param *param);
t_mlx			*init_mlx(t_param *param, char *map);
t_img			*init_img(t_param *param);
unsigned int	conv_hex_to_int(char *str);
char			*ft_strrem(const char *s, const char *rem);
void			check_map_and_save(t_param *param, t_map *map, char *file);
void			adjust_points(t_param *param);
void			my_mlx_pixel_put(t_param *param, int x, int y, int color);
void			draw_map(t_param *param);
int				close_window(t_param *param, char *msg);

#endif