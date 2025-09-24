/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/24 20:00:52 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_mlx_data *fdf)
{
	t_3dpoint	**matrix;
	int			i;
	int			size;

	mlx_image_to_window(fdf->mlx, fdf->imgs[WIREFRAME],
		(WIDTH + 200) / 2, (HEIGHT - 120) / 2);
	matrix = fdf->map.matrix;
	size = fdf->map.max_width * fdf->map.height;
	i = 0;
	while (i < size)
	{
		if (matrix[i] == NULL)
			return ;
		mlx_put_pixel(fdf->imgs[WIREFRAME], matrix[i]->x * 2,
			matrix[i]->y * 2, matrix[i]->color);
		i++;
	}
}
