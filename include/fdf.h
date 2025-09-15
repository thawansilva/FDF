/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:33:44 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/15 17:39:40 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42/MLX42.h"
# define WIDTH 256
# define HEIGHT 256

// Limit
# define INT_MAX 2147483647 
# define INT_MIN -2147483648

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

// Error Message
void	error_msg(char *str);

// Map Validation
void	validate_map(char **argv);

// Free Memory
void	free_arr(char **arr);
#endif 
