/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:35:36 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/05 12:35:36 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_putnbr_str(char *nbr)
{
	int	i;

	if (!nbr)
		return (write(STDOUT, "(null)", 6));
	i = 0;
	while (nbr[i])
	{
		write(STDOUT, &nbr[i], 1);
		i++;
	}
	return (i);
}

unsigned int	ft_print_nbr(int nbr)
{
	unsigned int	len;
	char			*str;

	str = ft_itoa(nbr);
	len = ft_putnbr_str(str);
	free(str);
	return (len);
}
