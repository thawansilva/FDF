/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:33:21 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/01 14:33:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_print_arg(char c, va_list args)
{
	unsigned int	len;

	len = 0;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), STDOUT);
		len++;
	}
	else if (c == '%')
		len += write(STDOUT, "%", 1);
	else if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unbr(va_arg(args, unsigned int));
	else if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), c);
	else
		len += ft_print_ptr(va_arg(args, t_ptr));
	return (len);
}

static void	ft_parse_format(const char *format, va_list args, unsigned int *len)
{
	unsigned int	index;

	index = 0;
	while (format[index])
	{
		if (format[index] == '%' && ft_strchr("cspdiuxX%", format[index + 1]))
		{
			*len += ft_print_arg(format[index + 1], args);
			index += 2;
		}
		else
		{
			ft_putchar_fd(format[index], STDOUT);
			*len += 1;
			index++;
		}
	}
}

unsigned int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	len;

	len = 0;
	va_start(args, format);
	ft_parse_format(format, args, &len);
	va_end(args);
	return (len);
}
