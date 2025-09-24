/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/24 13:30:47 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_mlx_data *fdf)
{
	fdf->map.height = 0;
	fdf->map.max_width = 0;
	fdf->file_line = NULL;
}

static void	ft_hook(void *param)
{
	t_mlx_data	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(fdf->mlx);
		free_map(&(fdf->map));
		exit(EXIT_SUCCESS);
	}
	draw_map(fdf);
}

int	main(int argc, char **argv)
{
	t_mlx_data	fdf;

	if (argc == 1)
		error_msg("Usage: ./fdf <filename>");
	init_fdf(&fdf);
	validate_map(argv + 1, &fdf);
	init_map(argv + 1, &fdf);
	mlx_set_setting(MLX_MAXIMIZED, true);
	create_images(&fdf);
	draw_menu(&fdf);
	mlx_loop_hook(fdf.mlx, ft_hook, &fdf);
	mlx_loop(fdf.mlx);
	free_map(&fdf.map);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
