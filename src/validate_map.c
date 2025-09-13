/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:36:16 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/13 16:36:16 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void validate_map(char **argv)
{
	int	 fd = open(*argv, O_RDONLY);
	if (fd < 0)
		error_msg(strerror(errno));
	close(fd);
}
