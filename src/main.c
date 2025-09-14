/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/11 16:13:05 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
}

//static void	ft_hook(void *param)
//{
//	const mlx_t	*mlx = param;
//
//	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
//}

int main(int argc, char **argv)
{
	if (argc == 1)
		error_msg("Usage: ./fdf <filename>");
	if (!argv)
		return (1);
	validate_map(argv + 1);
	mlx_set_setting(MLX_MAXIMIZED, TRUE);
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "Fdf", TRUE);

	if (!mlx)
		ft_error();

	mlx_image_t	*img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, img->width / 2, img->height / 2) < 0))
		ft_error();
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			mlx_put_pixel(img, i, j, 0xFF0000FF);
		}
	}

	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
