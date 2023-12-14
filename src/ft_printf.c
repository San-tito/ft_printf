/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:35 by sguzman           #+#    #+#             */
/*   Updated: 2023/12/14 15:40:50 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int count)
{
	int	bytes_written;

	bytes_written = write(STDOUT, str, count);
	ft_free(1, &str);
	return (bytes_written);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	char	*str;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	str = ft_calloc(1, sizeof(char *));
	if (!str)
		return (-1);
	va_start(arg, format);
	ft_handle_format((char *)format, arg, &str, &count);
	va_end(arg);
	if (!str)
		return (-1);
	return (ft_putstr(str, count));
}
