/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thawansilva@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:48:45 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/15 14:48:45 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = 0;
	while (*str)
	{
		if (*str == (char) c)
			last = (char *)str;
		str++;
	}
	if (*str == (char) c)
		return ((char *)str);
	return (last);
}
