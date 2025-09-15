/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/15 17:17:38 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR);
	exit(EXIT_FAILURE);
}

static void	ft_hook(void *param)
{
	mlx_t	*mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		error_msg("Usage: ./fdf <filename>");
	validate_map(argv + 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);

	if (!mlx)
		ft_error();

	mlx_image_t	*img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			mlx_put_pixel(img, i, j, 0xFF0000FF);
		}
	}

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
