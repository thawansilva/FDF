/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 11:30:44 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	get_line_to_print(t_point **matrix, int from, int to)
{
	t_line	line;

	line.p0 = *matrix[from];
	line.p1 = *matrix[to];
	return (line);
}

void	draw_line(t_mlx_data *fdf, t_point **matrix, int i, int j)
{
	t_line		line;
	int			current;
	int			width;
	int			height;

	width = fdf->map.max_width;
	height = fdf->map.height;
	current = i * width + j;
	if (matrix[current] == NULL)
		return ;
	if (j < width - 1 && matrix[current + 1] != NULL)
	{
		line = get_line_to_print(matrix, current, current + 1);
		bresenham(fdf->imgs[WIREFRAME], line);
	}
	if (i < height - 1 && matrix[current + width] != NULL)
	{
		line = get_line_to_print(matrix, current, current + width);
		bresenham(fdf->imgs[WIREFRAME], line);
	}
}

void	draw_map(t_mlx_data *fdf)
{
	int		i;
	int		j;
	int		width;
	int		height;

	transform_map(fdf, &fdf->map);
	width = fdf->map.max_width;
	height = fdf->map.height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			draw_line(fdf, fdf->map.matrix, i, j);
			j++;
		}
		i++;
	}
}
