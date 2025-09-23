/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/22 17:26:14 by thaperei         ###   ########.fr       */
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
	t_mlx_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(data->mlx);
		free_map(&(data->map));
		exit(EXIT_SUCCESS);
	}
}

// Estudar codam
int	main(int argc, char **argv)
{
	t_mlx_data	fdf_data;

	if (argc == 1)
		error_msg("Usage: ./fdf <filename>");
	// Solve leak problem on wrong inputs
	validate_map(argv + 1, &fdf_data);
	// Init map
	init_map(argv + 1, &(fdf_data.map), fdf_data.file_line);
	ft_putendl_fd("✅ Valid Map", STDOUT);
	// Window settings
	mlx_set_setting(MLX_MAXIMIZED, true);
	fdf_data.mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!fdf_data.mlx)
		ft_error();
	fdf_data.imgs[0] = mlx_new_image(fdf_data.mlx, WIDTH, HEIGHT);
	if (!fdf_data.imgs[0] || (mlx_image_to_window(fdf_data.mlx,
				fdf_data.imgs[0], fdf_data.mlx->width / 2,
				fdf_data.mlx->height / 2) < 0))
	{
		free_map(&fdf_data.map);
		mlx_terminate(fdf_data.mlx);
		return (EXIT_FAILURE);
	}
	// Draw pixels
//	draw_map(&fdf_data);
	mlx_loop_hook(fdf_data.mlx, ft_hook, &fdf_data);
	mlx_loop(fdf_data.mlx);
	mlx_terminate(fdf_data.mlx);
	return (EXIT_SUCCESS);
}
