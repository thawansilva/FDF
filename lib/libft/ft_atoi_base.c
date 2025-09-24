/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:40:03 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/24 14:00:01 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_base(char *base)
{
	int	i;
	int	next_i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || ft_isspace(base[i]))
			return (0);
		next_i = i + 1;
		while (base[next_i] != '\0')
		{
			if (base[i] == base[next_i])
				return (0);
			next_i++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

static int	find_index_in_base(char letter, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == letter)
			return (i);
		i++;
	}
	return (-1);
}

static unsigned int	convert_str_to_uint(char *str, char *base)
{
	int				i;
	int				base_length;
	int				value;
	unsigned int	result;

	i = 0;
	base_length = 0;
	result = 0;
	while (base[base_length] != '\0')
		base_length++;
	while (str[i] != '\0')
	{
		value = find_index_in_base(str[i], base);
		if (value == -1)
			break ;
		result = result * base_length + value;
		i++;
	}
	return (result);
}

unsigned int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (!is_valid_base(base) || str[i] == '\0')
		return (0);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign * convert_str_to_uint((str + i), base));
}
