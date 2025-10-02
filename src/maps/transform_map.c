/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:55:43 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 16:12:36 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_point(t_mlx_data *fdf, t_point *point)
{
	scale(fdf, point);
//	rotate_z(fdf, point);
//	rotate_x(fdf, point);
//	rotate_y(fdf, point);
	translate(fdf, point);
}

void	transform_map(t_mlx_data *fdf, t_map *map)
{
	t_point	*point;
	int		col;
	int		row;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->max_width)
		{
			point = get_map_point(map, col, row);
			transform_point(fdf, point);
			col++;
		}
		row++;
	}
}
