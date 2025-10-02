/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 08:39:58 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_mlx_data *fdf)
{
	fdf->camera.offset_x = WIDTH / 2 + (WIDTH / 3) / 5; 
	fdf->camera.offset_y = HEIGHT / 2; 
	fdf->camera.angle_x = 30;
	fdf->camera.angle_z = 45;
	fdf->camera.angle_y = 0;
	fdf->camera.scale_x = (WIDTH * 0.7) / (fdf->map.max_width);
	fdf->camera.scale_y = (HEIGHT * 0.7) / (fdf->map.height);
}

void	delete_fdf(t_mlx_data *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->imgs[WIREFRAME]);
	mlx_delete_image(fdf->mlx, fdf->imgs[MENU]);
}

static void	ft_hook(void *param)
{
	t_mlx_data	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(fdf->mlx);
		free_map(&fdf->map);
		ft_putendl_fd("Bye bye...", 1);
		exit(EXIT_SUCCESS);
	}
	draw_map(fdf);
}

int	main(int argc, char **argv)
{
	t_mlx_data	fdf;

	if (argc != 2)
		error_msg("Usage: ./fdf <filename>");
	create_map(&fdf, argv[1]);
	init_fdf(&fdf);
	mlx_set_setting(MLX_MAXIMIZED, true);
	create_images(&fdf, argv[1]);
	draw_menu(&fdf);
	ft_putendl_fd("🖌️  Drawing Map...", 1);
	mlx_loop_hook(fdf.mlx, ft_hook, &fdf);
	mlx_loop(fdf.mlx);
	delete_fdf(&fdf);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
