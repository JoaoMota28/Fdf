/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:18:00 by jomanuel          #+#    #+#             */
/*   Updated: 2025/04/03 17:02:23 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_name(t_param *param, char *map)
{
	int	len;

	if (!map)
		close_window(param, "Error: Invalid map file.\n");
	len = ft_strlen(map);
	return (ft_strncmp(map + len - 4, ".fdf", 4));
}

int	get_line_size(t_param *param, char *line)
{
	int		i;
	char	*trim;
	char	**array;

	i = 0;
	if (!line)
		close_window(param, "Error: Invalid map size.\n");
	trim = ft_strtrim(line, "\n");
	array = ft_split(trim, ' ');
	if (!array)
	{
		free(trim);
		free(line);
		close_window(param, "Error: Invalid map size.\n");
	}
	while (array[i])
		i++;
	ft_freeall(array);
	free(trim);
	return (i);
}

int	validate_map_size(t_param *param, t_map *map, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		close_window(param, "Error: Invalid map file.\n");
	line = get_next_line(fd);
	map->width = get_line_size(param, line);
	while (line && line[0] != '\n')
	{
		i++;
		if (get_line_size(param, line) != map->width)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	map->height = i;
	return (free(line), close(fd), 0);
}

void	save_line(t_param *param, t_map *map, char **arr, int i)
{
	int		j;
	int		index;
	char	**block;

	block = NULL;
	j = -1;
	while (++j < map->width)
	{
		block = ft_split(arr[j], ',');
		index = map->width * i + j;
		if (!block)
			close_window(param, "Error: Failed to allocate memory.\n");
		map->points[index] = malloc(sizeof(t_point));
		if (!map->points[index])
			close_window(param, "Error: Failed to allocate memory.\n");
		map->points[index]->x = j;
		map->points[index]->y = i;
		map->points[index]->z = ft_atoi(block[0]);
		if (!block[1])
			map->points[index]->color = conv_hex_to_int("0xFFFFFF");
		else
			map->points[index]->color = conv_hex_to_int(block[1]);
		ft_freeall(block);
	}
	ft_freeall(arr);
}

void	check_map_and_save(t_param *param, t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	**arr;
	int		i;

	i = -1;
	line = NULL;
	if (check_name(param, file) || validate_map_size(param, map, file))
		close_window(param, "Error: Invalid map file.\n");
	map->points = malloc(map->height * map->width * sizeof(t_point *));
	if (!map->points)
		close_window(param, "Error: Failed to allocate memory.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		close_window(param, "Error: Failed to open map file.\n");
	while (++i < map->height)
	{
		line = get_next_line(fd);
		arr = ft_split(line, ' ');
		free(line);
		if (!arr)
			close_window(param, "Error: Failed to allocate memory.\n");
		save_line(param, map, arr, i);
	}
}
