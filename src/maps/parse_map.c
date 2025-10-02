/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:26:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 17:10:48 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_point_in_map(t_map *map, char *str, t_point aux)
{
	t_point	*point;
	char	*color_str;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = aux.x;
	point->y = aux.y;
	point->z = ft_atoi(str);
	color_str = ft_strchr(str, ',');
	point->color = get_point_color(color_str);
	map->matrix[aux.y * map->max_width + aux.x] = point;
}

void	fill_points_in_map(t_map *map, char **splited_cols, t_point aux)
{
	while (splited_cols[aux.x] != NULL)
	{
		place_point_in_map(map, splited_cols[aux.x], aux);
		aux.x++;
	}
	while (aux.x < map->max_width)
	{
		place_point_in_map(map, "0", aux);
		aux.x++;
	}
}

static t_point	**matrix_alloc(int max_width, int height)
{
	return (ft_calloc((max_width * height) + 1, sizeof(t_point *)));
}

void	init_map(t_map *map, char *full_line)
{
	t_point	aux;
	char	**all_lines;
	char	**splited_cols;

	all_lines = ft_split(full_line, "\n");
	map->matrix = matrix_alloc(map->max_width, map->height);
	aux.y = 0;
	while (aux.y < map->height)
	{
		aux.x = 0;
		splited_cols = ft_split(all_lines[aux.y], " ");
		if (get_width(all_lines[aux.y]) < map->max_width)
			fill_points_in_map(map, splited_cols, aux);
		else
		{
			while (aux.x < map->max_width)
			{
				place_point_in_map(map, splited_cols[aux.x], aux);
				aux.x++;
			}
		}
		free_arr(splited_cols);
		aux.y++;
	}
	free_arr(all_lines);
}

double	get_z_range(t_map *map)
{
	double	z_max;
	double	z_min;
	double	current;
	int		i;

	i = 0;
	z_max = map->matrix[i]->z;
	z_min = map->matrix[i]->z;
	while (map->matrix[i] != NULL)
	{
		current = (double) map->matrix[i]->z;
		if (current > z_max)
			z_max = current;
		if (current < z_min)
			z_min = current;
		i++;
	}
	return (z_max - z_min);
}

void	parse_map(t_map *map, char *full_line)
{
	map->max_width = get_max_width(full_line);
	map->height = get_height(full_line);
	init_map(map, full_line);
	map->z_range = get_z_range(map);
}
