/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:36:16 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/16 10:04:46 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	terminate_process(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	error_msg("Invalid Map");
	close(fd);
}

int	is_valid_hex(char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	else
		return (0);
	while (ft_isalnum(str[i]))
	{
		if (!(ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'F')
				|| (str[i] >= 'a' && str[i] <= 'f')))
			return (0);
		i++;
	}
	if (i < 5 || i > 8)
		return (0);
	if (!(str[i] != '\0' || str[i] != '\n'))
		return (0);
	return (1);
}

static int	is_valid_point(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if ((str[i] == ',' && is_valid_hex(&str[i + 1]))
		|| (str[i] == '\0' || str[i] == '\n'))
		return (1);
	return (0);
}

static int	is_valid_line(char *line)
{
	int		i;
	int		width;
	char	**arr;

	if (line == NULL)
		return (0);
	arr = ft_split(line, ' ');
	width = 0;
	i = 0;
	while (arr[i])
	{
		if (!is_valid_point(arr[i]))
		{
			free_arr(arr);
			return (0);
		}
		width++;
		i++;
	}
	free_arr(arr);
	if (width < 2)
		return (0);
	return (1);
}

void	validate_map(char **argv)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(*argv, O_RDONLY);
	if (fd < 0)
		error_msg(strerror(errno));
	height = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!is_valid_line(line))
			terminate_process(line, fd);
		height++;
		free(line);
	}
	if (height < 2)
		terminate_process(NULL, fd);
	ft_putendl_fd("✅ Valid Map", STDOUT);
	close(fd);
}
