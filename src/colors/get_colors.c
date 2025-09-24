/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:44:23 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/24 17:50:08 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	get_r(unsigned int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

static unsigned int	get_g(unsigned int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

static unsigned int	get_b(unsigned int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

static unsigned int	get_a(unsigned int rgba)
{
	return (rgba & 0xFF);
}

unsigned int	get_rgba(unsigned int rgba)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = get_r(rgba);
	g = get_g(rgba);
	b = get_b(rgba);
	a = get_a(rgba);
	return (r << 24 | g << 16 | b << 8 | a);
}
