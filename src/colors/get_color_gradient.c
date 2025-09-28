/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:05:40 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/28 11:15:10 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_progress_ratio(int start, int end, int current)
{
	double	location;
	double	distance;

	distance = end - start;
	location = current - start;
	if (distance == 0)
		return (1.0);
	return (location / distance);
}

static int	lerp(int start, int end, double percent)
{
	return ((int)(start + percent * (end - start)));
}

int	get_color_gradient(t_3dpoint current, t_3dpoint start,
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
		percentage = get_progress_ratio(start.x, end.x, current.x);
	else
		percentage = get_progress_ratio(start.y, end.y, current.y);
	red = lerp(get_red(start.color), get_red(end.color), percentage);
	green = lerp(get_green(start.color), get_green(end.color), percentage);
	blue = lerp(get_blue(start.color), get_blue(end.color), percentage);
	alpha = lerp(get_alpha(start.color), get_alpha(end.color), percentage);
	return (get_rgba(red, green, blue, alpha));
}
