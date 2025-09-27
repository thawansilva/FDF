/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:05:19 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/27 18:52:19 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_percentage(int start, int end, int current)
{
	double	location;
	double	distance;

	distance = end - start;
	location = current - start;
	if (distance == 0)
		return (1.0);
	return (location / distance);
}

int	lerp(int start, int end, double percent)
{
	return (int)(start + percent * (end - start));
}

int	get_gradient(t_3dpoint current, t_3dpoint start,
		t_3dpoint end, t_3dpoint delta)
{
	int		red;
	int		blue;
	int		green;
	int		alpha;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = get_percentage(start.x, end.x, current.x);
	else
		percentage = get_percentage(start.y, end.y, current.y);
	red = lerp((start.color >> 24) & 0xFF, (end.color >> 24) & 0xFF,
			percentage);
	green = lerp((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percentage);
	blue = lerp((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percentage);
	alpha = lerp(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 24) | (green << 16) | (blue << 8) | alpha);
}

t_3dpoint	get_point(t_bresenham data)
{
	t_3dpoint	point;
	t_3dpoint	delta;

	point.x = data.line.p0.x;
	point.y = data.line.p0.y;
	point.color = data.line.p0.color;
	delta.x = ABS(data.line.p1.x - data.line.p0.x);
	delta.y = ABS(data.line.p1.y - data.line.p0.y);
	point.color = get_gradient(point, data.line.p0, data.line.p1, delta);
	return (point);
}

t_bresenham	init_bresenham(t_line line)
{
	t_bresenham	data;

	data.line = line;
	data.delta_x = ABS(line.p1.x - line.p0.x);
	data.delta_y = ABS(line.p1.y - line.p0.y);
	data.slope_x = (line.p0.x <= line.p1.x) - (line.p0.x > line.p1.x);
	data.slope_y = (line.p0.y <= line.p1.y) - (line.p0.y > line.p1.y);
	data.error = data.delta_x - data.delta_y;
	return (data);
}

void	put_pixel(mlx_image_t *img, t_3dpoint point)
{
		mlx_put_pixel(img, point.x, point.y, point.color);
}

void	bresenham(mlx_image_t *img, t_line line)
{
	t_bresenham	data;

	data = init_bresenham(line);
	while (1)
	{
		put_pixel(img, get_point(data));
		if (data.line.p0.x == data.line.p1.x && data.line.p0.y == data.line.p1.y)
			break;
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
