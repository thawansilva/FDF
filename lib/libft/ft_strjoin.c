/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thawansilva@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:12:31 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/16 14:12:31 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	full_len;
	char	*full_str;

	if (!s1 || !s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	full_str = (char *) ft_calloc(full_len, sizeof(char));
	if (!full_str)
		return (NULL);
	ft_strlcpy(full_str, s1, (full_len));
	ft_strlcat(full_str, s2, (full_len));
	return (full_str);
}
