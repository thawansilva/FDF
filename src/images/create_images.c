/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:05:41 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 11:56:50 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_image_in_window(t_mlx_data *fdf)
{
	mlx_image_to_window(fdf->mlx, fdf->imgs[WIREFRAME], 0, 0);
	mlx_image_to_window(fdf->mlx, fdf->imgs[MENU], 0, 0);
}

void	create_images(t_mlx_data *fdf, char *filename)
{
	char	*title;

	mlx_set_setting(MLX_MAXIMIZED, true);
	title = ft_strjoin("Fdf - ", filename);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, title, true);
	if (!fdf->mlx)
		error_msg((char *)(mlx_strerror(mlx_errno)));
	fdf->imgs[WIREFRAME] = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->imgs[MENU] = mlx_new_image(fdf->mlx, MENU_WIDTH, HEIGHT);
	free(title);
	place_image_in_window(fdf);
}
