/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thawansilva@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:49:19 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/15 16:49:19 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	full_size;

	if (nmemb == 0 || size == 0)
		return (ft_strdup(""));
	if (nmemb > ((size_t) -1 / size))
		return ((void *)0);
	full_size = nmemb * size;
	ptr = (void *) malloc(full_size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, full_size);
	return (ptr);
}
