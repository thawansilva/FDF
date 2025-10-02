/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/01 19:06:13 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(t_point point_3d)
{
	t_point	point_2d;

	point_2d.x = (point_3d.x - point_3d.y) * cos(0.523599);
	point_2d.y = (point_3d.x + point_3d.y) * sin(0.523599) - point_3d.z;
	return (point_2d);
}

t_line	get_line_to_print(t_mlx_data *fdf, t_point **matrix, int from, int to)
{
	t_line	line;

	if (fdf == NULL)
		;
	matrix[from]->x = matrix[from]->x;
	matrix[from]->y = matrix[from]->y;
	matrix[to]->x = matrix[to]->x;
	matrix[to]->y = matrix[to]->y;
	line.p0 = *matrix[from];
	line.p1 = *matrix[to];
	return (line);
}

void	draw_line(t_mlx_data *fdf, t_point **matrix, int i, int j)
{
	t_line		line;
	int			idx;
	int			width;
	int			height;

	width = fdf->map.max_width;
	height = fdf->map.height;
	idx = i * width + j;
	if (matrix[idx] == NULL)
		return ;
	if (j < width - 1 && matrix[idx + 1] != NULL)
	{
		line = get_line_to_print(fdf, matrix, idx, idx + 1);
		bresenham(fdf->imgs[WIREFRAME], line);
	}
	if (i < height - 1 && matrix[idx + width] != NULL)
	{
		line = get_line_to_print(fdf, matrix, idx, idx + width);
		bresenham(fdf->imgs[WIREFRAME], line);
	}
}

void	draw_map(t_mlx_data *fdf)
{
	t_point	**matrix;
	int			i;
	int			j;
	int			width;
	int			height;

	matrix = fdf->map.matrix;
	mlx_image_to_window(fdf->mlx, fdf->imgs[WIREFRAME],
		(WIDTH + 200) / 2, (HEIGHT - 120) / 2);
	width = fdf->map.max_width;
	height = fdf->map.height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			draw_line(fdf, matrix, i, j);
			j++;
		}
		i++;
	}
}
