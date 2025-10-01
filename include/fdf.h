/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:33:44 by thaperei          #+#    #+#             */
/*   Updated: 2025/10/01 10:15:52 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"
// Window
# define WIDTH 1920
# define HEIGHT 1080
# define MENU_WIDTH 300
# define QNT_IMAGES 2
# define HEX_BASE "0123456789ABCDEF"
// Limit
# define INT_MAX 2147483647 
# define INT_MIN -2147483648

enum e_images
{
	WIREFRAME,
	MENU
};

typedef struct s_3dpoint
{
	int	color;
	int	x;
	int	y;
	int	z;
}	t_3dpoint;

typedef struct s_point
{
	int	color;
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_3dpoint	p0;
	t_3dpoint	p1;
}	t_line;

typedef struct s_map
{
	t_3dpoint	**matrix;
	int			max_width;
	int			height;
	int			max_z;
}	t_map;

typedef struct s_bresenham
{
	t_3dpoint	delta;
	t_line		line;
	t_line		initial_line;
	int			delta_x;
	int			delta_y;
	int			slope_x;
	int			slope_y;
	int			error;
	int			error_2;
}	t_bresenham;

typedef struct s_mlx_data
{
	mlx_image_t	*imgs[QNT_IMAGES];
	mlx_t		*mlx;
	t_map		map;
}	t_mlx_data;

// Images
void	create_images(t_mlx_data *fdf, char *filename);
void	draw_menu(t_mlx_data *fdf);

// Bresenham
void	bresenham(mlx_image_t *fdf, t_line line);

// Colors
int		get_red(int rgba);
int		get_green(int rgba);
int		get_blue(int rgba);
int		get_alpha(int rgba);
int		get_rgba(int red, int green, int blue, int alpha);
int		get_color_gradient(t_3dpoint current, t_3dpoint start, t_3dpoint end,
			t_3dpoint delta);

// Map functions
void	create_map(t_mlx_data *fdf, char *filename);
void	parse_map(t_map *map, char *full_line);
void	draw_map(t_mlx_data *fdf);

// Map utils functions
int		get_max_width(char *str);
int		get_height(char *str);
int		get_max_altitude(t_3dpoint **matrix);
int		get_point_color(char *str);

// Error Message
void	error_msg(char *str);

// Map Validation
void	validate_map(char **argv, t_mlx_data *fdf_data);
int		is_valid_map(char *file_line);

// Free Memory
void	free_arr(char **arr);
void	free_map(t_map *map);

// Helper functions
void	put_pixel(mlx_image_t *img, t_3dpoint point);
int		absolute_value(int value);
int		get_width(char *str);
#endif 
