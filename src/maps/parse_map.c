/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:26:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/30 16:51:47 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_point_in_map(t_map *map, char **arr_points, int row, int col)
{
	t_3dpoint	*point;
	char		*color_str;

	point = (t_3dpoint *)malloc(sizeof(t_3dpoint));
	point->x = col * 20;
	point->y = row * 20;
	point->z = ft_atoi(arr_points[col]);
	color_str = ft_strchr(arr_points[col], ',');
	point->color = get_point_color(color_str);
	map->matrix[row * map->max_width + col] = point;
}

static t_3dpoint	**matrix_alloc(int max_width, int height)
{
	return (ft_calloc(max_width * height, sizeof(t_3dpoint *) + 1));
}

void	init_map(t_map *map, char *full_line)
{
	char	**all_lines;
	char	**splited_cols;
	int		col;
	int		row;

	all_lines = ft_split(full_line, "\n");
	map->matrix = matrix_alloc(map->max_width, map->height);
	row = 0;
	while (row < map->height)
	{
		col = 0;
		splited_cols = ft_split(all_lines[row], " ");
		if (get_width(all_lines[row]) < map->max_width)
			return ;
		else
		{
			while (col < map->max_width)
			{
				place_point_in_map(map, splited_cols, row, col);
				col++;
			}
		}
		row++;
	}
}

void	parse_map(t_map *map, char *full_line)
{
	map->max_width = get_max_width(full_line);
	map->height = get_height(full_line);
	init_map(map, full_line);
	map->max_z = get_max_altitude(map->matrix);
}
