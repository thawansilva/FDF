/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:05:41 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/30 10:41:15 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_images(t_mlx_data *fdf, char *filename)
{
	char	*title;

	title = ft_strjoin("Fdf - ", filename);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, title, true);
	if (!fdf->mlx)
		error_msg((char *)(mlx_strerror(mlx_errno)));
	fdf->imgs[WIREFRAME] = mlx_new_image(fdf->mlx, WIDTH / 2, HEIGHT / 2);
	fdf->imgs[MENU] = mlx_new_image(fdf->mlx, MENU_WIDTH, HEIGHT);
	free(title);
}
