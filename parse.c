/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:18:00 by jomanuel          #+#    #+#             */
/*   Updated: 2025/03/22 10:44:10 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_name(char *map)
{
	int	len;

	if (!map)
		return (-1); //terminate("Error: Invalid map file.")
	len = ft_strlen(map);
	return(ft_strncmp(map + len - 4, ".fdf", 4));
}

int	get_line_size(char *line)
{
	int	i;
	char **array;

	i = 0;
	if (!line)
		return (0);
	array = ft_split(line, ' ');
	if (!array)
		return (0);
	while (array[i])
		i++;
	ft_freeall(array);
	return (i);
}

int	validate_map_size(t_map *map, char *file)
{
	int i;
	int	fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1); //terminate("Error: Invalid map file.")
	line = get_next_line(fd);
	map->width = get_line_size(line);
	while (line)
	{
		i++;
		if (get_line_size(line) != map->width)
			return (-1); //free(line), close(fd), terminate("Error: Map lines must have same width.")
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->height = i;
	return (i);
}

unsigned int	conv_hex_to_int(char *str)
{
	unsigned int	res;

	res = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 16 + *str - '0';
		if (*str >= 'A' && *str <= 'F')
			res = res * 16 + *str - 'A' + 10;
		if (*str >= 'a' && *str <= 'f')
			res = res * 16 + *str - 'a' + 10;
		str++;
	}
	return (res);
}

int check_map_and_save(t_map *map, char *file)
{
	int	fd;
	char	*line;
	char	**arr;
	char	**block;
	int	i;
	int	j;

	i = 0;
	line = NULL;
	block = NULL;
	if (check_name(file))
		return (-1); //terminate("Error: Invalid map file.")
	if (!validate_map_size(map, file))
		return (-1); //terminate("Error: Invalid map file.")
	map->map_coords = ft_calloc(map->height * map->width, sizeof(int));
	if (!map->map_coords)
		return (-1);
	map->map_color = ft_calloc(map->height * map->width, sizeof(int));
	if (!map->map_color)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1); //terminate("Error: Invalid map file.")
	while (i < map->height)
	{
		j = 0;
		line = get_next_line(fd);
		arr = ft_split(line, ' ');
		free(line);
		if (!arr)
			return (-1);
		while (j < map->width)
		{
			block = ft_split(arr[j], ',');
			if (!block)
				return (-1);
			map->map_coords[map->width * i + j] = ft_atoi(block[0]);
			if (!block[1])
			map->map_color[map->width * i + j] = conv_hex_to_int("0xFFFFFF");
			else
				map->map_color[map->width * i + j] = conv_hex_to_int(block[1]);
			ft_freeall(block);
			j++;
		}
		ft_freeall(arr);
		i++;
	}
	return (0);
}
