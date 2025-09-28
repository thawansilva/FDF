/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:26:00 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/28 11:30:34 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(mlx_image_t *img, t_3dpoint point)
{
	mlx_put_pixel(img, point.x, point.y, point.color);
}

int	absolute_value(int value)
{
	return ((value) * ((value) >= 0) - (value) * ((value) < 0));
}
