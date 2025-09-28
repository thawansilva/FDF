/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:05:19 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/28 11:32:27 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dpoint	get_point(t_bresenham data)
{
	t_3dpoint	point;

	point.x = data.line.p0.x;
	point.y = data.line.p0.y;
	point.color = 0;
	point.color = get_color_gradient(data.line.p0, data.initial_line.p0,
			data.initial_line.p1, data.delta);
	return (point);
}

t_bresenham	init_bresenham(t_line line)
{
	t_bresenham	data;

	data.line = line;
	data.initial_line = line;
	data.delta.x = absolute_value(line.p1.x - line.p0.x);
	data.delta.y = absolute_value(line.p1.y - line.p0.y);
	data.delta_x = absolute_value(line.p1.x - line.p0.x);
	data.delta_y = absolute_value(line.p1.y - line.p0.y);
	data.slope_x = (line.p0.x <= line.p1.x) - (line.p0.x > line.p1.x);
	data.slope_y = (line.p0.y <= line.p1.y) - (line.p0.y > line.p1.y);
	data.error = data.delta_x - data.delta_y;
	return (data);
}

void	bresenham(mlx_image_t *img, t_line line)
{
	t_bresenham	data;

	data = init_bresenham(line);
	while (1)
	{
		put_pixel(img, get_point(data));
		if (data.line.p0.x == data.line.p1.x
			&& data.line.p0.y == data.line.p1.y)
			break ;
		data.error_2 = 2 * data.error;
		if (data.error_2 >= data.delta_y)
		{
			if (data.line.p0.x == data.line.p1.x)
				break ;
			data.error += data.delta_y;
			data.line.p0.x += data.slope_x;
		}
		if (data.error_2 <= data.delta_x)
		{
			if (data.line.p0.y == data.line.p1.y)
				break ;
			data.error += data.delta_x;
			data.line.p0.y += data.slope_y;
		}
	}
}
