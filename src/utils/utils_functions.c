/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:26:00 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/29 17:57:24 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(mlx_image_t *img, t_3dpoint point)
{
	if (point.x >= 0 && point.x <= WIDTH && point.y >= 0 && point.y <= HEIGHT)
		mlx_put_pixel(img, point.x, point.y, point.color);
}

int	absolute_value(int value)
{
	return ((value) * ((value) >= 0) - (value) * ((value) < 0));
}

int	get_width(char *str)
{
	int	i;
	int	width;

	width = 0;
	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n'
				|| str[i + 1] == '\0'))
			width++;
		i++;
	}
	return (width);
}
