/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:33:44 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/17 16:02:23 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42/MLX42.h"
# define WIDTH 1920
# define HEIGHT 1080

// Limit
# define INT_MAX 2147483647 
# define INT_MIN -2147483648

typedef struct s_window
{
    mlx_t *mlx;
    mlx_image_t *img;
} t_window;

typedef struct s_map
{
	struct s_map	**matrix;
}	t_map;

typedef struct s_3dpoint
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_3dpoint;

typedef struct s_line
{
	t_3dpoint	p1;
	t_3dpoint	p2;
}	t_line;

// Error Message
void	error_msg(char *str);

// Map Validation
void	validate_map(char **argv);

// Free Memory
void	free_arr(char **arr);
#endif 
