/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:29:45 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 16:02:41 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_mlx_data *fdf, t_point *point)
{
	point->x *= fdf->camera.scale_x * fdf->camera.scale;
	point->y *= fdf->camera.scale_y * fdf->camera.scale;
}

void	rotate_x(t_mlx_data *fdf, t_point *point)
{
	t_point	aux;
	float	angle_rad;

	aux = *point;
	angle_rad = fdf->camera.angle_x * PI / 180.0;
	point->y = aux.y * cos(angle_rad) - aux.z * sin(angle_rad);
	point->z = aux.y * sin(angle_rad) + aux.z * cos(angle_rad);
}

void	rotate_y(t_mlx_data *fdf, t_point *point)
{
	t_point	aux;
	float	angle_rad;

	aux = *point;
	angle_rad = fdf->camera.angle_y * PI / 180.0;
	point->x = aux.x * cos(angle_rad) + aux.z * sin(angle_rad);
	point->z = (-aux.x * sin(angle_rad)) + aux.z * cos(angle_rad);
}

void	rotate_z(t_mlx_data *fdf, t_point *point)
{
	t_point	aux;
	float	angle_rad;

	aux = *point;
	angle_rad = fdf->camera.angle_z * PI / 180.0;
	point->x = aux.x * cos(angle_rad) - aux.y * sin(angle_rad);
	point->y = aux.x * sin(angle_rad) + aux.y * cos(angle_rad);
}

void	translate(t_mlx_data *fdf, t_point *point)
{
	point->x += fdf->camera.offset_x;
	point->y += fdf->camera.offset_y;
}
