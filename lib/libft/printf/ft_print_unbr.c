/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:44:29 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/06 10:44:29 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_unbr_len(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_putunbr(unsigned int nbr)
{
	char	letter;

	if (nbr >= 10)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	else
	{
		letter = nbr + '0';
		write(STDOUT, &letter, 1);
	}
}

unsigned int	ft_print_unbr(unsigned int nbr)
{
	unsigned int	len;

	if (nbr == 0)
		return (write(STDOUT, "0", 1));
	len = ft_get_unbr_len(nbr);
	ft_putunbr(nbr);
	return (len);
}
