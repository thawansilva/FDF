/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:54:23 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/12 16:54:23 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(char *str, char *sub, size_t n)
{
	size_t	i;
	size_t	j;

	if (n < 0 || *sub == '\0')
		return (str);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while ((str[i + j] == sub[j]) && (j < n - i) && sub[j])
			j++;
		if (sub[j] == '\0')
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
