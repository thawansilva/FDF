/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:25:25 by thaperei          #+#    #+#             */
/*   Updated: 2025/07/18 11:25:25 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	start;
	int	i;
	int	count;

	if (!*s)
		return (0);
	i = 0;
	start = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && i != start)
		{
			count++;
			start = i + 1;
		}
		else if (s[i] == c && i == start)
			start = i + 1;
		i++;
	}
	if (i > start)
		count++;
	return (count);
}

static void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	ft_insert_str(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c && i != start)
		{
			arr[j] = ft_substr(s, start, i - start);
			if (!arr[j++])
				return (ft_free_arr(arr));
			start = i + 1;
		}
		else if (s[i] == c && i == start)
			start = i + 1;
		i++;
	}
	if (i > start)
		arr[j++] = ft_substr(s, start, i - start);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	ft_insert_str(arr, s, c);
	return (arr);
}
