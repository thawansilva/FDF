/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:37:33 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/05 12:37:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_putchar_hex(char letter)
{
	return (write(STDOUT, &letter, 1));
}

unsigned int	ft_print_hex(unsigned int nbr, char case_letter)
{
	unsigned int	len;
	char			*base;

	len = 0;
	if (case_letter == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		len += ft_putchar_hex(base[nbr]);
	else
	{
		len += ft_print_hex(nbr / 16, case_letter);
		len += ft_print_hex(nbr % 16, case_letter);
	}
	return (len);
}
