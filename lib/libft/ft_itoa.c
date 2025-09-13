/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:25:21 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/19 12:25:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_count_digits(int n)
{
	int	count_dig;

	count_dig = 0;
	if (n <= 0)
	{
		count_dig++;
		n = -n;
	}
	while (n != 0)
	{
		count_dig++;
		n /= 10;
	}
	return (count_dig);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		count_dig;
	long	num;
	char	*nbr;

	num = n;
	count_dig = ft_count_digits(num);
	nbr = (char *) ft_calloc(count_dig + 1, sizeof(char));
	if (!nbr)
		return (0);
	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	while (count_dig--)
	{
		nbr[count_dig] = num % 10 + '0';
		num /= 10;
	}
	if (sign < 0)
		nbr[0] = '-';
	return (nbr);
}
