/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:04:59 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/23 10:18:44 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	int			i;
	t_3dpoint	**matrix;

	if (map == NULL)
		return ;
	i = 0;
	matrix = map->matrix;
	while (i < map->height * map->max_width)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
