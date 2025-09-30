/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:06:18 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/30 16:41:52 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".fdf", 4) != 0)
		return (0);
	return (1);
}

char	*read_all_map(int fd)
{
	char	*file_line;
	char	*line;
	char	*temp;

	file_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(file_line, line);
		free(file_line);
		free(line);
		file_line = temp;
	}
	return (file_line);
}

void	create_map(t_mlx_data *fdf, char *filename)
{
	int		fd;
	char	*full_line;

	if (!is_valid_extension(filename))
		error_msg("❌ Invalid extension");
	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		error_msg("❌ Invalid file descriptor");
	fdf->map.max_width = 0;
	full_line = read_all_map(fd);
	ft_putendl_fd("🔎 Validating Map...", 1);
	if (!is_valid_map(full_line))
	{
		free(full_line);
		close(fd);
		error_msg("❌ Invalid Map");
	}
	ft_putendl_fd("✅ Valid Map", 1);
	parse_map(&(fdf->map), full_line);
	free(full_line);
	close(fd);
}
