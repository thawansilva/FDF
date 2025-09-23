/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/22 16:06:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_mlx_data *fdf)
{
	t_3dpoint	**matrix;
	int			i;

	matrix = fdf->map.matrix;
	i = 0;
	while (i < fdf->map.max_width)
	{
		if (matrix[i] == NULL)
			return ;
		mlx_put_pixel(fdf->imgs[0], matrix[i]->x, matrix[i]->y, 0xFF0000FF);
		i++;
	}
}
