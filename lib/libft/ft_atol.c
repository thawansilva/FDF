/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:45:19 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/15 17:37:54 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nbr)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr++ == '-')
			sign *= -1;
	}
	while (ft_isdigit(*nbr))
		result = result * 10 + (*nbr++ - '0');
	return (result * sign);
}
