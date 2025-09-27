/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/27 16:10:32 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_mlx_data *fdf)
{
	t_3dpoint	**matrix;
	int			i;
	int			j;
	int			width;
	int			height;
	int			idx;
	t_line		line;

	mlx_image_to_window(fdf->mlx, fdf->imgs[WIREFRAME],
		(WIDTH + 200) / 2, (HEIGHT - 120) / 2);
	matrix = fdf->map.matrix;
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
			j++;
		}
		i++;
	}
}
