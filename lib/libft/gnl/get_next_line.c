/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:21:54 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/25 11:21:54 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

static char	*ft_get_line(char *str)
{
	size_t	line_len;
	char	*line;

	line = NULL;
	line_len = 0;
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	if (!str[line_len])
		return (str);
	if (str[line_len] == '\n')
		line_len++;
	line = ft_calloc(line_len + 1, sizeof(char));
	if (!line)
		return (ft_free(line, NULL));
	ft_strlcpy(line, str, line_len + 1);
	return (line);
}

static char	*ft_get_remainder(char *str)
{
	size_t	nl_pos;
	size_t	rem_len;
	char	*remainder;

	nl_pos = 0;
	while (str[nl_pos] && str[nl_pos] != '\n')
		nl_pos++;
	if (str[nl_pos] == '\0')
		return (NULL);
	rem_len = ft_strlen(str) - nl_pos;
	if (rem_len <= 1)
		return (ft_free(str, NULL));
	remainder = ft_calloc(rem_len + 1, sizeof(char));
	if (!remainder)
		return (ft_free(remainder, str));
	ft_strlcpy(remainder, str + nl_pos + 1, rem_len + 1);
	free(str);
	return (remainder);
}

static char	*ft_parse_line(char *rest, int fd)
{
	char	*buff;
	char	*tmp_rest;
	int		bytes_read;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (ft_free(buff, rest));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(buff, rest));
		buff[bytes_read] = '\0';
		tmp_rest = ft_strjoin(rest, buff);
		free(rest);
		rest = tmp_rest;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (bytes_read == 0 && (rest[0] == '\0' || !rest))
		return (ft_free(rest, buff));
	ft_free(buff, NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(remainder, NULL));
	remainder = ft_parse_line(remainder, fd);
	if (!remainder)
		return (NULL);
	line = ft_get_line(remainder);
	if (!line)
		return (ft_free(line, remainder));
	remainder = ft_get_remainder(remainder);
	return (line);
}
