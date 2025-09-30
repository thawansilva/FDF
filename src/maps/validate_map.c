/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:36:16 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/30 10:03:55 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_map(char *file_line)
{
	char	**splited_line;
	int		width;
	int		height;

	width = get_width(file_line);
	if (width < 2)
		return (0);
	splited_line = ft_split(file_line, "\n");
	height = 0;
	while (splited_line[height] != NULL)
		height++;
	if (height < 2)
		return (0);
	free_arr(splited_line);
	return (1);
}
