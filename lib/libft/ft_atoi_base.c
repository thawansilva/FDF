/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:09 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/27 14:48:09 by thaperei         ###   ########.fr       */
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

static int	convert_str_to_int(char *str, char *base)
{
	int	i;
	int	base_length;
	int	value;
	int	result;

	base_length = ft_strlen(base);
	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		value = find_index_in_base(ft_toupper(str[i]), base);
		if (value == -1)
			break ;
		result = result * base_length + value;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;

	if (!is_valid_base(base) || *str == '\0')
		return (0);
	if (!ft_strncmp(str, "0x", 2))
		str += 2;
	result = convert_str_to_int((str), base);
	return (result);
}
