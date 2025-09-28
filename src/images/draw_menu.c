/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:30:30 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/24 13:30:57 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_mlx_data *fdf)
{
	int	i;
	int	j;

	mlx_image_to_window(fdf->mlx, fdf->imgs[MENU], 0, 0);
	mlx_put_string(fdf->mlx, "FDF", (MENU_WIDTH - 40) / 2, 40);
	i = 0;
	while (i < MENU_WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_put_pixel(fdf->imgs[MENU], i, j, 0x222222ff);
			j++;
		}
		i++;
	}
}
