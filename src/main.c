/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/17 16:00:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR);
	exit(EXIT_FAILURE);
}

static void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc == 1)
		error_msg("Usage: ./fdf <filename>");
	validate_map(argv + 1);
//	init_map(argv + 1);
	mlx_set_setting(MLX_MAXIMIZED, true);
	window.mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!window.mlx)
		ft_error();
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	if (!window.img || (mlx_image_to_window(window.mlx, window.img,
				window.mlx->width / 2, window.mlx->height / 2) < 0))
	{
		mlx_terminate(window.mlx);
		return (EXIT_FAILURE);
	}
	mlx_put_pixel(window.img, 0, 0, 0xFF0000FF);
	mlx_loop_hook(window.mlx, ft_hook, window.mlx);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	return (EXIT_SUCCESS);
}
