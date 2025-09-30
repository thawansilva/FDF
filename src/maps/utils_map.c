/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:22:38 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/30 16:15:51 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max_width(char *str)
{
	char	**split_line;
	int		max_width;
	int		i;

	i = 0;
	max_width = 0;
	split_line = ft_split(str, "\n");
	while (split_line[i] != NULL)
	{
		if (get_width(split_line[i]) > max_width)
			max_width = get_width(split_line[i]);
		i++;
	}
	free_arr(split_line);
	return (max_width);
}

int	get_height(char *str)
{
	int		height;
	int		i;

	i = 0;
	height = 0;
	while (str[i])
	{
		if (str[i] == '\n' || (str[i] != '\n' && str[i + 1] == '\0'))
			height++;
		i++;
	}
	return (height);
}

int	get_max_altitude(t_3dpoint **matrix)
{
	int	max_altitude;
	int	i;

	i = 0;
	max_altitude = 0;
	while (matrix[i] != NULL)
	{
		if (matrix[i]->z > max_altitude)
			max_altitude = matrix[i]->z;
		i++;
	}
	return (max_altitude);
}

int	get_point_color(char *str)
{
	int		color;

	if (str == NULL)
		color = ft_atoi_base("0xFFFFFFFF", HEX_BASE);
	else
		color = ft_atoi_base(str + 1, HEX_BASE);
	return (color);
}
