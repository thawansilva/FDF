/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:54:59 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/05 12:54:59 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_ptr_digits(t_ptr ptr)
{
	unsigned int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_putptr(t_ptr ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), STDOUT);
		else
			ft_putchar_fd((ptr - 10 + 'a'), STDOUT);
	}
}

unsigned int	ft_print_ptr(t_ptr ptr)
{
	unsigned int	len;

	len = 0;
	if (ptr == 0)
		len += write(STDOUT, "(nil)", 5);
	else
	{
		len = write(STDOUT, "0x", 2);
		ft_putptr(ptr);
		len += ft_get_ptr_digits(ptr);
	}
	return (len);
}
