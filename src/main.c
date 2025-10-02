/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:13:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/02 16:46:46 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_mlx_data *fdf)
{
	double	scale_height;
	double	scale_width;

	fdf->camera.offset_x = WIDTH / 4 + (WIDTH / 2) / 5; 
	fdf->camera.offset_y = HEIGHT / 3;
	fdf->camera.angle_x = 30;
	fdf->camera.angle_z = 45;
	fdf->camera.angle_y = 0;
	scale_width = WIDTH / hypot((double) fdf->map.max_width, (double) fdf->map.height);
	scale_height = HEIGHT / hypot((double) fdf->map.max_width, (double) fdf->map.height);
	fdf->camera.scale = 0.7;
	fdf->camera.scale_x = scale_width;
	fdf->camera.scale_y = scale_height;
}

void	delete_fdf(t_mlx_data *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->imgs[WIREFRAME]);
	mlx_delete_image(fdf->mlx, fdf->imgs[MENU]);
}

//static void	ft_hook(void *param)
//{
//	static struct timeval lasttime = {0,0};
//	struct timeval current_time;
//	t_mlx_data	*fdf = (t_mlx_data *)param;
//
//	gettimeofday(&current_time, NULL);
//	long long timediff = (current_time.tv_sec - lasttime.tv_sec) * 100000;
//	timediff += current_time.tv_usec - lasttime.tv_usec;
//	if (timediff >= (fdf->map.max_width * fdf->map.height) / 1.5)
//	{
//		lasttime = current_time;
//	}
//}

int	main(int argc, char **argv)
{
	t_mlx_data	fdf;

	if (argc != 2)
		error_msg("Usage: ./fdf <filename>");
	create_map(&fdf, argv[1]);
	init_fdf(&fdf);
	create_images(&fdf, argv[1]);
	draw_menu(&fdf);
	ft_putendl_fd("🖌️  Drawing Map...", 1);
	draw_map(&fdf);
//	mlx_loop_hook(fdf.mlx, ft_hook, &fdf);
	mlx_key_hook(fdf.mlx, handle_keys, &fdf);
	mlx_loop(fdf.mlx);
	delete_fdf(&fdf);
	mlx_terminate(fdf.mlx);
	ft_putendl_fd("Bye bye...", 1);
	return (EXIT_SUCCESS);
}
