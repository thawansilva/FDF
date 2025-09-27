/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:05:41 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/26 10:13:42 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_images(t_mlx_data *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Fdf ", true);
	if (!fdf->mlx)
		error_msg((char *)(mlx_strerror(mlx_errno)));
	fdf->imgs[WIREFRAME] = mlx_new_image(fdf->mlx, WIDTH / 2, HEIGHT / 2);
	fdf->imgs[MENU] = mlx_new_image(fdf->mlx, MENU_WIDTH, HEIGHT);
}
