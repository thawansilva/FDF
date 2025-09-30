/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/30 16:40:41 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_mlx_data *fdf)
{
	fdf->map.height = 0;
	fdf->map.max_width = 0;
	fdf->map.max_z = 0;
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
	init_fdf(&fdf);
	create_map(&fdf, argv[1]);
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
