/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:37:06 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/14 16:37:06 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_remainder(char *s1, char *s2)
{
	char	*str_join;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, s1, s1_len + 1);
	ft_strlcpy(str_join + s1_len, s2, s2_len + 1);
	free(s1);
	return (str_join);
}
