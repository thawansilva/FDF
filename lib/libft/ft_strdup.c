/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:28:00 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/11 20:28:00 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup_str;
	int		i;

	dup_str = (char *) ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!dup_str)
		return (0);
	i = 0;
	while (str[i])
	{
		dup_str[i] = str[i];
		i++;
	}
	return (dup_str);
}
