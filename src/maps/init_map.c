/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:06:18 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/28 18:40:17 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_3dpoint(t_map *map, char **arr, int *row_idx, int *col_idx)
{
	t_3dpoint	*point;
	char		*hex_color;
	int			altitude;

	point = (t_3dpoint *)malloc(sizeof(t_3dpoint));
	altitude = ft_atoi(arr[*col_idx]);
	point->x = *col_idx * 30;
	point->y = *row_idx * 30;
	point->z = altitude;
	hex_color = ft_strchr(arr[*row_idx * map->max_width + *col_idx], ',');
	if (hex_color == NULL)
		point->color = ft_atoi_base("0xFFFFFFFF", HEX_BASE);
	else
		point->color = ft_atoi_base(hex_color + 1, HEX_BASE);
	map->matrix[*row_idx * map->max_width + *col_idx] = point;
	(*col_idx)++;
}

static void	set_map_size(char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	**arr_str;
	char	*line;

	map->height = 0;
	map->max_width = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		arr_str = ft_split(line, " ");
		while (arr_str[i] != NULL)
			i++;
		if (i > map->max_width)
			map->max_width = i;
		map->height++;
		free(line);
		free(arr_str);
	}
	close(fd);
}

static t_3dpoint	**matrix_alloc(int max_width, int height)
{
	return ((t_3dpoint **)malloc(max_width * height * sizeof(t_3dpoint *)));
}

void	insert_point(t_map *map, char **split_line, int *row_idx, int *col_idx)
{
	if (split_line[*col_idx] == NULL)
	{
		while (*col_idx < map->max_width)
		{
			map->matrix[*row_idx * map->max_width + *col_idx] = NULL;
			(*col_idx)++;
		}
		return ;
	}
	set_3dpoint(map, split_line, row_idx, col_idx);
}

void	init_map(char **argv, t_mlx_data *fdf)
{
	int		fd;
	int		col_idx;
	int		row_idx;
	char	**split_line;

	fd = open(*argv, O_RDONLY);
	set_map_size(*argv, &fdf->map);
	fdf->map.matrix = matrix_alloc(fdf->map.max_width, fdf->map.height);
	row_idx = 0;
	split_line = ft_split(fdf->file_line, " \n");
	while (row_idx < fdf->map.height)
	{
		col_idx = 0;
		while (col_idx < fdf->map.max_width)
			insert_point(&fdf->map, split_line, &row_idx, &col_idx);
		row_idx++;
	}
	free_arr(split_line);
	close(fd);
}
