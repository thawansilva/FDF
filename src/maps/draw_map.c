/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/28 18:09:23 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx_data *fdf, t_3dpoint **matrix, int i, int j)
{
	t_line		line;
	int			idx;
	int			width;
	int			height;

	width = fdf->map.max_width;
	height = fdf->map.height;
	idx = i * width + j;
	if (j < width - 1 && matrix[idx + 1] != NULL)
	{
		line.p0 = *matrix[idx];
		line.p1 = *matrix[idx + 1];
		bresenham(fdf->imgs[WIREFRAME], line);
	}
	if (i < height - 1 && matrix[idx + width] != NULL)
	{
		line.p0 = *matrix[idx];
		line.p1 = *matrix[idx + width];
		bresenham(fdf->imgs[WIREFRAME], line);
	}
}

void	draw_map(t_mlx_data *fdf)
{
	t_3dpoint	**matrix;
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
		if (matrix[i] == NULL)
			return ;
		j = 0;
		while (j < width)
		{
			draw_line(fdf, matrix, i, j);
			j++;
		}
		i++;
	}
}
